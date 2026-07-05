CMake_Minimum_Required(VERSION 3.10)
Project(Calculator)

Add_Subdirectory(libs)
Add_Executable(Main)
Target_Sources(Main PRIVATE app/Main.cpp)
Target_Link_Libraries(Main PRIVATE Calculator)
