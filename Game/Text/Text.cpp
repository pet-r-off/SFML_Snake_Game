#include "Text.h"


Text::Text() {
    try {
        this->scoreFont.loadFromFile("/home/petroff/C++_Lessons/Common/sfml/SNAKE_GAME/snake_game/common_files/Arial_Bold.ttf");
    } catch (const std::exception &ex){
        std::cout << ex.what() << std::endl;
    }

    this->scoreText.setFont(this->scoreFont);
    this->scoreText.setFillColor(sf::Color::Red);
    this->scoreText.setCharacterSize(25);
    this->scoreText.setString("Text: ");
    this->scoreText.setPosition(sf::Vector2f(0.f, 0.f));
}


Text::Text(std::string text_string, sf::Color color, const int font_size, sf::Vector2f position) {
    try {
        this->scoreFont.loadFromFile("/home/petroff/C++_Lessons/Common/sfml/SNAKE_GAME/snake_game/common_files/Arial_Bold.ttf");
    } catch (const std::exception &ex){
        std::cout << ex.what() << std::endl;
    }

    this->scoreText.setFont(this->scoreFont);
    this->scoreText.setFillColor(color);
    this->scoreText.setCharacterSize(font_size);
    this->scoreText.setString(text_string);
    this->scoreText.setPosition(position);
}


Text::~Text() {std::cout << "Text Destructor" << std::endl;}


sf::Text Text::getText() {
    return this->scoreText;
}


void Text::updateText(std::string text_string) {
    this->scoreText.setString(text_string);
}

