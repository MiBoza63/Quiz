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

add_executable(Examples)
target_sources(Examples
    PRIVATE
        Source/Equations.cpp
        Source/Fraction.cpp
        Source/Main.cpp
        Source/Polynomial.cpp
        Source/Vector2.cpp
        Source/Vector3.cpp
)
target_include_directories(Examples PRIVATE Include)
target_link_libraries(Examples GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(Examples)
