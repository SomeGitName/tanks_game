cmake_minimum_required(VERSION 3.0.0)
project(TanksGame VERSION 0.1.0)

include(CTest)
enable_testing()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

# SET(CMAKE_CXX_FLAGS_DEBUG "-O0")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
# include_directories(TanksGame ${SDL2_INCLUDE_DIRS})


# add_library(external.sdl2 INTERFACE)
# target_include_directories(external.sdl2 INTERFACE ${SDL2_INCLUDE_DIRS})
# target_link_libraries(external.sdl2 INTERFACE ${SDL2_LIBRARIES})

add_executable(TanksGame src/AnimatedSprite.cpp src/Button.cpp src/CollisionDetector.cpp src/Event.cpp src/EventCallback.cpp src/Game.cpp src/Hitbox.cpp src/InputManager.cpp src/main.cpp  src/Map.cpp src/MapTile.cpp src/Scene.cpp src/SceneGame.cpp src/SceneMenu.cpp src/Sprite.cpp src/Tank.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# target_link_libraries(TanksGame ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Image)