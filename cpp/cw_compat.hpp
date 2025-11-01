#pragma once

#include <string>
#include <catch2/catch_all.hpp>

// Map Codewars BDD-style to Catch2 equivalents
#define Describe(name) TEST_CASE(#name)
#define It(name)       SECTION(#name)

// Keep familiar helpers
#define Equals(expected) expected
#define ExtraMessage(msg) (msg)

// Optional glue for kata-specific boolean predicate tests
// To enable `dotest("...", expected)` for a specific kata, define:
//   #define CW_BOOL_PREDICATE_FUNC yourFunctionName
// before including this header. The function must have signature:
//   bool yourFunctionName(const std::string&)
#ifdef CW_BOOL_PREDICATE_FUNC
namespace cw_compat {
    inline void dotest(const std::string& str, bool expected) {
        bool actual = CW_BOOL_PREDICATE_FUNC(str);
        INFO("Incorrect answer for input = \"" << str << "\"");
        REQUIRE(actual == expected);
    }
}
// Allow calls like dotest("()", true)
#define dotest(str, expected) ::cw_compat::dotest((str), (expected))
#endif

// Provide Assert::That(...) API similar to Codewars
namespace Assert {
    template <typename Actual, typename Expected>
    inline void That(const Actual& actual, const Expected& expected, const std::string& msg = "") {
        if (!msg.empty()) INFO(msg);
        REQUIRE(actual == expected);
    }
}
