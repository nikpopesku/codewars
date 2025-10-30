cmake_minimum_required(VERSION 3.16)
project(codewars CXX)

# Default to Debug build if not specified (helps IDEs and local runs)
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Enforce C++17 without compiler-specific extensions
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Catch2 3 REQUIRED)

# Optionally enable sanitizers for GCC/Clang
option(ENABLE_SANITIZERS "Enable Address/UB sanitizers (GCC/Clang)" OFF)

# Build the code under test as a library with all kata sources
add_library(kata STATIC
#    kata/quarter_of_the_year.cpp
#    kata/find_the_vowels.cpp
    kata/valid_parentheses.cpp
)

# Test executable containing all test files
add_executable(YourTestRunner
#    tests/quarter_of_the_year.cpp
#    tests/find_the_vowels.cpp
    tests/valid_parentheses.cpp
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

# Optional sanitizers for GCC/Clang
if (ENABLE_SANITIZERS AND CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(kata PRIVATE -fsanitize=address,undefined)
    target_link_options(kata PRIVATE -fsanitize=address,undefined)
    target_compile_options(YourTestRunner PRIVATE -fsanitize=address,undefined)
    target_link_options(YourTestRunner PRIVATE -fsanitize=address,undefined)
endif()

# Enable test discovery
include(CTest)
include(Catch)
catch_discover_tests(YourTestRunner)