#pragma once

#ifndef _LTGBOT_HPP_
#define _LTGBOT_HPP_


#include <string>
#include <vector>
#include <chrono>

#include <curl/curl.h>
#include <nlohmann/json.hpp>

#include "ltgbot/types/types.hpp"


namespace sk {


class Bot {
public:
  Bot(const std::string token);
  ~Bot();
  void set_callback(void (*callback)(types::Message message));
  void start();

private:
  std::string _token;
  std::chrono::_V2::system_clock::time_point _prev_update_time;

  void (*_callback)(types::Message message);
  types::i64 _skip_old_messages();
  std::vector<types::Update> _get_updates(types::i64 offset);
};


} // namespace sk


#endif // _LTGBOT_HPP_
