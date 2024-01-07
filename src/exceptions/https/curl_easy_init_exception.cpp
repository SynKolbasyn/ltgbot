#include "ltgbot/exceptions/https/curl_easy_init_exception.hpp"

#include <string>


namespace sk {
namespace exceptions {


Curl_easy_init_exception::Curl_easy_init_exception() {
  _message = "[ ER ] -> curl_easy_init";
}


Curl_easy_init_exception::Curl_easy_init_exception(std::string message = "[ ER ] -> curl_easy_init") {
  _message = message;
}


Curl_easy_init_exception::~Curl_easy_init_exception() {

}


std::string Curl_easy_init_exception::what() {
  return _message;
}


} // namespace exceptions
} // namespace sk
