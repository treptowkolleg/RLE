cmake_minimum_required(VERSION 3.2)
project(RLE)

set(CMAKE_CXX_STANDARD 11)

add_executable(RLE main.cpp
        src/encoder.h
        src/encoder.cpp
        src/Filesystem.cpp
        src/Filesystem.h
        src/FileSystem.cpp
        src/FileSystem.h)
