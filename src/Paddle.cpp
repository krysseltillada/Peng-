#include "Paddle.hpp"

Paddle::Paddle () :
    paddleBounds (paddle.getGlobalBounds ()) { }

Paddle::~Paddle () { }

Paddle &Paddle::setX (const int &px) {
    this->p_paddle.x = px;
    paddle.setPosition (this->p_paddle.x, this->p_paddle.y);
    return *this;
}

Paddle &Paddle::setY (const int &py) {
    this->p_paddle.y = py;
    paddle.setPosition (this->p_paddle.x, this->p_paddle.y);
    return *this;
}

Paddle &Paddle::setSize (const int &l, const int &w) {
    paddle.setSize (sf::Vector2f (l, w));
    return *this;
}

Paddle &Paddle::setColor (sf::Color c) {
    paddle.setFillColor (c);
    return *this;
}

Paddle &Paddle::setSpeed (const int &s) {
    this->velocity = s;
    return *this;
}


bool Paddle::Contains (const int &x, const int &y) {
    return (paddleBounds.contains (x, y)) ? true : false;
}

int Paddle::getX () const {
    return this->p_paddle.x;
}

int Paddle::getY () const {
    return this->p_paddle.y;
}

float Paddle::getSpeed () const {
    return this->velocity;
}

sf::RectangleShape &Paddle::getObj ()  {
    return this->paddle;
}

sf::FloatRect &Paddle::getBounds ()  {
    return this->paddleBounds;
}

Paddle &Paddle::updateBounds () {
    paddleBounds = paddle.getGlobalBounds();
    return *this;
}


