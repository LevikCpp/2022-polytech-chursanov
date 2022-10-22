unsigned int length(const char* str)
{   
    if (!str) // - проверка на NULL
      return 0;
      
    const char *end_pos = str;
      
    while (*end_pos != '\0')
      *end_pos++;
    
    return end_pos - str;
}


