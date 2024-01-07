#include "ltgbot/types/message.hpp"

#include <nlohmann/json.hpp>

#include "ltgbot/types/simple_types.hpp"
#include "ltgbot/types/user.hpp"
#include "ltgbot/types/chat.hpp"


namespace sk {
namespace types {


Message::Message() {
  
}


Message::Message(nlohmann::json message) {
  _message_id = _parse<i64>(message, "message_id", 0);
  _from = User(message["from"]);
  _chat = Chat(message["chat"]);
  _date = _parse<i64>(message, "date", 0);
  _text = _parse<std::string>(message, "text", "");
}


Message::~Message() {

}


i64 Message::get_message_id() {
  return _message_id;
}


User Message::get_from() {
  return _from;
}


Chat Message::get_chat() {
  return _chat;
}


i64 Message::get_date() {
  return _date;
}


std::string Message::get_text() {
  return _text;
}


template <typename T> T Message::_parse(nlohmann::json json, std::string key, T default_value) {
  if (json.contains(key)) return json[key.c_str()].get<T>();
  return default_value;
}


} // namespace types
} // namespace sk
