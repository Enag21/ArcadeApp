cmake_minimum_required(VERSION 3.7)

project(
    ArcadeApp
    VERSION 0.1 
    LANGUAGES CXX
)

find_package(SDL2 REQUIRED)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(app)

