#pragma once

#ifndef _TELEGRAM_EXCEPTION_HPP
#define _TELEGRAM_EXCEPTION_HPP


#include <string>

#include "ltgbot/exceptions/ltgbot_exception.hpp"


namespace sk {
namespace exceptions {


class Telegram_exception : public Ltgbot_exception {
public:
  Telegram_exception();
  Telegram_exception(std::string message);
  ~Telegram_exception();

  std::string what();

private:
  std::string _message;
};


} // namespace exceptions
} // namespace sk


#endif // _TELEGRAM_EXCEPTION_HPP
