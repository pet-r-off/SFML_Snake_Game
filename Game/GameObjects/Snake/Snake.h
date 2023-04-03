#ifndef SNAKE_GAME_SNAKE_H
#define SNAKE_GAME_SNAKE_H


#include "../gameObject.h"


class Snake {
private:

    class Snake_Node : public gameObject {
    public:
        Snake_Node();
        Snake_Node(float pos_x_, float pos_y_, int direction);
        Snake_Node(const sf::Vector2f &position, int direction);
        ~Snake_Node();

        void move();
        static void increaseSpeed();
        static void resetSpeed();
        static float getSpeed();

        int snakeNodeMovements;
    private:
        static float speed;
    };

    void move_snake(sf::Vector2f direction);
    std::list<Snake_Node>::iterator head;
    std::list<Snake_Node>::iterator tail;
public:
    Snake();
    ~Snake();

    void handle_direction(sf::Time &timeSinceLastMove);
    void add_tail();
    void stop();
    void restart();

    int snakeMovements;
    std::list<Snake_Node> snakeNodes;
};


#endif //SNAKE_GAME_SNAKE_H

