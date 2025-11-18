#pragma once

#include <string>
#include <unordered_set>
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
    // Primary template for regular comparisons
    template <typename Actual, typename Expected>
    auto That(const Actual& actual, const Expected& expected, const std::string& msg = "")
        -> decltype(actual == expected, void()) {
        if (!msg.empty()) INFO(msg);
        REQUIRE(actual == expected);
    }

    // Overload for predicate functions (lambdas, function pointers, etc.)
    template <typename Actual, typename Predicate>
    auto That(const Actual& actual, Predicate predicate, const std::string& msg = "")
        -> decltype(predicate(actual), void()) {
        if (!msg.empty()) INFO(msg);
        REQUIRE(predicate(actual));
    }
}

// Helper macros for unordered matching
#define Fulfills(condition) condition
#define Unordered_Match(expected) [&expected](const auto& actual) { \
    std::unordered_set<typename std::decay_t<decltype(actual)>::value_type> actual_set(actual.begin(), actual.end()); \
    std::unordered_set<typename std::decay_t<decltype(expected)>::value_type> expected_set(expected.begin(), expected.end()); \
    return actual_set == expected_set; \
}
