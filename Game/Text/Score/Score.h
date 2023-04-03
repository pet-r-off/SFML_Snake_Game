#ifndef SNAKE_GAME_SCORE_H
#define SNAKE_GAME_SCORE_H


#include "../Text.h"
#include "../../GameObjects/gameObject.h"


class Score : public Text {
public:
    Score();
    ~Score();

    void increaseScore();
    int getScore();
    void setScore(int score);
    int getRecord();
    void setRecord();
private:
    int score = 0;
    int record;
    std::fstream record_file;
};


#endif //SNAKE_GAME_SCORE_H
