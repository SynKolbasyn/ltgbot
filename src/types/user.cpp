#include "ltgbot/types/user.hpp"

#include <string>

#include <nlohmann/json.hpp>

#include "ltgbot/types/simple_types.hpp"


namespace sk {
namespace types {


User::User() {
  
}


User::User(nlohmann::json user) {
  _id = user["id"];
  _is_bot = user["is_bot"];
  _first_name = user["first_name"];
}


User::~User() {

}


i64 User::get_id() {
  return _id;
}


bool User::get_is_bot() {
  return _is_bot;
}


std::string User::get_first_name() {
  return _first_name;
}


} // namespace types
} // namespace sk
