#include "Menu.h"


Menu::Menu()
    : game_name("Snake Game", sf::Color::White, 20, sf::Vector2f(355.f, 22.f)),
    play("Play", sf::Color::White, 25, sf::Vector2f(387.f, 120.f)),
    exit("Exit", sf::Color::White, 25, sf::Vector2f(387.f, 300.f)) {
    try {
        bkgrndTexture.loadFromFile("/home/petroff/C++_Lessons/Common/sfml/SNAKE_GAME/snake_game/common_files/menu_game.png");
    } catch (const std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    this->bkgrndSprite.setTexture(this->bkgrndTexture);
    this->bkgrndSprite.setPosition(-30.f, 0.f);
}


Menu::~Menu() {}


void Menu::run(sf::RenderWindow &window) {

    window.draw(this->bkgrndSprite);
    window.draw(this->game_name.getText());
    window.draw(this->play.getText());
    window.draw(this->exit.getText());
}

