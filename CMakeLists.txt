cmake_minimum_required(VERSION 3.21)
project(lang)

set(CMAKE_CXX_STANDARD 17)

add_executable(lang main.cpp defines/instruction.h defines/instructions.cpp memory/Memory.cpp memory/Memory.h)
