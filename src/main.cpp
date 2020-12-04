/*!
    * \file main.cpp
*/


#include "Selection/Selection.h"
#include "Action/Quit.h"
#include "Action/StartGame.h"

int main()
{
    std::unique_ptr<Action> startGame( new StartGame() );
    std::unique_ptr<Action> quit( new Quit() );

    Selection selectBeginGame;

    std::cout << "\n Menu";
    selectBeginGame.select(
        { startGame.get(), quit.get() } 
    );

    return 0;
}
