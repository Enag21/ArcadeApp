add_executable(ArcadeApp-dev ArcadeApp.cpp)

target_link_libraries(ArcadeApp-dev PUBLIC App Graphics Utils Shapes SDL2::SDL2)