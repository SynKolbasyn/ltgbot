#include <nlohmann/json.hpp>

#include "ltgbot/types/update.hpp"
#include "ltgbot/types/types.hpp"


namespace sk {
namespace types {


Update::Update(nlohmann::json response) {
  _update_id = response["update_id"];
  _message = Message(response["message"]);
}


Update::~Update() {

}


i64 Update::get_update_id() {
  return _update_id;
}


Message Update::get_message() {
  return _message;
}


} // namespace types
} // namespace sk
