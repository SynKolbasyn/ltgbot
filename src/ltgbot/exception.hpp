#pragma once

#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_


#include <string>
#include <exception>


namespace sk {
namespace exception {


class Ltgbot_exception : public std::exception {
public:
  Ltgbot_exception(const std::string message);
  std::string what();

private:
  std::string _message;
};


} // namespace exception
} // namespace sk


#endif // _EXCEPTION_HPP_
