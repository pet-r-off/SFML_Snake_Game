#include "Score.h"


Score::Score() : Text("Score: " + std::to_string(this->score), sf::Color::Red, 25, sf::Vector2f(0.f, 0.f)){}


Score::~Score() {}


void Score::increaseScore() {
    this->score += (int)getRandomNum();
}


int Score::getScore() {
    return this->score;
}


void Score::setScore(int score) {
    this->score = score;
}


int Score::getRecord() {
    try {
        this->record_file.open("/home/petroff/C++_Lessons/Common/sfml/SNAKE_GAME/snake_game/common_files/record_score.txt");
    } catch (const std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    this->record_file >> this->record;
    this->record_file.close();
    return this->record;
}


void Score::setRecord() {
    try {
        this->record_file.open("/home/petroff/C++_Lessons/Common/sfml/SNAKE_GAME/snake_game/common_files/record_score.txt");
    } catch (const std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }


    if(this->score > this->record) {
        this->record_file << this->score;
    }
    else {
        this->record_file.close();
    }
}

