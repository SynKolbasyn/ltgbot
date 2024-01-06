# ltgbot
Open source linux telegram bot library

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

1. Linux distribution of the [Debian family](https://distrowatch.com/search.php?basedon=Debian&status=Active#distrosearch)

2. [git](https://git-scm.com/)
```Shell
sudo apt install git
```

3. [cmake](https://cmake.org/)
```Shell
sudo apt install cmake
```

4. [libcurl](https://curl.se/libcurl/)
```Shell
sudo apt install libcurl4-openssl-dev
```

5. [nlohmann json](https://github.com/nlohmann/json.git)
```Shell
sudo apt install nlohmann-json3-dev
```

6. Build tools
```Shell
sudo apt install build-essential
```

### Usage

Create a folder for your project
```Shell
mkdir ./project_name/
```

Navigate to the created folder
```Shell
cd ./project_name/
```

Clone the library repository to your project
```Shell
git clone https://github.com/SynKolbasyn/ltgbot.git libs/ltgbot/
```

Create a file src/main.cpp and write the following program in it
```C++
#include <ltgbot/ltgbot.hpp>

sk::Bot bot("BOT_TOKEN");

void callback(sk::types::Message message);

int main() {
  bot.set_callback(callback);
  bot.start();
  return 0;
}

void callback(sk::types::Message message) {
  bot.send(message.user.get_id(), message.get_text());
}

```

Create a file in the root of the project CMakeLists.txt and fill it in with the following lines
```CMake
cmake_minimum_required(VERSION 3.16.3)

set(PROJECT_NAME project_name)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(libs/ltgbot/)
target_link_libraries(${PROJECT_NAME} ltgbot)
```

Configure
```Shell
# Debug
cmake -S ./ -B ./build/Debug/ -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug

# Release
cmake -S ./ -B ./build/Release/ -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Release
```

Build
```Shell
# Debug
cmake --build ./build/Debug/ --config Debug

# Release
cmake --build ./build/Release/ --config Release
```

Run
```Shell
# Debug
./build/Debug/project_name

# Release
./build/Release/project_name
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

## License

[GPLv3](https://www.gnu.org/licenses/gpl-3.0-standalone.html)
