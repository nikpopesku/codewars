#include <catch2/catch_test_macros.hpp>

// Declaration to use the function implemented in quarter_of_the_year.cpp
int quarter_of(const int month);

TEST_CASE("quarter_of basic cases") {
    REQUIRE(quarter_of(1) == 1);
    REQUIRE(quarter_of(3) == 1);
    REQUIRE(quarter_of(5) == 2);
    REQUIRE(quarter_of(7) == 3);
    REQUIRE(quarter_of(9) == 3);
    REQUIRE(quarter_of(11) == 4);
}