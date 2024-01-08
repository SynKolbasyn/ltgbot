cmake_minimum_required(VERSION 3.16.3)

set(PROJECT_NAME ltgbot)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(${PROJECT_NAME})

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "include/*.hpp" "src/*.cpp")
add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME} curl)
target_include_directories(${PROJECT_NAME} PUBLIC include/)
