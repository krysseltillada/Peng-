#pragma once
#ifndef SCORE_HEADER
#define SCORE_HEADER

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

class Score {
public:
    Score ();

    ~Score ();

    Score &setScoreSize (const int &);
    Score &setTextPosition (const int &, const int &);

    Score &increase ();
    Score &decrease ();

    Score &reset ();

    sf::Text getScore () const;
    Score &updateScore ();

private:

    sf::Font fontStyle;
    sf::Text textScore;

    unsigned score, characterSize;
};

#endif // SCORE_HEADER
