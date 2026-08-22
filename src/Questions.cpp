#include "Questions.hpp"
#include <fstream>
#include <filesystem>
#include <time.h>
using std::ios;
using std::string;
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

int Read_Score(){
    short score;
    const char file_path[] = "include/Score.bin";
    if(!std::filesystem::exists(file_path))
        score = 0;
    else{
        std::ifstream input(file_path, ios::binary);
        input.read((char*) &score, 2);
        input.close();
    }

    return score;
}

void Save_Score(int score){
    std::ofstream output("include/Score.bin", ios::binary);
    output.write((char*) &score, 2);
    output.close();
}
