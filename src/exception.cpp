#include <string>

#include <ltgbot/exception.hpp>


namespace sk {
namespace exception {


Ltgbot_exception::Ltgbot_exception(const std::string message) {
  _message = message;
}


std::string Ltgbot_exception::what() {
  return _message;
}


} // namespace exception
} // namespace sk
