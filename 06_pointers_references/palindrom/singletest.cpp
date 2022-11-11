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
    unsigned int num = length(str);

    for (int i = 0; i < num; i++)
    {
        if (str[i] == ch)
            quantity++;
    }

    // std::cout << quantity << std::endl;
    return quantity;
}

void func(const char *str, const char ch = ' ')
{
    unsigned int num = length(str);
    unsigned int del_quantity = num - ch_quantity(str, ch);
    char *new_str = new char[del_quantity];

    for (auto i = 0, j = 0; i < num; i++) // need rework
    {
        if (str[i + j] == ' ')
        {
            new_str[i] = str[i + j + 1];
            j++;
        }
        else
            new_str[i] = str[i + j];
    }

    for (auto i = 0; i < 7; i++)
    {
        std::cout << new_str[i] << std::endl;
    }

    delete new_str;
}

int main()
{
    func("II pp ww");

    return 0;
}