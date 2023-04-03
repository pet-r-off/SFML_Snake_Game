#include "Game.h"


Game::Game()
    : mWindow(sf::VideoMode(800, 480),"Snake Game"),
    gameOverText("Game Over", sf::Color::Red, 50, sf::Vector2f(280.f, 200.f)),
    restartText("RESTART", sf::Color::Red, 30, sf::Vector2f(350.f, 350.f)),
    timeSinceLastMove(sf::Time::Zero),
    gameScore() {
    std::cout << "Game Constr" << std::endl;
}


Game::~Game() {std::cout << "Game Destr" << std::endl;}


void Game::run() {
    while(this->mWindow.isOpen()) {
        sf::Time dt = this->mClock.restart();
        this->timeSinceLastMove += dt;

        this->processEvents();
        this->isColliding(this->mSnake.snakeNodes.front().objectRect, this->mFruit.objectRect);
        this->wallCollider();
        this->update();
        this->render();
    }
}


void Game::processEvents() {
    while (this->mWindow.pollEvent(mEvent)) {
        switch (mEvent.type) {
            case sf::Event::EventType::Closed:
                this->mWindow.close();
                break;

            case sf::Event::EventType::KeyPressed:
                handleInputKey(mEvent.key.code);
                break;

            case sf::Event::EventType::MouseButtonPressed:
                handleInputMouse(sf::Vector2f(sf::Mouse::getPosition(this->mWindow)));
                break;
        }
    }
}


void Game::update() {
    this->mSnake.handle_direction(this->timeSinceLastMove);
    this->gameScore.updateText("Score: " + std::to_string(this->gameScore.getScore()) + "  Record: " + std::to_string(this->gameScore.getRecord()));
}


void Game::render() {
    this->mWindow.clear();

    if (this->gameState == gameStates::MENU){
        this->mMenu.run(this->mWindow);
    }
    else if (this->gameState == gameStates::GAME){
        this->mWindow.draw(this->mBackground.backgrndSprite);
        this->draw_walls();
        this->mWindow.draw(this->mFruit.objectRect);
        this->mWindow.draw(this->gameScore.getText());
        this->draw_snake();
    }
    else if (this->gameState == gameStates::GAME_OVER){
        this->mWindow.draw(this->mBackground.backgrndSprite);
        this->mWindow.draw(this->gameOverText.getText());
        this->mWindow.draw(this->restartText.getText());
    }

    this->mWindow.display();
}










/////////////////////////////////////////////////////////////////////////////////////
//      STATE METHODS
/////////////////////////////////////////////////////////////////////////////////////


void Game::handleInputKey(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::Escape) {
        this->gameScore.setRecord();
        this->mWindow.close();
    }


    if(key == sf::Keyboard::W){
        this->mSnake.snakeMovements = Direction::UP;
    }
    if(key == sf::Keyboard::S){
        this->mSnake.snakeMovements = Direction::DOWN;
    }
    if(key == sf::Keyboard::D){
        this->mSnake.snakeMovements = Direction::RIGHT;
    }
    if(key == sf::Keyboard::A){
        this->mSnake.snakeMovements = Direction::LEFT;
    }
}


void Game::handleInputMouse(sf::Vector2f cursor_pos) {
    if (this->gameState == gameStates::MENU){
        if (sf::IntRect(380, 120, 50, 50).contains(int(cursor_pos.x), int(cursor_pos.y))){
            this->gameState = gameStates::GAME;
        }
        if (sf::IntRect(380, 300, 50, 50).contains(int(cursor_pos.x), int(cursor_pos.y))){
            this->mWindow.close();
        }
    }
    if (this->gameState == gameStates::GAME_OVER){
        if (sf::IntRect(380, 350, 50, 50).contains(int(cursor_pos.x), int(cursor_pos.y))){
            this->gameState = gameStates::GAME;
            this->gameScore.setScore(0);
            this->mSnake.restart();
        }
    }
}


void Game::isColliding(sf::RectangleShape &snake_rect, sf::RectangleShape &fruit_rect) {
    sf::FloatRect snakeRect = snake_rect.getGlobalBounds();
    sf::FloatRect fruitRect = fruit_rect.getGlobalBounds();

    if (snakeRect.intersects(fruitRect)) {
        // DEBUG //std::cout << "Snake -> Fruit Colliding" << std::endl;
        this->mFruit.new_pos();
        this->mSnake.add_tail();
        this->gameScore.increaseScore();
    }
}


bool Game::isColliding(sf::RectangleShape &wall_rect) {
    sf::FloatRect snakeRect = this->mSnake.snakeNodes.front().objectRect.getGlobalBounds();
    sf::FloatRect wallRect = wall_rect.getGlobalBounds();

    if (snakeRect.intersects(wallRect)) {
        return true;
    }
}


void Game::draw_snake() {
    for (auto &snakeNode: this->mSnake.snakeNodes) {
        this->mWindow.draw(snakeNode.objectRect);
    }
}


void Game::draw_walls() {
    for (auto &wallNodes : this->mWalls.wall_nodes) {
        this->mWindow.draw(wallNodes.objectRect);
    }
}


void Game::wallCollider() {
    for (auto &wallNodes : this->mWalls.wall_nodes) {
        if (this->isColliding(wallNodes.objectRect)){
            this->gameState = gameStates::GAME_OVER;
            this->mSnake.stop();
        }
    }
}

