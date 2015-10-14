#pragma once
#ifndef GAME_HEADER
#define GAME_HEADER

#include "Fps.hpp"
#include "TimeInterval.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Score.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>
#include <stdexcept>
#include <random>

class Game {
public:
    Game ();
    ~Game ();

    void run ();
    void eventHandling ();
    void update ();
    void init ();
    void render ();
    void resetGame (const bool &, Paddle &, Paddle &, Ball &);

    bool getGameState ();


private:
    const std::string windowName;

    const int width;
    const int height;

    bool gameState, cState1 = false, cState2 = false, cwState1 = false, cwState2 = false, ifLaunch = false;

    Fps FpsCounter;

    sf::Clock gameClock;
    sf::Time deltaTime;

    sf::Vector2f currPosition;

    std::shared_ptr <sf::Font> sp_mmfontStyle = std::make_shared <sf::Font> ();
    std::shared_ptr <sf::Text> sp_mmText = std::make_shared <sf::Text> ();
    std::shared_ptr <sf::Text> sp_mmText2 = std::make_shared <sf::Text> ();

    const float PI = 3.14159265359;

    std::shared_ptr <Paddle> sp_paddle1 = std::make_shared <Paddle> ();
    std::shared_ptr <Paddle> sp_paddle2  = std::make_shared <Paddle> ();
    std::shared_ptr <Ball>   sp_ball    = std::make_shared <Ball> ();

    std::shared_ptr <Score> sp_playerScore1 = std::make_shared <Score> ();
    std::shared_ptr <Score> sp_playerScore2 = std::make_shared <Score> ();

    std::default_random_engine generator;

    std::shared_ptr <sf::RenderWindow> sp_window;
};



#endif // GAME_HEADER
