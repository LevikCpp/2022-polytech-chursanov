// Only for Windows
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

#define DIV (1024 * 1024)

enum ARGS { percent, absolute };

std::string operator*(std::string &str, int times) {

  std::stringstream stream;

  for (size_t i = 0; i < times; i++) {
    stream << str;
  }

  return stream.str();
}

unsigned long memoryCheck(ARGS arg) {

  MEMORYSTATUSEX statex;
  statex.dwLength = sizeof(statex);

  GlobalMemoryStatusEx(&statex);

  if (arg == percent)
    return statex.dwMemoryLoad;
  if (arg == absolute)
    return statex.ullTotalPhys / DIV;

  return 0;
}

void printer(unsigned long percent, unsigned long absolute) {

  std::string palka = "|";
  std::string tochka = ".";

  std::cout << palka * (percent / 5) + tochka * (20 - percent / 5) << " "
            << percent << " %" << std::endl;

  std::cout << "Used " << absolute * (percent / 100.0) << " from " << absolute
            << " " << std::endl;
}

int main() {

  printer(memoryCheck(ARGS::percent), memoryCheck(ARGS::absolute));

  return 0;
}