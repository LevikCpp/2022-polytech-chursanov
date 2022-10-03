cmake_minimum_required(VERSION 3.2)

project(search)

set(SOURCES main.cpp linear.h binary.h)

add_executable(${PROJECT_NAME} ${SOURCES})