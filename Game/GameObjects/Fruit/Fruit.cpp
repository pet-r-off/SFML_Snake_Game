#include "Fruit.h"


Fruit::Fruit() : gameObject(getRandomPos(30, 770), getRandomPos(30, 450)) {
    try {
        this->fruit_texture.loadFromFile("/home/petroff/C++_Lessons/Common/sfml/SNAKE_GAME/snake_game/common_files/apple_fruit.png");
    } catch (const std::exception &ex){
        std::cout << ex.what() << std::endl;
    }

    const sf::Texture *pTexture = &fruit_texture;

    this->objectRect.setFillColor(sf::Color::Yellow);
    this->objectRect.setOutlineThickness(3.f);
    this->objectRect.setOutlineColor(sf::Color::Transparent);
    this->objectRect.setTexture(pTexture);
    std::cout << "Fruit Constr" << std::endl;
}


Fruit::~Fruit() {std::cout << "Fruit Destr" << std::endl;}


void Fruit::new_pos() {
    this->objectRect.setPosition(getRandomPos(30, 770), getRandomPos(30, 450));
}

