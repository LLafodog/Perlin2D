project(Perlin2D)
set(EXECUTABLE_OUTPUT_PATH bin/)
cmake_minimum_required( VERSION 2.8)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML2 REQUIRED sfml-graphics>=2.1)

file(

GLOB_RECURSE

src_file

include/*
src/*
./main.cpp
)

add_definitions(-std=c++11)
include_directories(

include/
)

add_executable(

Perlin2D

${src_file}
)

target_link_libraries(

Perlin2D
sfml-graphics
sfml-window
sfml-system
)