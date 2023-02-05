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
    Shapes/Shape.h
    Shapes/Shape.cpp
    Shapes/Triangle.cpp
    Shapes/Triangle.h
    Shapes/AARectangle.cpp
    Shapes/AARectangle.h
    Shapes/Circle.cpp    
    Shapes/Circle.h
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


add_library(
    Scenes
    Scenes/Scene.h
    Scenes/ArcadeScene.h
    Scenes/ArcadeScene.cpp
    )
    
target_include_directories(Scenes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Scenes/)

target_link_libraries(Scenes PRIVATE Graphics Shapes)

add_library(
    App
    App/App.h
    App/App.cpp
)

target_include_directories(App PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/App/)

target_link_libraries(App PRIVATE SDL2::SDL2 Shapes Graphics Scenes)