#ifndef SNAKE_GAME_WALLS_H
#define SNAKE_GAME_WALLS_H


#include "../gameObject.h"


class Walls {
private:

    class Wall_Node : public gameObject{
    public:
        Wall_Node();
        explicit Wall_Node(sf::Vector2f position);
        ~Wall_Node();

    private:
        sf::Texture wall_texture;
    };

public:
    Walls();
    ~Walls();

    std::vector<Wall_Node> wall_nodes;
};


#endif //SNAKE_GAME_WALLS_H
