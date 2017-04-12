cmake_minimum_required(VERSION 3.7)
project(refa)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES
        external/gtest/gtest-all.cc
        external/gtest/gtest.h
        test/gtest_main.cpp)

include_directories(external)
include_directories(src)


add_executable(refa ${SOURCE_FILES})