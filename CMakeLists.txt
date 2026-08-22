CMake_Minimum_Required(VERSION 3.20)
Project(Quiz)
Add_Executable(${PROJECT_NAME})

Find_Package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

Target_Include_Directories(${PROJECT_NAME}
	PRIVATE
		include
		${GTKMM_INCLUDE_DIRS}
)
Target_Compile_Options(${PROJECT_NAME} PRIVATE ${GTKMM_CFLAGS_OTHER})
Target_Link_Directories(${PROJECT_NAME} PRIVATE ${GTKMM_LIBRARY_DIRS})
Target_Link_Libraries(${PROJECT_NAME} PRIVATE ${GTKMM_LIBRARIES})
Target_Sources(${PROJECT_NAME}
	PRIVATE
		src/Main.cpp
		src/Questions.cpp
		src/Window.cpp
)
