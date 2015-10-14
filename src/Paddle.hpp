#pragma once
#ifndef PADDLE_HEADER
#define PADDLE_HEADER

#include <SFML/Graphics.hpp>

#include <iostream>

class Paddle {
public:
    Paddle ();
    ~Paddle ();

    Paddle &setX (const int &);
    Paddle &setY (const int &);
    Paddle &setSize (const int &, const int &);
    Paddle &setColor (sf::Color);
    Paddle &setSpeed (const int &);

    bool Contains (const int &, const int &);


    int getX () const;
    int getY () const;

    float getSpeed () const;

    sf::RectangleShape &getObj ();
    sf::FloatRect &getBounds ();

    Paddle &updateBounds ();

private:
    int length;
    int width;

    float velocity = 0.0f;

    sf::Color paddleColor;

    sf::RectangleShape paddle;

    sf::Vector2f p_paddle;
    sf::FloatRect paddleBounds;
};

#endif // PADDLE_HEADER
