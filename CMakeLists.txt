cmake_minimum_required(VERSION 3.16)
project(codewars CXX)

find_package(Catch2 3 REQUIRED)

# Build the code under test as a library with all kata sources
add_library(kata STATIC
    kata/quarter_of_the_year.cpp
    kata/find_the_vowels.cpp
)

# Test executable containing all test files
add_executable(YourTestRunner
    tests/quarter_of_the_year.cpp
    tests/find_the_vowels.cpp
)

# Link Catch2 main and your library
target_link_libraries(YourTestRunner PRIVATE kata Catch2::Catch2WithMain)

# Enable warnings for GCC/Clang
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(kata PRIVATE -Wall -Wextra -Wpedantic -Wsign-compare)
    target_compile_options(YourTestRunner PRIVATE -Wall -Wextra -Wpedantic -Wsign-compare)
endif()

# Enable higher warnings for MSVC
if (MSVC)
    target_compile_options(kata PRIVATE /W4 /permissive-)
    target_compile_options(YourTestRunner PRIVATE /W4 /permissive-)
endif()

# Enable test discovery
include(CTest)
include(Catch)
catch_discover_tests(YourTestRunner)