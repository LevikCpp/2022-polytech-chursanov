#include "hash.h"
#include <iostream>

int main() {

  int key;
  std::string str;

  while (str != "stop") {
    std::cout << "Enter the str: ";
    std::cin >> str;
    std::cout << "Hash is " << default_hash(str) << ";" << std::endl;
  }
  return 0;
}