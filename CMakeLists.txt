cmake_minimum_required(VERSION 3.14)
project(FetchContentExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        v3.11.3 
)

FetchContent_MakeAvailable(json)

add_executable(my_program main.cpp)

# Link against the fetched target
target_link_libraries(my_program PRIVATE nlohmann_json::nlohmann_json)

# --- ADD THIS NEW PART ---
# Pass the environment variable from the terminal/GitHub Action straight into C++
if(DEFINED ENV{ENV_TYPE})
    target_compile_definitions(my_program PRIVATE APP_ENV="$ENV{ENV_TYPE}")
else()
    target_compile_definitions(my_program PRIVATE APP_ENV="dev")
endif()