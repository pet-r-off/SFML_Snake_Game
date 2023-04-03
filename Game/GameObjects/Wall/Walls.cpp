#include "Walls.h"


Walls::Walls() {
    Wall_Node *new_wall = new Wall_Node(sf::Vector2f(0.f, 0.f));
    this->wall_nodes.push_back(*new_wall);

    for (int i = 0; i < 27; ++i) {
        Wall_Node *new_wall = new Wall_Node(sf::Vector2f(30.f + 30.f * i, 0.f));
        this->wall_nodes.push_back(*new_wall);
    }

    for (int i = 0; i < 16; ++i) {
        Wall_Node *new_wall = new Wall_Node(sf::Vector2f(765.f , 30.f + 30.f * i));
        this->wall_nodes.push_back(*new_wall);
    }

    for (int i = 0; i < 25; ++i) {
        Wall_Node *new_wall = new Wall_Node(sf::Vector2f(30.f + 30.f * i , 450.f));
        this->wall_nodes.push_back(*new_wall);
    }

    for (int i = 0; i < 15; ++i) {
        Wall_Node *new_wall = new Wall_Node(sf::Vector2f(0.f, 30.f + 30.f * i));
        this->wall_nodes.push_back(*new_wall);
    }
}


Walls::~Walls() {}










Walls::Wall_Node::Wall_Node() : gameObject(0.f, 0.f) {
    try {
        this->wall_texture.loadFromFile("/home/petroff/C++_Lessons/Common/sfml/SNAKE_GAME/snake_game/common_files/wall.png");
    } catch (const std::exception &ex){
        std::cout << ex.what() << std::endl;
    }

    const sf::Texture *pTexture = &wall_texture;

    this->setHeight(30.f);
    this->setWidth(30.f);
    this->objectRect.setOutlineColor(sf::Color::Transparent);
    this->objectRect.setTexture(pTexture);
    //std::cout << "Wall_Node Constr" << std::endl;
}


Walls::Wall_Node::Wall_Node(sf::Vector2f position) : gameObject(position) {
    try {
        this->wall_texture.loadFromFile("/home/petroff/C++_Lessons/Common/sfml/SNAKE_GAME/snake_game/common_files/wall.png");
    } catch (const std::exception &ex){
        std::cout << ex.what() << std::endl;
    }

    const sf::Texture *pTexture = &wall_texture;

    this->setHeight(30.f);
    this->setWidth(30.f);
    this->objectRect.setOutlineColor(sf::Color::Transparent);
    this->objectRect.setTexture(pTexture);
    //std::cout << "Wall_Node Constr" << std::endl;
}


Walls::Wall_Node::~Wall_Node() {}

