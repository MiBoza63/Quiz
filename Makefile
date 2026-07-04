CXX := g++
Include := -I include `pkg-config --cflags --libs gtkmm-4.0`
Debug_Flags := -std=c++20 -w -fmax-errors=6 -g

Source := Main.o Window.o Questions.o
Debug_Objects := $(addprefix debug/, $(Source))

$(Debug_Objects): debug/%.o : src/%.cpp
	$(CXX) $(Debug_Flags) -c $^ $(Include) -o $@
Quiz: $(Debug_Objects)
	$(CXX) $(Debug_Flags) $^ $(Include) -o $@
Fuck_This: src/Fuck_This.cpp
run_debug: Quiz
	./$^
clear:
	clear
