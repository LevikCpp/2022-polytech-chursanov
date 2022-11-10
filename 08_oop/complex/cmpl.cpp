#include <iostream>
#include <cassert>
#include "custom_complex.h"

int main()
{
    custom_complex<int> c0(2,-4);
    custom_complex<int> c1(2,-4);
    custom_complex<int> c2(1,-1);
    custom_complex<double> c3(2.0, -5.0);
    custom_complex<double> c4(2.0, -5.0);

    assert(c0 == c1);
    assert(c0 == c2);
    assert(c1 + c2 == custom_complex(3, -5));
    assert(c3 == c4);


    return 0;
}