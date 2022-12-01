#include <iostream>
#include <string>
#include <vector>

double bitpow(double d, int n) {
  if (n < 0) {
    d = 1 / d;
    n *= -1;
  }
  double result = 1;
  while (n) {
    if (n & 1) {
      result *= d;
    }
    d *= d;
    n >>= 1;
  }
  return result;
}

double calc(char op, double d0, double d1) {
  switch (op) {
  case '+':
    return d0 + d1;
  case '-':
    return d0 - d1;
  case '*':
    return d0 * d1;
  case '/':
    return d0 / d1;
  case '^':
    return bitpow(d0, static_cast<int>(d1));
  default:
    return 0.0;
  }
}

std::vector<std::string> convertor(std::string input) {
  std::vector<std::string> tokens;
  std::string token;
  for (int i = 0; i < input.size(); ++i) {
    if (input[i] == ' ') {
      tokens.push_back(token);
      token = "";
    } else {
      token += input[i];
    }
  }
  tokens.push_back(token);
  return tokens;
}

int main() {

  char ch;
  double v0 = 0, v1 = 0;

  std::string iv0, iv1, iop;

  std::cout << "------Verry simple calculatorn------\n";
  std::cout << "input form: 'value' 'operator' 'value'\n";

  while (true) {
    std::cout << ">";
    std::string input;
    getline(std::cin, input);
    std::vector<std::string> tokens = convertor(input);
    if (tokens[1].size() > 1) {
      std::cout << "input error, try again\n";
    } else {
      std::cout << calc(*tokens[1].c_str(), std::stod(tokens[0]),
                        std::stod(tokens[2]))
                << "\n";
    }
  }
  return 0;
}
