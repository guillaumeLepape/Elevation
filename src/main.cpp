/*!
    * \file main.cpp
*/


#include "Selection/Selection.h"
#include "Action/Quit.h"
#include "Action/StartGame.h"
#include "Writer/Rules.h"

int main()
{
    Rules::displayRules();

    std::unique_ptr<Action> startGame( new StartGame() );
    std::unique_ptr<Action> quit( new Quit() );

    Selection::select(
        "Menu",
        { startGame.get(), quit.get() } 
    );

    return 0;
}
