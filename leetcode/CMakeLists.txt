cmake_minimum_required(VERSION 3.22)
project(leetcode)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SOURCES CONFIGURE_DEPENDS
        "*.cpp"
        "*.cc"
)

foreach(src ${SOURCES})
    get_filename_component(name ${src} NAME)
    string(REPLACE "." "_" target ${name})
    add_executable(${target} ${src})
    target_compile_features(${target} PRIVATE cxx_std_23)
endforeach()
