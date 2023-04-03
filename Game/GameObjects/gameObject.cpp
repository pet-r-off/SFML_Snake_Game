#include "gameObject.h"



gameObject::gameObject() : objectRect(sf::Vector2f(0.f, 0.f)) {
    this->objectRect.setSize(sf::Vector2f(this->height, this->width));
    this->objectRect.setPosition(0.f, 0.f);
    //std::cout << "gameObject Constr" << std::endl;
}


gameObject::gameObject(float pos_x_, float pos_y_) : objectRect(sf::Vector2f(pos_x_, pos_y_)) {
    this->objectRect.setSize(sf::Vector2f(this->height, this->width));
    this->objectRect.setPosition(pos_x_, pos_y_);
    //std::cout << "gameObject Constr" << std::endl;
}


gameObject::gameObject(const sf::Vector2f &position) : objectRect(position) {
    this->objectRect.setSize(sf::Vector2f(this->height, this->width));
    this->objectRect.setPosition(position);
    //std::cout << "gameObject Constr" << std::endl;
}


gameObject::~gameObject() {};//std::cout << "gameObject Destr" << std::endl;}


void gameObject::setWidth(const float new_width) {
    this->width = new_width;
}


void gameObject::setHeight(const float new_height) {
    this->height = new_height;
}

