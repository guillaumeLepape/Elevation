/*!
    * \file main.cpp
*/


#include "Selection.h"
#include "Quit.h"
#include "StartGame.h"
#include "Rules.h"

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
