#include "Background.h"


Background::Background() {
    try{
        this->backgrndTexture.loadFromFile("/home/petroff/Pictures/SFML_sprites/background/snake_back.jpg");
    }catch (const std::exception &ex){
        std::cout << ex.what() << std::endl;
    }

    this->backgrndSprite.setTexture(backgrndTexture);
    this->backgrndSprite.setPosition(0.f, 0.f);
    std::cout << "Backgrnd Constr" << std::endl;
}


Background::~Background() {
    std::cout << "Backgrnd Destr" << std::endl;
}

