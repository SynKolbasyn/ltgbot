#include <nlohmann/json.hpp>

#include "ltgbot/types/message.hpp"
#include "ltgbot/types/types.hpp"
#include "ltgbot/types/user.hpp"
#include "ltgbot/types/chat.hpp"


namespace sk {
namespace types {


Message::Message() {
  
}


Message::Message(nlohmann::json message) {
  _message_id = message["message_id"];
  _from = User(message["from"]);
  _chat = Chat(message["chat"]);
  _date = message["date"];
  _text = message["text"];
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


} // namespace types
} // namespace sk
