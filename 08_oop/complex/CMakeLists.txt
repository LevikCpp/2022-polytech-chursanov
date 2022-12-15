cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
project(complex LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include(doctest.cmake)
add_executable(tests custom_complex.h test_complex.cpp)
target_link_libraries(tests PRIVATE doctest)