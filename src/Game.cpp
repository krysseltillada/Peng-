#include "Game.hpp"
#include "Paddle.hpp"

Game::Game () :
    windowName (std::string ("")), width (800), height (600), gameState (true), sp_window (std::make_shared <sf::RenderWindow> (sf::VideoMode (width, height), windowName)) { }

Game::~Game () { }

void Game::init () {
     try {
        if (!sp_mmfontStyle->loadFromFile ("sansation.ttf"))
                throw std::string ("error loading file sansation.ttf");

        } catch (std::string e) {
            std::runtime_error what(e);
        }

    sp_mmText->setFont (*sp_mmfontStyle);
    sp_mmText->setCharacterSize (20);
    sp_mmText->setString ("Press any key to play or esc to exit");
    sp_mmText->setPosition (190, 300);

    sp_mmText2->setFont (*sp_mmfontStyle);
    sp_mmText2->setCharacterSize (200);
    sp_mmText2->setString ("Peng");
    sp_mmText2->setPosition (190, 100);

    sp_paddle1->setX (30).setY (height / 2).setColor (sf::Color::White).setSize (9, 90).setSpeed (500);
    sp_paddle2->setX (760).setY (height / 2).setColor (sf::Color::White).setSize (9, 90).setSpeed (500);
    currPosition.x = width / 2;
    currPosition.y = height / 2;
    sp_ball->setX (currPosition.x).setY (currPosition.y).setColor (sf::Color::White).setRadius (10).setSpeed (400);

    sp_playerScore1->setScoreSize (100);
    sp_playerScore1->setTextPosition (200, 20);

    sp_playerScore2->setScoreSize (100);
    sp_playerScore2->setTextPosition (550, 20);


    while (sp_window->isOpen ()) {
            FpsCounter.update ();
            deltaTime = gameClock.getElapsedTime ();
            eventHandling ();
            update ();
            render ();
            gameClock.restart ();
            std::cout << FpsCounter.getFps () << std::endl;
            system ("cls");
    }
}

void Game::run () {
    init ();
}

void Game::eventHandling () {
    sf::Event getEvents;

    while (sp_window->pollEvent (getEvents)) {
        if (getEvents.type == sf::Event::Closed) {
            sp_window->close ();
            gameState = false;
        }

            if (getEvents.type == sf::Event::TextEntered) {
                char keyInput = static_cast <char> (getEvents.text.unicode);
                float prevY = 0.0f;

                if (keyInput == 'w' || keyInput == 'W') {
                        if (!sp_paddle1->Contains (30, 0)) {
                                prevY = sp_paddle1->getY ();
                                sp_paddle1->setY ( prevY -= deltaTime.asSeconds () * sp_paddle1->getSpeed ());
                                sp_paddle2->setY ( prevY -= deltaTime.asSeconds () * sp_paddle2->getSpeed ());
                        }
                }

                else if (keyInput == 's' || keyInput == 'S') {
                        if (!sp_paddle1->Contains (30, 640)) {
                                prevY = sp_paddle1->getY ();
                                sp_paddle1->setY ( prevY += deltaTime.asSeconds () * sp_paddle1->getSpeed ());
                                sp_paddle2->setY ( prevY += deltaTime.asSeconds () * sp_paddle1->getSpeed ());
                        }
                } else if (static_cast <int> (keyInput) == 27) {
                    sp_window->close ();
                    gameState = false;
                }
                else {
                    ifLaunch = true;
                }
            }

            if (getEvents.type == sf::Event::MouseMoved) {
                std::cout << "mouse x: " << getEvents.mouseMove.x << " " << " mouse y: " << getEvents.mouseMove.y << std::endl;
            }

    }

}

