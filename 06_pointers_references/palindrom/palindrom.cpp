#include <cassert>

unsigned int length(const char* str)
{   
    if (!str) // - проверка на NULL
      return 0;
      
    const char* end_pos = str;
      
    while (*end_pos != '\0')
      *end_pos++;
    
    return end_pos - str;
}

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

  return 0;
}