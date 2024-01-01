#pragma once

#ifndef _UPDATE_HPP_
#define _UPDATE_HPP_


#include <nlohmann/json.hpp>

#include "types.hpp"
#include "message.hpp"


namespace sk {
namespace types {


class Update {
public:
  Update(nlohmann::json response);
  ~Update();
  i64 get_update_id();
  Message get_message();

private:
  i64 _update_id;
  Message _message;
};


} // namespace types
} // namespace sk


#endif // _UPDATE_HPP_
