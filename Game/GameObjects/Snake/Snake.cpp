#include "Snake.h"


Snake::Snake() {
    this->snakeNodes.push_front(*new Snake_Node(50.f, 200.f, Direction::IDLE));
    this->head = this->snakeNodes.begin();
    this->tail = --(this->snakeNodes.end());
    std::cout << "Snake Constr" << std::endl;
}


Snake::~Snake() {std::cout << "Snake Destr" << std::endl;}


void Snake::add_tail() {
    auto end = --(this->snakeNodes.end());

    float newX = end->objectRect.getPosition().x;
    float newY = end->objectRect.getPosition().y;

    switch (end->snakeNodeMovements) {
        case Direction::UP:
            newY += 38.f;
            break;

        case Direction::DOWN:
            newY -= 38.f;
            break;

        case Direction::RIGHT:
            newX -= 38.f;
            break;

        case Direction::LEFT:
            newX += 38.f;
            break;
    }
    this->snakeNodes.push_back(*new Snake_Node(newX, newY, end->snakeNodeMovements));
    Snake_Node::increaseSpeed();

    // DEBUG //std::cout << "Pos end x -> " << this->snakeNodes.back().objectRect.getPosition().x <<
    //                    " y -> " << this->snakeNodes.back().objectRect.getPosition().y << std::endl;
    std::cout << "Tail added" << std::endl;
}


void Snake::handle_direction(sf::Time &timeSinceLastMove) {

    if (timeSinceLastMove.asSeconds() >= sf::seconds(1.f / (Snake_Node::getSpeed())).asSeconds()) {
        switch (this->snakeMovements){
            case Direction::UP:
                //this->positionQueue.emplace_front(0.f, -38.f);
                this->move_snake(sf::Vector2f(0.f, -38.f));
                break;
            case Direction::DOWN:
                //this->positionQueue.emplace_front(0.f, 38.f);
                this->move_snake(sf::Vector2f(0.f, 38.f));
                break;
            case Direction::RIGHT:
                //this->positionQueue.emplace_front(38.f, 0.f);
                this->move_snake(sf::Vector2f(38.f, 0.f));
                break;
            case Direction::LEFT:
                //this->positionQueue.emplace_front(-38.f, 0.f);
                this->move_snake(sf::Vector2f(-38.f, 0.f));
                break;
        }

        //this->move();
        timeSinceLastMove = sf::Time::Zero;

//        if (this->positionQueue.size() > this->snakeNodes.size()){
//            this->positionQueue.pop_back();
//        }
    }
}


void Snake::move_snake(sf::Vector2f direction) {

    this->head->objectRect.setPosition(this->tail->objectRect.getPosition() + direction);
    this->tail = this->head;
    ++(this->head);

    if(this->head == this->snakeNodes.end()){
        this->head = this->snakeNodes.begin();
    }
}


void Snake::stop() {
    this->snakeMovements = Direction::IDLE;
}


void Snake::restart() {
    this->snakeNodes.clear();
    this->snakeNodes.push_front(*new Snake_Node(50.f, 200.f, Direction::IDLE));
    this->head = this->snakeNodes.begin();
    this->tail = --(this->snakeNodes.end());
    Snake_Node::resetSpeed();
}











/////////////////////////////////////////////////////////////////////////////////////
//      SNAKE_NODE METHODS
/////////////////////////////////////////////////////////////////////////////////////


float Snake::Snake_Node::speed = 2.f; // static


Snake::Snake_Node::Snake_Node()
                    : gameObject(0.f, 0.f), snakeNodeMovements(Direction::IDLE) {
    this->objectRect.setFillColor(sf::Color::Blue);
    this->objectRect.setOutlineColor(sf::Color::Black);
    this->objectRect.setOutlineThickness(3.f);
    this->objectRect.setFillColor(sf::Color(2, 2, 2));
    std::cout << "Snake_Node Constr" << std::endl;
}


Snake::Snake_Node::Snake_Node(float pos_x_, float pos_y_, int direction)
                    : gameObject(pos_x_, pos_y_), snakeNodeMovements(direction) {
    this->objectRect.setFillColor(sf::Color::Blue);
    this->objectRect.setOutlineColor(sf::Color::Black);
    this->objectRect.setOutlineThickness(3.f);
    std::cout << "Snake_Node Constr" << std::endl;
}


Snake::Snake_Node::Snake_Node(const sf::Vector2f &position, int direction)
                    : gameObject(position), snakeNodeMovements(direction) {
    this->objectRect.setFillColor(sf::Color::Blue);
    this->objectRect.setOutlineColor(sf::Color::Black);
    this->objectRect.setOutlineThickness(3.f);
    std::cout << "Snake_Node Constr" << std::endl;
}


Snake::Snake_Node::~Snake_Node() {std::cout << "Snake_Node Destr" << std::endl;}


void Snake::Snake_Node::move() {
    sf::Vector2f move(0.0f, 0.0f);

        switch (this->snakeNodeMovements) {
            case Direction::UP:
                move.y -= speed;
                break;

            case Direction::DOWN:
                move.y += speed;
                break;

            case Direction::RIGHT:
                move.x += speed;
                break;

            case Direction::LEFT:
                move.x -= speed;
                break;

            case Direction::IDLE:
                move = move;
                break;
        }

    this->objectRect.move(move);
}


void Snake::Snake_Node::increaseSpeed() { // static
    speed += 0.2f;
}


float Snake::Snake_Node::getSpeed() {
    return speed;
}


void Snake::Snake_Node::resetSpeed() {
    speed = 2.f;
}

