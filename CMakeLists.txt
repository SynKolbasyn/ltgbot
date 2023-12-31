cmake_minimum_required(VERSION 3.16.3)

set(PROJECT_NAME ltgbot)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(${PROJECT_NAME})

add_library(${PROJECT_NAME} src/ltgbot/ltgbot.hpp src/ltgbot.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC src/)
