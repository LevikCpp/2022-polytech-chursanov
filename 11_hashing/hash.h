#pragma once
#include <string>

namespace hf {
unsigned A = 13441;
unsigned B = 93937;
unsigned C = 28309;
} // namespace hf

using namespace hf;
unsigned default_hash(const std::string &str) {
  unsigned resault = C;
  for (unsigned i = 0; i != static_cast<unsigned>(str.size()); i++) {
    resault = (resault * A) ^ (str[i] * B);
  }
  return resault;
}
