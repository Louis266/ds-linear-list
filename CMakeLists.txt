cmake_minimum_required(VERSION 3.12)
project(ds_linear_list C)

include_directories( "src" )

set(CMAKE_C_STANDARD 99)

add_executable(ds_linear_list main.c src/LinkedList.c)