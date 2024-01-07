#pragma once

#ifndef _USER_HPP_
#define _USER_HPP_


#include <string>

#include <nlohmann/json.hpp>

#include "ltgbot/types/simple_types.hpp"


namespace sk {
namespace types {


class User {
public:
  User();
  User(nlohmann::json user);
  ~User();
  i64 get_id();
  bool get_is_bot();
  std::string get_first_name();

private:
  i64 _id;
  bool _is_bot;
  std::string _first_name;
};


} // namespace types
} // namespace sk


#endif // _USER_HPP_
