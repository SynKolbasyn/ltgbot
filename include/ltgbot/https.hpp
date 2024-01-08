#pragma once

#ifndef _HTTPS_HPP_
#define _HTTPS_HPP_


#include <string>
#include <chrono>


namespace sk {


class Https {
public:
  Https();
  ~Https();

  std::string get_updates(std::string url);

private:
  static size_t _curl_write_function(char* contents, size_t size, size_t nmemb, void* userdata);

  std::chrono::_V2::system_clock::time_point _prev_update_time;
};


} // namespace sk


#endif // _HTTPS_HPP_
