cmake_minimum_required(VERSION 3.14)
project(FetchContentExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Include the FetchContent module
include(FetchContent)

# 2. Declare the external JSON library
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        v3.11.3
)

# 3. Download the library at configure time
FetchContent_MakeAvailable(json)

# 4. Define your executable
add_executable(my_program main.cpp)

# 5. Link the JSON library
target_link_libraries(my_program PRIVATE nlohmann_json::nlohmann_json)