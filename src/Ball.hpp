#pragma once
#ifndef BALL_HEADER
#define BALL_HEADER

#include <SFML/Graphics.hpp>

#include <iostream>

class Ball {
public:
    Ball ();
    ~Ball ();

    Ball &moveBall (const int &);

    Ball &setY (const int &);
    Ball &setX (const int &);
    Ball &setRadius (const float &);
    Ball &setSpeed (const float &);

    Ball &setColor (sf::Color) ;

    int getY () const;
    int getX () const;

    float getSpeed () const;

    sf::CircleShape getObj ();
    Ball &updateBounds ();

    bool checkCollision (sf::FloatRect &);
    bool checkWallCollision (const float &, const float &);

private:
    float radius, speed;

    sf::Vector2f ball_p;
    sf::CircleShape ball;
    sf::FloatRect ballBounds;
    sf::Clock gameClock;
    sf::Time deltaTime;
};

#endif // BALL_HEADER
