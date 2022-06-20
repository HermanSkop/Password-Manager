cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp Console.h Console.cpp NoMatchesException.h FileManager.cpp FileManager.h PasswordManager.cpp PasswordManager.h PasswordPack.cpp PasswordPack.h)
