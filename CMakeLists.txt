cmake_minimum_required(VERSION 3.2)
project(RLE)

set(CMAKE_CXX_STANDARD 20)

add_executable(RLE main.cpp
        src/Encoder.h
        src/Encoder.cpp
        src/FileSystem.cpp
        src/FileSystem.h
        lib/libusb.h
        src/System/Color.h
        src/System/Out.cpp
        src/System/Out.h
        src/System/In.cpp
        src/System/In.h
        src/System/System.cpp
        src/System/System.h
        src/TUI/TerminalMenu.cpp
        src/TUI/TerminalMenu.h
        src/TUI/TerminalMenuItem.cpp
        src/TUI/TerminalMenuItem.h
        Main.h)
