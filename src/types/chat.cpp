#include "ltgbot/types/chat.hpp"

#include <string>

#include <nlohmann/json.hpp>

#include "ltgbot/types/simple_types.hpp"


namespace sk {
namespace types {


Chat::Chat() {

}


Chat::Chat(nlohmann::json chat) {
  _id = chat["id"];
  _type = chat["type"];
}


Chat::~Chat() {

}


i64 Chat::get_id() {
  return _id;
}


std::string Chat::get_type() {
  return _type;
}


} // namespace types
} // namespace sk
