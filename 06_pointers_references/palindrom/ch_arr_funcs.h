#include <iostream>

unsigned int length(const char *str)
{
  if (!str) // - проверка на NULL
    return 0;

  const char *end_pos = str;

  while (*end_pos != '\0')
    *end_pos++;

  // std::cout << end_pos - str << std::endl;
  return end_pos - str;
}

unsigned int ch_quantity(const char *str, const char ch)
{
  unsigned int quantity = 0;

  for (int i = 0; i < length(str); i++)
  {
    if (str[i] == ch)
      quantity++;
  }

  std::cout << quantity << std::endl;
  return quantity;
}

const char *ch_del(const char *str, const char ch = ' ')
{
  unsigned int del_quantity = length(str) - ch_quantity(str, ch);
  char *new_str = new char[del_quantity];

  for (int i = 0; i < length(str); i++) // problem here, ignore cycle
  {
    if (str[i] != ch)
      new_str[i] == str[i];
  }

  return new_str;
}

void ch_out(const char *str)
{
  for (auto i = 0; i < length(str); i++)
  {
    std::cout << i << ". " << str[i] << "\n";
  }
}

void str_out(const char *str)
{
  std::cout << "full string: ";

  for (auto i = 0; i < length(str); i++)
  {
    std::cout << str[i];
  }
}