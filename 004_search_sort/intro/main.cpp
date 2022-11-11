#include "linear.h"
#include "binary.h"
#include <iostream>

int main()
{
    const int sequence[] = {
        -996, -960, -944, -887, -865, -860, -846, -831, -790, -785, -700, -691,
        -662, -662, -647, -640, -587, -532, -524, -519, -501, -497, -475, -471,
        -461, -457, -452, -442, -441, -416, -412, -411, -390, -389, -358, -341,
        -306, -257, -253, -252, -248, -208, -143, -134, -82,  -79,  -11,  21,
        26,   48,   68,   69,   72,   93,   95,   99,   115,  120,  156,  164,
        181,  200,  231,  252,  288,  304,  336,  343,  364,  402,  419,  486,
        546,  584,  595,  596,  606,  627,  636,  666,  666,  683,  701,  740,
        766,  780,  782,  794,  802,  829,  832,  837,  858,  875,  881,  882,
        883,  883,  947,  959};

    const int len = sizeof(sequence) / sizeof(sequence[0]);

    char input {' '};
    
    int what_find = 120;

    std::cout << "b/l" << " > ";
    std::cin >> input;

    if (input == 'b')
    {
        std::cout << binary_search(sequence, what_find, len, 0); // 57
    }
    else if (input == 'l')
    {
        std::cout << linear_search(sequence, what_find, len);
    }
    else
    {   
        std::cout << "Error";
    }

    return 0;
}