#ifndef SNAKE_GAME_TEXT_H
#define SNAKE_GAME_TEXT_H


#include "../../stdafx.h"


class Text {
public:
    Text();
    Text(std::string text_string, sf::Color color, int font_size, sf::Vector2f position);
    ~Text();

    sf::Text getText();
    void updateText(std::string text_string);
private:
    sf::Text scoreText;
    sf::Font scoreFont;
};


#endif //SNAKE_GAME_TEXT_H
