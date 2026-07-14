cmake_minimum_required(VERSION 3.14) # FetchContent became stable in 3.14
project(FetchContentExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Include the FetchContent module
include(FetchContent)

# 2. Declare the external library you want to fetch
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        v3.11.3 # It's best practice to lock to a specific version/tag
)

# 3. Download and make the library available (Happens right now at CMake time!)
FetchContent_MakeAvailable(json)

# 4. Define your local executable
add_executable(my_program main.cpp)

# 5. Link against the fetched target (nlohmann_json::nlohmann_json)
target_link_libraries(my_program PRIVATE nlohmann_json::nlohmann_json)