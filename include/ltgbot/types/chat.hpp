#pragma once

#ifndef _CHAT_HPP_
#define _CHAT_HPP_


#include <string>

#include <nlohmann/json.hpp>

#include "ltgbot/types/simple_types.hpp"


namespace sk {
namespace types {


class Chat {
public:
  Chat();
  Chat(nlohmann::json chat);
  ~Chat();
  i64 get_id();
  std::string get_type();

private:
  i64 _id;
  std::string _type;
};


} // namespace types
} // namespace sk


#endif // _CHAT_HPP_
