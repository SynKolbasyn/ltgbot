#pragma once

#ifndef _MESSAGE_HPP_
#define _MESSAGE_HPP_


#include <nlohmann/json.hpp>

#include "ltgbot/types/simple_types.hpp"
#include "ltgbot/types/user.hpp"
#include "ltgbot/types/chat.hpp"


namespace sk {
namespace types {


class Message {
public:
  Message();
  Message(nlohmann::json message);
  ~Message();
  i64 get_message_id();
  User get_from();
  Chat get_chat();
  i64 get_date();
  std::string get_text();

private:
  i64 _message_id;
  User _from;
  Chat _chat;
  i64 _date;
  std::string _text;

  template <typename T> T _parse(nlohmann::json json, std::string key, T default_value);
};


} // namespace types
} // namespace sk


#endif // _MESSAGE_HPP_
