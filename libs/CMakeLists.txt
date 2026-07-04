add_library(calculator calculator.cpp)
Target_Include_Directories(calculator
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
)
