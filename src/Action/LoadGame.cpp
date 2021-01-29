/*!
    * \file LoadGame.cpp
*/

#include "LoadGame.h"

#include "ResultsData.h"
#include "Selection.h"
#include "Languages.h"
#include "StartGame.h"
#include "Options.h"

#include <cpp-terminal/terminal.h>


LoadGame::LoadGame
(
    const std::string& statement,
    const std::string& result,
    const Options& options
) :
    Action( statement, result ),
    options_( options )
{

}

void LoadGame::triggerAction()
{
    ResultsData* const resultsData = new ResultsData();
    const auto& results = resultsData->results();

    if ( results.size() == 0 )
    {
        std::cout << "\n " 
            << Term::color( Term::bg::red )
            << Term::color( Term::style::bold ) 
            << "Aucune partie ne peut etre chargé." 
            << Term::color( Term::bg::reset )
            << Term::color( Term::style::reset );
        
        std::cout << "\n";

        delete resultsData;
    }
    else
    {
        std::vector<Action*> actions;
        for ( auto r = results.cbegin(); r != results.cend(); r++ )
        {                
            Action* startGame = new StartGame
            ( 
                data::Menu::statementChooseLoadedGame( (*r)->name(), (*r)->nbLevelSuceeded() ), 
                data::Menu::resultChooseLoadedGame, 
                options_, 
                *r, 
                resultsData
            );   

            actions.push_back( startGame );
        }

        int result = Selection::select(
            actions,
            data::Menu::titleLoadGameMenu
        );     
    }
}