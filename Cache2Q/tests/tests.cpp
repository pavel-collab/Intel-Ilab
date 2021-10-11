#define CATCH_CONFIG_MAIN
#include <iostream>

#include "catch.hpp"
#include "../include/cache.hpp"

TEST_CASE("2+2 must be equal is 4") {
    REQUIRE(2 + 2 == 4);
}