#ifndef Questions_hpp
#define Questions_hpp

#include <string>
using std::string;

struct Question{
    ushort a, b;
    int answer;
    ushort max;

    Question(ushort p_max);
    void Make_New();
    string Get_String();
};

#endif // Questions_hpp
