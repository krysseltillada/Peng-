#include "Ball.hpp"

Ball::Ball () :
    ballBounds (ball.getGlobalBounds()) { }

Ball::~Ball () { }

Ball &Ball::moveBall (const int & n) {
    deltaTime = gameClock.getElapsedTime ();
    ball_p.x += n * (deltaTime.asSeconds () * getSpeed ());
    ball.setPosition (ball_p.x, ball_p.y);
    gameClock.restart();
    return *this;
}

Ball &Ball::setY (const int &by) {
    this->ball_p.y = by;
    ball.setPosition (this->ball_p.x, this->ball_p.y);
    return *this;
}

Ball &Ball::setX (const int &bx) {
    this->ball_p.x = bx;
    ball.setPosition (this->ball_p.x, this->ball_p.y);
    return *this;
}

Ball &Ball::setRadius (const float &br) {
    this->ball.setRadius (br);
    return *this;
}

Ball &Ball::setSpeed (const float &bs) {
    this->speed = bs;
    return *this;
}

Ball &Ball::setColor (sf::Color bc) {
    this->ball.setFillColor (bc);
    return *this;
}

int Ball::getY () const {
    return this->ball_p.y;
}

int Ball::getX () const {
    return this->ball_p.x;
}

float Ball::getSpeed () const {
    return this->speed;
}

sf::CircleShape Ball::getObj () {
    return this->ball;
}

Ball &Ball::updateBounds () {
    ballBounds = ball.getGlobalBounds();
    return *this;
}

bool Ball::checkCollision (sf::FloatRect &pb) {
   if (ballBounds.intersects(pb)) {
    return true;
   } else {
       return false;
   }
}




