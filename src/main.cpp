/*!
    * \file main.cpp
*/


#include "StartGame.h"
#include "LoadGame.h"
#include "Quit.h"

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
    
    std::unique_ptr<Action> startGame( new StartGame( "data/Menu", "startGame", options ) );
    std::unique_ptr<Action> loadGame( new LoadGame( "data/Menu", "loadGame", options ) );
    std::unique_ptr<Action> quit( new Quit( "data/Menu", "quit" ) );

    Selection::select(  
        { startGame.get(), loadGame.get(), quit.get() },
        "data/Menu",
        "selection0"
    );

    return 0;
}
