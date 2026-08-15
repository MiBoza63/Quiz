cmake_minimum_required(VERSION 3.14)
project(gtest_demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(my_tests test_main.cpp)
target_link_libraries(my_tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(my_tests)