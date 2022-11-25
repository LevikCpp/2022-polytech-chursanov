#include "json.h"
#include <fstream>
#include <string>
#include <unordered_map>

int main() {

  std::unordered_map<std::string, BasicToken> a = {
      {"int_token", NumToken<int>(9090)},
      {"str_token", StringToken("hi")},
      {"bool_token", BoolToken(true)},
      {"array_token", ArrayToken({NumToken<float>(2.0f), StringToken("ok")})}};

  std::unordered_map<std::string, BasicToken> big = {
      {"struct_token", ObjectToken(a)}, {"int_token", NumToken<double>(14.44)}};

  Json _json(big);
  std::cout << _json.serialize();

  std::fstream file;
  file.open("folder/out_test.json", std::ios::out);

  file << _json.serialize();
  file.close();

  return 0;
}