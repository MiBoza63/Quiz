#include "Questions.hpp"
#include <stdlib.h>
#include <time.h>
using std::to_string;

#define SHORT_MAX 1<<16 -1

Question::Question(ushort p_max = SHORT_MAX):
    max(p_max){
    srand(time(0));
    Make_New();
}

bool Question::Check(ushort guess){
    return guess == answer;
}

void Question::Make_New(){
    int random_number = rand();
    a = random_number % max;
    b = (random_number >> 16) % max;

    answer = a + b;
}

string Question::Get_String(){
    string result   = to_string(a);
    result += " + " + to_string(b);
    result += " = ";

    return result;
}
