#include <cassert>

unsigned int length(const char* str)
{   
    if (!str) // - проверка на NULL
      return 0;
      
    const char *end_pos = str;
      
    while (*end_pos != '\0')
      *end_pos++;
    
    return end_pos - str;
}

int main()
{
    assert(length("a") == 1);
    assert(length("ab") == 2);
    assert(length("") == 0);
    assert(length("hello world") == 11);
    assert(length(nullptr) == 0);
    
    return 0;
}
