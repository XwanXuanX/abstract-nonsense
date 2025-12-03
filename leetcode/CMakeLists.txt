cmake_minimum_required(VERSION 3.22)
project(leetcode)

file(GLOB SOURCES "*.cpp")

foreach(src ${SOURCES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})
endforeach()
