#ifndef Questions_hpp
#define Questions_hpp

#include <string>

struct Question{
    ushort a, b;
    int answer;
    ushort max;

    bool Check(ushort guess);
    Question(ushort p_max);
    void Make_New();
    std::string Get_String();
};

int Read_Score();
void Save_Score(int score);

#endif // Questions_hpp
