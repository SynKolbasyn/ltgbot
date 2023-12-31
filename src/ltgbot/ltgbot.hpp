#pragma once

#ifndef _LTGBOT_HPP_
#define _LTGBOT_HPP_


#include <string>

#include <ltgbot/types/message.hpp>


namespace sk {


class Bot {
public:
  Bot(const std::string token);
  ~Bot();
  void set_callback(void (*callback)(types::Message message));
  void start();

private:
  std::string _token;
  void (*_callback)(types::Message message);
};


} // namespace sk


#endif // _LTGBOT_HPP_
