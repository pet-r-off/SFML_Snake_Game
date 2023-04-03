#ifndef SNAKE_GAME_BACKGROUND_H
#define SNAKE_GAME_BACKGROUND_H


#include "../../stdafx.h"


class Background {
public:
    Background();
    ~Background();

    sf::Sprite backgrndSprite;
private:
    sf::Texture backgrndTexture;
};


#endif //SNAKE_GAME_BACKGROUND_H
