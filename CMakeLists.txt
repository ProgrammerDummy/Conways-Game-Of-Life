cmake_minimum_required(VERSION 3.14)
project(conwaysgameoflife)

include_directories(/opt/homebrew/opt/pybind11/include/pybind11/)

find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(gameoflife game.cpp)
target_include_directories(gameoflife PRIVATE ${Python3_INCLUDE_DIRS})
set_target_properties(gameoflife PROPERTIES PREFIX "" SUFFIX ".so")
