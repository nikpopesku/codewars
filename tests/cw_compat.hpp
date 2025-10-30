#pragma once

#include <string>
#include <catch2/catch_all.hpp>

// Map Codewars BDD-style to Catch2 equivalents
#define Describe(name) TEST_CASE(#name)
#define It(name)       SECTION(#name)

// Keep familiar helpers
#define Equals(expected) expected
#define ExtraMessage(msg) (msg)

namespace cw_compat {
    inline void dotest(const std::string& str, bool expected) {
        bool actual = validParentheses(str);
        INFO("Incorrect answer for input = \"" << str << "\"");
        REQUIRE(actual == expected);
    }
}

// Allow calls like dotest("()", true)
#define dotest(str, expected) ::cw_compat::dotest((str), (expected))
