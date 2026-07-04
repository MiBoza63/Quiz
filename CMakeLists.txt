CMake_Minimum_Required(VERSION 3.10)
Project(Calculator)


Add_Subdirectory(libs)
Add_Executable(Main PRIVATE calculator)
