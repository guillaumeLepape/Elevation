#include <iostream>
#include <string>

#include "Selection/Selection.h"
#include "Action/ChangeAttribute.h"
#include "Action/Quit.h"
#include "Action/StartGame.h"

int main()
{
    Action *startGame = new StartGame();
    Action *quit = new Quit();

    Selection::newSelection( 
        "Menu",
        { "Commencer une partie", "Quitter" }, 
        { startGame, quit } 
    );

    return 0;
}
