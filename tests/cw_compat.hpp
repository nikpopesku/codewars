#pragma once

#include <string>
#include <catch2/catch_all.hpp>

// Forward declarations for helpers referenced by generic test utilities
// Declared in kata/valid_parentheses.cpp and tested in tests/valid_parentheses.cpp
bool validParentheses(const std::string&);

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

// Provide Assert::That(...) API similar to Codewars
namespace Assert {
    template <typename Actual, typename Expected>
    inline void That(const Actual& actual, const Expected& expected, const std::string& msg = "") {
        if (!msg.empty()) INFO(msg);
        REQUIRE(actual == expected);
    }
}

// Allow calls like dotest("()", true)
#define dotest(str, expected) ::cw_compat::dotest((str), (expected))
