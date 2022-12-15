cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
project(complex LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include(doctest.cmake)
add_executable(hf_autotest hash.h hf_autotest.cpp)
target_link_libraries(hf_autotest PRIVATE doctest)