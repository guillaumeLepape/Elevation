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

    std::unique_ptr<Action> startGame( new StartGame( "data/Menu", "startGame" ) );
    std::unique_ptr<Action> quit( new Quit( "data/Menu", "quit" ) );

    Selection::select(  
        { startGame.get(), quit.get() },
        "data/Menu",
        "selection0"
    );

    return 0;
}
