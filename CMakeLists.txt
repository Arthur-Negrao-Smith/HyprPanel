cmake_minimum_required(VERSION 3.10)
project(HyprPanel)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL3 REQUIRED CONFIG)

add_executable(main
  src/main.cpp
)

target_link_libraries(main PRIVATE SDL3::SDL3)
