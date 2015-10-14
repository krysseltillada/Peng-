#include "Score.hpp"

Score &Score::updateScore () {
    std::ostringstream toString;
    toString << score;

    textScore.setFont(fontStyle);
    textScore.setCharacterSize(characterSize);
    textScore.setString (toString.str ());

    return *this;
}

Score::Score () :
    score (0), characterSize (20) {
        try {
            if (!fontStyle.loadFromFile ("sansation.ttf"))
                throw std::string ("error loading file ");
        } catch (std::string e) {
            throw std::runtime_error (e);
        }
    }

Score::~Score () { }

Score &Score::setTextPosition (const int &tx, const int &ty) {
    textScore.setPosition (tx, ty);
    return *this;
}


Score &Score::setScoreSize (const int &ps) {
    characterSize = ps;
    return *this;
}

Score &Score::increase () {
    ++this->score;
    return *this;
}

Score &Score::decrease () {
    --this->score;
    return *this;
}

Score &Score::reset () {
    this->score = 0;
    return *this;
}

sf::Text Score::getScore () const {
    return this->textScore;
}


