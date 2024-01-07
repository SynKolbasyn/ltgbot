#include "ltgbot/exceptions/https/curl_easy_perform_exception.hpp"

#include <string>


namespace sk {
namespace exceptions {


Curl_easy_perform_exception::Curl_easy_perform_exception() {
  _message = "[ ER ] -> curl_easy_perform";
}


Curl_easy_perform_exception::Curl_easy_perform_exception(std::string message = "[ ER ] -> curl_easy_perform") {
  _message = message;
}


Curl_easy_perform_exception::~Curl_easy_perform_exception() {

}


std::string Curl_easy_perform_exception::what() {
  return _message;
}


} // namespace exceptions
} // namespace sk
