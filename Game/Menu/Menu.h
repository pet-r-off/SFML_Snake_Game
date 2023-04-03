#ifndef SNAKE_GAME_MENU_H
#define SNAKE_GAME_MENU_H


#include "../../stdafx.h"
#include "../Text/Text.h"

class Menu {
public:
    Menu();
    ~Menu();

    void run(sf::RenderWindow &window);
private:
    sf::Texture bkgrndTexture;
    sf::Sprite bkgrndSprite;
    Text game_name, play, exit;
};




#endif //SNAKE_GAME_MENU_H
