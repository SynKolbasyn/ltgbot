#include <string>
#include <vector>

#include <curl/curl.h>
#include <nlohmann/json.hpp>

#include "ltgbot/ltgbot.hpp"
#include "ltgbot/types/message.hpp"
#include "ltgbot/types/types.hpp"
#include "ltgbot/types/update.hpp"
#include "ltgbot/exception.hpp"


namespace sk {


Bot::Bot(const std::string token) {
  _token = token;
}


Bot::~Bot() {

}


void Bot::set_callback(void (*callback)(types::Message message)) {
  _callback = callback;
}


void Bot::start() {
  types::i64 offset = _skip_old_messages();
  while (true) {
    std::vector<types::Update> updates = _get_updates(offset);
    if (updates.empty()) continue;
    offset = updates.back().get_update_id();

    for (types::Update update : updates) {
      types::Message message = update.get_message();
      _callback(message);
    }
  }
}


size_t Bot::_curl_write_function(char* contents, size_t size, size_t nmemb, void* userdata) {
  size_t realsize = size * nmemb;
  ((std::string*)userdata)->clear();
  ((std::string*)userdata)->append((char*)contents, realsize);
  return realsize;
}


types::i64 Bot::_skip_old_messages() {
  types::i64 prev_offset = 0;
  types::i64 offset = prev_offset + 1;
  while (prev_offset != offset) {
    prev_offset = offset;
    std::vector<types::Update> updates = _get_updates(prev_offset);
    if (updates.empty()) continue;
    offset = updates.back().get_update_id();
  }
  return offset;
}


std::vector<types::Update> Bot::_get_updates(types::i64 offset) {
  curl_global_init(CURL_GLOBAL_DEFAULT);
  CURL* curl = curl_easy_init();
  if (!curl) throw exception::Ltgbot_exception("[ ERROR ] -> curl_easy_init");
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &_curl_write_buffer);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, _curl_write_function);
  curl_easy_setopt(curl, CURLOPT_TIMEOUT, 15);
  curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 2);
  curl_easy_setopt(curl, CURLOPT_URL, ("https://api.telegram.org/bot" + _token + "/getUpdates").c_str());
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, ("offset=" + std::to_string(offset) + "&timeout=10").c_str());
  
  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    if (res == CURLE_OPERATION_TIMEDOUT) {
      curl_easy_cleanup(curl);
      curl_global_cleanup();
      return std::vector<types::Update>();
    }
    throw exception::Ltgbot_exception("[ ERROR ] -> curl_easy_perform: " + std::string(curl_easy_strerror(res)));
  }
  
  nlohmann::json response(_curl_write_buffer);
  if (!response["ok"]) throw exception::Ltgbot_exception("[ ERROR ] -> response not ok");

  std::vector<types::Update> updates;
  for (nlohmann::json update : response["result"]) {
    updates.push_back(types::Update(update));
  }

  curl_easy_cleanup(curl);
  curl_global_cleanup();
  return updates;
}


} // namespace sk
