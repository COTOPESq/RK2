cmake_minimum_required(VERSION 3.10)
project(ConceptualExample)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ConceptualExample Program.cpp ConceptualExample.cpp)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

add_executable(runTests tests.cpp)

target_link_libraries(runTests gtest_main)
target_compile_options(gtest PRIVATE -Wno-error=maybe-uninitialized)

include(GoogleTest)
gtest_discover_tests(runTests)

