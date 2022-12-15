#include "hash.h"
#include <iostream>
#include <string>

int main() {

  int key;
  std::string str;

  while (str != "stop") {
    std::cout << "Enter the str: ";
    std::getline(std::cin, str);
    // std::cin >> str;
    std::cout << "Hash is " << default_hash(str) << ";" << std::endl;
  }
  return 0;
}