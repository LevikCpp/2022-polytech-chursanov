#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct BasicToken {
  std::string value;
};

struct StringToken : BasicToken {
  StringToken(std::string str = "") { value = '"' + str + '"'; }
};

template <typename NUMTYPE> struct NumToken : BasicToken {
  NumToken(NUMTYPE num = 0) { value = '"' + std::to_string(num) + '"'; }
};

struct BoolToken : BasicToken {
  BoolToken(bool boolean) {
    if (boolean) {
      value = "true";
    } else {
      value = "false";
    }
  }
};

struct ArrayToken : BasicToken {
  ArrayToken(std::vector<BasicToken> array) {
    value.append("[");
    for (auto i = 0; i < array.capacity(); i++) {
      value.append(array[i].value);
      if (i != array.capacity() - 1) {
        value.append(",");
      }
    }
    value.append("]");
  }
};

struct ObjectToken : BasicToken {
  ObjectToken(std::unordered_map<std::string, BasicToken> object) {
    this->value.append("{");
    for (std::size_t i = 1; const auto &elem : object) {
      value.append("\"" + elem.first + "\":" + elem.second.value);
      if (i != object.size()) {
        this->value.append(",");
        i++;
      }
    }
    this->value.append("}");
  }
};

struct Json {
  std::unordered_map<std::string, BasicToken>
      tokens; // <название параметра, значение>

  Json(std::unordered_map<std::string, BasicToken> map) { tokens = map; }

  std::string serialize() const {
    std::string out;
    out.append("{");
    for (std::size_t i = 1; const auto &elem : tokens) {
      // map {<key, value>, <key1, value1>, ...}
      out.append("\"" + elem.first + "\":" + elem.second.value);
      // { "КЛЮЧ": "ЗНАЧЕНИЕ", ...}
      if (i != tokens.size()) {
        out.append(",");
        i++;
      }
    }
    out.append("}");
    return out;
  }
};