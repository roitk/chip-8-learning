cmake_minimum_required(VERSION 3.5)
project(chip-8)
set(CMAKE_CXX_STANDARD 14)

FILE(GLOB Chip8Ops src/chip8_*.cc)

add_executable(chip8 src/game_loop.cc src/chip8.cc ${Chip8Ops})