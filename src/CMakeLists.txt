cmake_minimum_required(VERSION 3.0.0)

project(MathLib_SimpleApp VERSION 0.1.0)

set(MATHLIB_SIMPLE_APP_SOURCES src/calc.cpp src/vector.cpp src/simple_app.cpp )
add_executable(MathLib_SimpleApp ${MATHLIB_SIMPLE_APP_SOURCES})

target_include_directories(MathLib_SimpleApp PRIVATE include)

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

file(GLOB MATHLIB_SOURCES src/calc.cpp src/vector.cpp)
file(GLOB TESTS tests/calc_tests.cpp)

add_executable(CalcTests "test_runner.cpp" ${TESTS} ${MATHLIB_SOURCES})
target_link_libraries(CalcTests Catch)
target_include_directories(CalcTests PRIVATE include)