/*!
    * \file main.cpp
*/

#include <iostream>

#include "StartGame.h"
#include "LoadGame.h"
#include "Quit.h"

#include "Selection.h"

#include "Languages.h"

#include "Rules.h"

int main( int argc, char* argv[] )
{
    const Options options( argc, argv );

    // If user selected -h option, print options descriptions 
    // and exit program
    if ( options.help_ )
    {
        std::cout << options.desc_ << "\n";
        return 0;
    }
    
    Rules::displayRules( options );
    
    // // Start the game at the begining
    StartGame startGame( data::Menu::statementStartGame, data::Menu::resultStartGame, options );
    // // Load previous game from results.json file
    LoadGame loadGame( data::Menu::statementLoadGame, data::Menu::resultLoadGame, options ); 
    // // Quit the game
    Quit quit( data::Menu::statementQuit, data::Menu::resultLoadGame ); 

    Selection::select(  
        { &startGame, &loadGame, &quit },
        data::Menu::titleStartGameMenu
    );

    return 0;
}
