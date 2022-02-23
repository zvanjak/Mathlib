cmake_minimum_required(VERSION 3.0.0)

project(SimpleAppWithTests VERSION 0.1.0)

set(SIMPLEAPPWITHTESTS_SOURCES src/calc.cpp src/simple_app.cpp )
add_executable(SimpleAppWithTests ${SIMPLEAPPWITHTESTS_SOURCES})

target_include_directories(SimpleAppWithTests PRIVATE include)

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

file(GLOB APPSOURCES src/calc.cpp )
file(GLOB TESTS tests/calc_tests.cpp)

add_executable(CalcTests "test_runner.cpp" ${TESTS} ${APPSOURCES})
target_link_libraries(CalcTests Catch)
target_include_directories(CalcTests PRIVATE include)