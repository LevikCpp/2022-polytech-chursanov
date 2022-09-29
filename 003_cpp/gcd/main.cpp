#include <iostream>
#include <cassert>

//const char console_sumbol[2] {'>',' '};

int gcd(int a, int b) 
{

  if (a < 0) a *= -1;
  if (b < 0) b *= -1;

    while(a > 0 && b > 0)
    {
        if (a > b) {
            a %= b; 
        }
        else {
            b %= a;
        } 
    }
  
    if (a > 0) {
        return a;
     }
    else if (b > 0) {
        return b;
    }
    else {
        return 1;
    }
}

int main() 
{ // test block:

  assert(gcd(0, 5) == 5);
  assert(gcd(9, 0) == 9);
  assert(gcd(48, 64) == 16);
  assert(gcd(-64, 48) == 16);
  assert(gcd(30, 18) == 6);
  assert(gcd(-30, -18) == 6);
  assert(gcd(270, 192) == 6);

    
  return 0;
}
