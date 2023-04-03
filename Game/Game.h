#ifndef SNAKE_GAME_GAME_H
#define SNAKE_GAME_GAME_H


#include "Menu/Menu.h"
#include "GameObjects/Snake/Snake.h"
#include "GameObjects/Fruit/Fruit.h"
#include "GameObjects/Wall/Walls.h"
#include "Background/Background.h"
#include "Text/Score/Score.h"


class Game {
public:
    Game();
    ~Game();

    void run();               // main loop
private:
    sf::RenderWindow mWindow; // mainWindow
    sf::Event mEvent;         // mainEvent
    sf::Clock mClock;         // mainClock
    sf::Time timeSinceLastMove;
    Menu mMenu;
    Snake mSnake;             // mainSnake
    Fruit mFruit;             // mainFruit
    Walls mWalls;
    Background mBackground;   // mainBackground
    Score gameScore;
    Text gameOverText, restartText;

    int gameState = gameStates::MENU;

    void processEvents();     // handle input events
    void update();            // update all objects
    void render();            // display updated objects

    // state methods
    void handleInputKey(sf::Keyboard::Key key);
    void handleInputMouse(sf::Vector2f cursor_pos);
    void draw_snake();
    void draw_walls();
    void isColliding(sf::RectangleShape &snake_rect, sf::RectangleShape &fruit_rect);
    bool isColliding(sf::RectangleShape &wall_rect);
    void wallCollider();
};


#endif //SNAKE_GAME_GAME_H

