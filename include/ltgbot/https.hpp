#pragma once

#ifndef _HTTPS_HPP_
#define _HTTPS_HPP_


#include <string>


namespace sk {


class Https {
public:
  Https();
  ~Https();
  std::string make_request(std::string url);

private:
  static size_t _curl_write_function(char* contents, size_t size, size_t nmemb, void* userdata);
};


} // namespace sk


#endif