void Game::update () {
    sp_playerScore1->updateScore ();
    sp_playerScore2->updateScore ();
    sp_ball->updateBounds ();
    sp_paddle2->updateBounds ();
    sp_paddle1->updateBounds ();

    if (ifLaunch) {

     if (sp_ball->getX () >= 800) {
            sp_playerScore1->increase ();
            resetGame (ifLaunch, *sp_paddle1, *sp_paddle2, *sp_ball);
        }

        if (sp_ball->getX () <= 0) {
            sp_playerScore2->increase ();
            resetGame (ifLaunch, *sp_paddle1, *sp_paddle2, *sp_ball);
        }

        if (sp_ball->checkCollision (sp_paddle1->getBounds ())) {
                std::cout << "paddle1" << std::endl;

            cState1 = true;
            cState2 = false;
            cwState1 = false;
            cwState2  = false;

            /*
            ifCollide = true;
            ifCollide2 = false;
            wallCollide = false;
            wallCollide2 = false;
            */
        } else if (sp_ball->checkCollision (sp_paddle2->getBounds ())) {

                std::cout << "paddle2 " << std::endl;

            cState2 = true;
            cState1 = false;
            cwState1 = false;
            cwState2 = false;

            /*
            ifCollide2 = true;
            ifCollide = false;
            wallCollide = false;
            wallCollide2 = false;
            */
        }

        if (cState1) {
            currPosition.x = sp_ball->getX ();
            currPosition.y = sp_ball->getY ();

            currPosition.x += deltaTime.asSeconds () * sp_ball->getSpeed ();
            currPosition.y -= deltaTime.asSeconds () * sp_ball->getSpeed ();

            /*
            ball_p.x += deltaTime * velocity;
            ball_p.y -= deltaTime * velocity;
            */
        }
        else if (cState2) {
            currPosition.x = sp_ball->getX ();
            currPosition.y = sp_ball->getY ();

            currPosition.x -= deltaTime.asSeconds () * sp_ball->getSpeed ();
            currPosition.y += deltaTime.asSeconds () * sp_ball->getSpeed ();

            /*

            ball_p.x -= deltaTime * velocity;
            ball_p.y += deltaTime * velocity;
            */
        }
        else if (!(cState1 && cwState1 && cState2 )) {
            if (!cwState2) {
                    std::cout << "else" << std::endl;
                currPosition.x = sp_ball->getX ();
                currPosition.x += deltaTime.asSeconds () * sp_ball->getSpeed ();

                /*
                ball_p.x += deltaTime * velocity;
                */
            }
        }

        if (sp_ball->getY () <= 0) {
            cwState1 = true;
            cState1 = false;
            cState2 = false;
            cwState2 = false;
        } else if (sp_ball->getY () >= 600) {
            cwState2 = true;
            cwState1 = false;
            cState2 = false;
            cState1 = false;

            /*

            wallCollide2 = true;
            wallCollide = false;
            ifCollide2 = false;
            ifCollide = false; /// 50 / / 2
            */
        } else if (sp_ball->getY () <= 50 && sp_ball->getX () <= 2) {
            std::cout << "hit" << std::endl;
            exit (0);
            cwState2 = false;
            cwState1 = true;
            cState2 = false;
            cState1 = false;
        }

        if (cwState1) {
                currPosition.x = sp_ball->getX ();
                currPosition.y = sp_ball->getY ();

                currPosition.x += deltaTime.asSeconds () * sp_ball->getSpeed ();
                currPosition.y += deltaTime.asSeconds () * sp_ball->getSpeed ();

                std::cout << "true2" << std::endl;
                /*
                ball_p.x += deltaTime * velocity;
                ball_p.y += deltaTime * velocity;
                */
        }

        if (cwState2) {
            currPosition.x = sp_ball->getX ();
            currPosition.y = sp_ball->getY ();

            currPosition.x -= deltaTime.asSeconds () * sp_ball->getSpeed ();
            currPosition.y -= deltaTime.asSeconds () * sp_ball->getSpeed ();

                std::cout << "true3" << std::endl;

            /*
            ball_p.x -= deltaTime * velocity;
            ball_p.y -= deltaTime * velocity;
            */
        }


        sp_ball->setX (currPosition.x).setY (currPosition.y);

        std::cout <<  "x: " << sp_ball->getX () << " " << sp_ball->getY () << std::endl;

    }
}

void Game::render () {
    if (ifLaunch) {
    sp_window->draw (sp_playerScore1->getScore());
    sp_window->draw (sp_playerScore2->getScore());
    sp_window->draw (sp_paddle1->getObj());
    sp_window->draw (sp_paddle2->getObj());
    sp_window->draw (sp_ball->getObj ());
    sp_window->display ();
    sp_window->clear ();
    } else {
        sp_window->draw (*sp_mmText2);
        sp_window->draw (*sp_mmText);
        sp_window->display ();
        sp_window->clear ();
    }

}

bool Game::getGameState () {
    return this->gameState;
}

void Game::resetGame (const bool &state, Paddle &paddle1, Paddle &paddle2, Ball &ball) {
    cState1 = false; cState2 = false; cwState1 = false; cwState2 = false;
    paddle1.setX (30).setY (height / 2);
    paddle2.setX (760).setY (height / 2);
    ball.setX (width / 2).setY (height / 2);
    currPosition.y = height / 2;
    ifLaunch = state;
}

