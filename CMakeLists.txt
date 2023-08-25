cmake_minimum_required(VERSION 3.21)
project(EDyA_hashing C)

set(CMAKE_C_STANDARD 11)

add_executable(EDyA_hashing main.c hash.c hash.h)
