#include "Game.hpp"

int main ()
{
    Game peng;

    while (peng.getGameState ())
        peng.run ();


    return 0;
}
