cmake_minimum_required(VERSION 3.5.0)
project(ProjectGrid VERSION 0.1.0 LANGUAGES C CXX)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(ProjectGrid
    src/main.cpp
    src/Grid.cpp
)

target_link_libraries(ProjectGrid ${SDL2_LIBRARIES})



