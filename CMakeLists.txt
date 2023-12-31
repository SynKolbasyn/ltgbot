cmake_minimum_required(VERSION 3.16.3)

set(PROJECT_NAME ltgbot)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC
  src/ltgbot/ltgbot.hpp src/ltgbot.cpp
  src/ltgbot/exception.hpp src/exception.cpp
  src/ltgbot/types/types.hpp
  src/ltgbot/types/chat.hpp src/chat.cpp
  src/ltgbot/types/message.hpp src/message.cpp
  src/ltgbot/types/user.hpp src/user.cpp
)
target_link_libraries(${PROJECT_NAME} curl)
target_include_directories(${PROJECT_NAME} PUBLIC src/)
