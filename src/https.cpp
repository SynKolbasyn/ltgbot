#include "ltgbot/https.hpp"

#include <string>
#include <chrono>

#include <curl/curl.h>

#include "ltgbot/exceptions.hpp"


namespace sk {


Https::Https() {
  curl_global_init(CURL_GLOBAL_DEFAULT);
  _prev_update_time = std::chrono::high_resolution_clock::now();
}

Https::~Https() {
  curl_global_cleanup();
}


std::string Https::get_updates(std::string url) {
  std::string curl_write_buffer;

  CURL* curl = curl_easy_init();
  if (!curl) throw exceptions::Curl_easy_init_exception();

  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curl_write_buffer);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, _curl_write_function);
  curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5);
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  
  while ((std::chrono::high_resolution_clock::now() - _prev_update_time).count() <= 1000000000);
  CURLcode res = curl_easy_perform(curl);
  _prev_update_time = std::chrono::high_resolution_clock::now();
  curl_easy_cleanup(curl);

  if (res != CURLE_OK) {
    if ((res == CURLE_OPERATION_TIMEDOUT) || (res == CURLE_COULDNT_CONNECT)) return "";
    throw exceptions::Curl_easy_perform_exception("[ ERROR ] -> curl_easy_perform: " + std::string(curl_easy_strerror(res)));
  }

  return curl_write_buffer;
}


size_t Https::_curl_write_function(char* contents, size_t size, size_t nmemb, void* userdata) {
  size_t realsize = size * nmemb;
  ((std::string*)userdata)->append((char*)contents, realsize);
  return realsize;
}


} // namespace sk
