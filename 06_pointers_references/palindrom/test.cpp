#include "ch_arr_funcs.h"
#include <cassert>


bool is_palindrom(const char* str)
{
  if (!str)
    return false;

  for (auto i = 0; i < length(str) / 2; i++)
  {
    if (str[i] != str[length(str) - 1 - i])
      return false;
  }

  return true;
}

int main()
{
  assert(is_palindrom("tenet"));
  
  if(is_palindrom(ch_del("tenet", ' ')))
    str_out(ch_del("tenet", ' '));


  if(is_palindrom(ch_del("taco cat", ' ')))
    str_out(ch_del("taco cat", ' '));
  assert(is_palindrom(ch_del("taco cat", ' ')));

  return 0;
}