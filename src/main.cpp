/*!
    * \file main.cpp
*/


#include "Selection/Selection.h"
#include "Action/Quit.h"
#include "Action/StartGame.h"
#include "Writer/Rules.h"

#include "Writer/Writer.h"

// #include "Getter/GetFromTerminal.h"

int main()
{
    Rules::displayRules();

    std::unique_ptr<Action> startGame( new StartGame() );
    std::unique_ptr<Action> quit( new Quit() );

    Selection::select( 
        -1, 
        0, 
        { startGame.get(), quit.get() } 
    );

    return 0;
}
