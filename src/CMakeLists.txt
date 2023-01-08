add_library(
    Utils
    Utils/Utils.cpp
    Utils/Utils.h
    Utils/Vector2D.cpp
    Utils/Vector2D.h
)

target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Utils/) 

add_library(
    Shapes
    Shapes/Line2D.cpp
    Shapes/Line2D.h
)

target_include_directories(Shapes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Shapes/) 

target_link_libraries(Shapes PRIVATE Utils SDL2::SDL2)

add_library(
    Graphics
    Graphics/Color.cpp
    Graphics/Color.h
    Graphics/Screen.cpp
    Graphics/Screen.h
    Graphics/ScreenBuffer.cpp
    Graphics/ScreenBuffer.h
)

target_include_directories(Graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Graphics/) 

target_link_libraries(Graphics PRIVATE Utils Shapes SDL2::SDL2)