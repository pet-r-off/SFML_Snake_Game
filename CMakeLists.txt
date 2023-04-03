cmake_minimum_required(VERSION 3.24)
project(snake_game)

set(CMAKE_CXX_STANDARD 17)

set(SFML_LIBRARY_G /usr/lib/x86_64-linux-gnu/libsfml-graphics.so)
set(SFML_LIBRARY_W /usr/lib/x86_64-linux-gnu/libsfml-window.so)
set(SFML_LIBRARY_S /usr/lib/x86_64-linux-gnu/libsfml-system.so)

add_executable(snake_game
                main.cpp
                stdafx.h
                Game/Game.cpp Game/Game.h
                Game/GameObjects/gameObject.cpp Game/GameObjects/gameObject.h
                Game/GameObjects/Snake/Snake.cpp Game/GameObjects/Snake/Snake.h
                Game/GameObjects/Fruit/Fruit.cpp Game/GameObjects/Fruit/Fruit.h
                Game/GameObjects/Wall/Walls.cpp Game/GameObjects/Wall/Walls.h
                Game/Background/Background.cpp Game/Background/Background.h
                Game/Text/Text.cpp Game/Text/Text.h
                Game/Text/Score/Score.cpp Game/Text/Score/Score.h
                Game/Menu/Menu.cpp Game/Menu/Menu.h )
               

target_link_libraries(snake_game ${SFML_LIBRARY_G} ${SFML_LIBRARY_W} ${SFML_LIBRARY_S})
