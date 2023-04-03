#ifndef SNAKE_GAME_GAMEOBJECT_H
#define SNAKE_GAME_GAMEOBJECT_H


#include "../../stdafx.h"


class gameObject {
public:
    gameObject();
    gameObject(float pos_x_, float pos_y_);
    explicit gameObject(const sf::Vector2f &position);
    ~gameObject();

    void setWidth(float new_width);
    void setHeight(float new_height);

    sf::RectangleShape objectRect;
private:
    float width = 35.f;
    float height = 35.f;
};


enum Direction{IDLE, UP, DOWN, RIGHT, LEFT};
enum gameStates{MENU, GAME, GAME_OVER};


inline float getRandomPos(int min, int max) {
    srand(time(NULL));
    int num = min + rand() % (max - min + 1);

    return (float)num;
}


inline float getRandomNum() {
    srand(time(NULL));
    int num = 0 + rand() % (20 - 0 + 1);

    return (float)num;
}


#endif //SNAKE_GAME_GAMEOBJECT_H
