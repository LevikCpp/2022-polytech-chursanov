#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "hash_table.h"
#include <doctest.h>
#include <string>

TEST_CASE("whatever") {

  HashTable<std::string> d1;
  d1.insert("first", "hi");
  d1.insert("secnd", "ih");

  CHECK_EQ(d1.size(), 2);
  CHECK_EQ(d1.get("first"), "hi");
}