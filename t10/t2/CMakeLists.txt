cmake_minimum_required(VERSION 3.16)

project(FlowerDragDrop LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(flower_app
    src/main.cpp
    src/Application.cpp
    src/Flower.cpp
)

target_link_libraries(flower_app
    sfml-graphics
    sfml-window
    sfml-system
)


