cmake_minimum_required(VERSION 3.0.0)

set (CMAKE_CXX_STANDARD 17)

project(MathLib_SimpleApp VERSION 0.1.0)

find_package( Boost 1.78.0 )

if ( Boost_FOUND )
    include_directories( ${Boost_INCLUDE_DIRS} )
else()
    message( FATAL_ERROR "Required Boost packages not found. Perhaps add -DBOOST_ROOT?" )
endif()

set(MATHLIB_SIMPLE_APP_SOURCES  src/simple_app.cpp 
                                src/test_vector_matrix.cpp
                                src/test_integration.cpp
                                src/test_polynom.cpp
                                src/test_coord_systems.cpp
                                src/test_function.cpp
                                src/test_metric_tensor.cpp
                                src/test_fields.cpp
                                )
add_executable(MathLib_SimpleApp ${MATHLIB_SIMPLE_APP_SOURCES})

target_include_directories(MathLib_SimpleApp PRIVATE include)

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

file(GLOB MATHLIB_SOURCES src/mml.h src/VectorN.h)
file(GLOB MATHLIB_TESTS tests/vector_tests.cpp
                        tests/derivation_tests.cpp 
                        )

add_executable(Mathlib_Tests "mathlib_test_runner.cpp" ${MATHLIB_SOURCES} ${MATHLIB_TESTS} )
target_link_libraries(Mathlib_Tests Catch)
target_include_directories(Mathlib_Tests PRIVATE include)