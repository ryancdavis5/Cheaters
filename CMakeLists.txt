cmake_minimum_required(VERSION 3.14)
project(Cheaters)

set(CMAKE_CXX_STANDARD 14)

#include_directories(sm_doc_set)

add_executable(Cheaters main.cpp hashTable.h hashTable.cpp)