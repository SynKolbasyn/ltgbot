#pragma once

#ifndef _CURL_EASY_INIT_EXCEPTION_HPP_
#define _CURL_EASY_INIT_EXCEPTION_HPP_


#include <string>

#include "ltgbot/exceptions/ltgbot_exception.hpp"


namespace sk {
namespace exceptions {


class Curl_easy_init_exception : public Ltgbot_exception {
public:
  Curl_easy_init_exception();
  Curl_easy_init_exception(std::string message);
  ~Curl_easy_init_exception();

  std::string what();

private:
  std::string _message;
};


} // namespace exceptions
} // namespace sk


#endif // _CURL_EASY_INIT_EXCEPTION_HPP_
