/*!
    * \file main.cpp
*/
#include "LoadGame.h"

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
    
    std::unique_ptr<Action> startGame
    ( 
        new StartGame
        ( 
            data::Menu::statementStartGame, 
            data::Menu::resultStartGame, 
            options 
        ) 
    );
    std::unique_ptr<Action> loadGame
    ( 
        new LoadGame
        ( 
            data::Menu::statementLoadGame, 
            data::Menu::resultLoadGame, 
            options 
        ) 
    );
    std::unique_ptr<Action> quit
    ( 
        new Quit
        (
            data::Menu::statementQuit,
            data::Menu::resultLoadGame
        ) 
    );

    Selection::select(  
        { startGame.get(), loadGame.get(), quit.get() },
        data::Menu::titleStartGameMenu
    );

    return 0;
}
