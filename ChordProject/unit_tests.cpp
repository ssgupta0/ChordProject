
#include "gtest/gtest.h"

#include "Decorator_tests.hpp"
#include "Visitor_tests.hpp"
#include "Factory_tests.hpp"
#include "Chord_tests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
