cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME algorithms)
project(${PROJECT_NAME})

set(CUSTOM "${PROJECT_NAME}")
set(TESTS   "test_${PROJECT_NAME}")
set(INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")

include_directories("${INCLUDE}" gtest)

add_subdirectory(include)
add_subdirectory(gtest)
add_subdirectory(test)

message( STATUS "")
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "======================================")
message( STATUS "")
message( STATUS "   Configuration: ${CMAKE_BUILD_TYPE}")
message( STATUS "")