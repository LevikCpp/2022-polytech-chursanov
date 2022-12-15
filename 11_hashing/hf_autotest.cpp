#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "hash.h"
#include <doctest.h>

TEST_CASE("whatever") {
  CHECK_EQ(default_hash("test"), 1147426883);
  CHECK_EQ(default_hash("tset"), 2979146563);
  CHECK_EQ(default_hash("TEST"), 2839250627);
  CHECK_EQ(default_hash("uw"), 849752887);
  CHECK_EQ(default_hash("uwuw"), 3451170197);
}

// oop_is_the_best_programming_paradigma 2372392596
// oop_is_the_1234_programming_paradigma 3462918384