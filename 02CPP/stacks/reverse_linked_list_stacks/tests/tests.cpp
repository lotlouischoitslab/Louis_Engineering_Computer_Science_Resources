#include <stdlib.h>
#include <iostream>
#include "catch.hpp"
#include "stack.hpp"

using namespace std;

TEST_CASE("Louis-Sungwoo-Cho") {
  // Write your test case
  Stack louis;
  string name = "Louis-Sungwoo-Cho";
  louis.setName(name);
  louis.Reverse();
  
  REQUIRE(louis.return_Reverse() == "ohC-oowgnuS-siuoL");
}