Add_Library(Calculator Calculator.cpp)
Target_Sources(Calculator PRIVATE Calculator.cpp)
Target_Include_Directories(Calculator INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

message(${CMAKE_CURRENT_SOURCE_DIR})
