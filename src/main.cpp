/*!
    * \file main.cpp
*/


#include "Selection/Selection.h"
#include "Action/Quit.h"
#include "Action/StartGame.h"

int main()
{
    std::cout << "Appuyez sur Entrée pour passer au message suivant." << std::endl;

    std::unique_ptr<Action> startGame( new StartGame() );
    std::unique_ptr<Action> quit( new Quit() );

    Selection selectBeginGame;

    selectBeginGame.select(
        "Menu",
        { startGame.get(), quit.get() } 
    );

    return 0;
}
