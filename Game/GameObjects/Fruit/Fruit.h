#ifndef SNAKE_GAME_FRUIT_H
#define SNAKE_GAME_FRUIT_H


#include "../gameObject.h"


class Fruit : public gameObject {
public:
    Fruit();
    ~Fruit();

    void new_pos();
private:
    sf::Texture fruit_texture;
};


#endif //SNAKE_GAME_FRUIT_H
