#include "ltgbot/exceptions/telegram/telegram_exception.hpp"


namespace sk {
namespace exceptions {


Telegram_exception::Telegram_exception() {
  _message = "[ ER ] -> telegram exception";
}


Telegram_exception::Telegram_exception(std::string message = "[ ER ] -> telegram exception") {
  _message = message;
}


Telegram_exception::~Telegram_exception() {

}


std::string Telegram_exception::what() {
  return _message;
}


} // namespace exceptions
} // namespace sk
