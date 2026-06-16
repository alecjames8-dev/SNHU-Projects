cmake_minimum_required(VERSION 4.2)
project(GroceryApp)

set(CMAKE_CXX_STANDARD 20)

add_executable(GroceryApp main.cpp
        GroceryTracker.cpp
        GroceryTracker.h)
