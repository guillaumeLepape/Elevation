#include <iostream>
#include <string>

#include "Selection/Selection.h"
#include "Action/Quit.h"
#include "Action/StartGame.h"

int main()
{
    Action *startGame = new StartGame();
    Action *quit = new Quit();

    Selection::newSelection( 
        "Menu",
        { startGame, quit } 
    );

    return 0;
}
