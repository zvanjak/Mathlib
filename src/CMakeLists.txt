cmake_minimum_required(VERSION 3.0.0)

project(MathLib_SimpleApp VERSION 0.1.0)

set(MATHLIB_SIMPLE_APP_SOURCES src/vector.cpp src/simple_app.cpp )
add_executable(MathLib_SimpleApp ${MATHLIB_SIMPLE_APP_SOURCES})

target_include_directories(MathLib_SimpleApp PRIVATE include)

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

file(GLOB MATHLIB_SOURCES src/vector.cpp)
file(GLOB MATHLIB_TESTS tests/vector_tests.cpp)

add_executable(Mathlib_Tests "mathlib_test_runner.cpp" ${MATHLIB_SOURCES} ${MATHLIB_TESTS} )
target_link_libraries(Mathlib_Tests Catch)
target_include_directories(Mathlib_Tests PRIVATE include)