#include "ltgbot/ltgbot.hpp"

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <chrono>

#include <curl/curl.h>
#include <nlohmann/json.hpp>

#include "ltgbot/types/types.hpp"
#include "ltgbot/exceptions.hpp"
#include "ltgbot/https.hpp"


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
    std::vector<types::Update> updates;
    while (updates.empty()) updates = _get_updates(offset);

    for (types::Update update : updates) {
      offset = std::max(offset, update.get_update_id() + 1);
      types::Message message = update.get_message();
      _callback(message);
    }
  }
}


types::i64 Bot::_skip_old_messages() {
  types::i64 offset = 0;
  std::vector<types::Update> updates;
  
  // TODO: FIX BUG WHEN NO OLD MESSAGES AND TELEGRAM RESPONSE '{"ok": true, "result": []}'
  while (updates.empty()) updates = _get_updates(offset);
  
  // offset = updates.back().get_update_id();
  for (types::Update update : updates) offset = std::max(offset, update.get_update_id() + 1);
  return offset;
}


std::vector<types::Update> Bot::_get_updates(types::i64 offset) {
  std::string telegram_response = _https.get_updates("https://api.telegram.org/bot" + _token + "/getUpdates?offset=" + std::to_string(offset) + "&timeout=3");
  // std::cout << "telegram_response: " << telegram_response << std::endl;
  if (telegram_response.empty()) return std::vector<types::Update>();

  nlohmann::json response = nlohmann::json::parse(telegram_response);
  if (!response["ok"]) throw exceptions::Telegram_exception("[ ERROR ] -> response not ok");

  std::vector<types::Update> updates;
  for (nlohmann::json update : response["result"]) {
    updates.push_back(types::Update(update));
  }

  return updates;
}


} // namespace sk
