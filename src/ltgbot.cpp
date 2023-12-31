#include <ltgbot/ltgbot.hpp>


namespace sk {


Bot::Bot(const std::string token) {
  _token = token;
}


Bot::~Bot() {

}


void Bot::set_callback(void (*callback)(types::Message message)) {
  _callback = callback;
}


void Bot::start() {
  while (true) {
    types::Message message;
    _callback(message);
  }
  
}


} // namespace sk
