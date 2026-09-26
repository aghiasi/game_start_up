cmake_minimum_required(VERSION 3.16)

project(MyGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML-3.1.0/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics)

add_executable(MyGame
    src/main.cpp
)

target_link_libraries(MyGame PRIVATE
    SFML::Graphics
)
