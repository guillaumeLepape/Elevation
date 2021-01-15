#ifndef LOAD_GAME_H
#define LOAD_GAME_H

/*!
    * \file LoadGame.h
*/

#include "Action.h"

#include <cpp-terminal/terminal.h>

class LoadGame : public Action
{
    private:
        const Options& options_;

    public:
        LoadGame
        ( 
            const std::string& folderFromRoot, 
            const std::string& nameFile,
            const Options& options
        ) :
            Action( folderFromRoot, nameFile ),
            options_( options )
        {

        }

        void triggerAction() override
        {
            ResultsData resultsData;
            const auto& results = resultsData.results();

            if ( results.size() == 0 )
            {
                std::cout << "\n " 
                    << Term::color( Term::bg::red )
                    << Term::color( Term::style::bold ) 
                    << "Aucune partie ne peut être chargé." 
                    << Term::color( Term::bg::reset )
                    << Term::color( Term::style::reset );
                
                std::cout << "\n";
            }
            else
            {
                std::vector<Action*> actions;
                for ( auto r = results.cbegin(); r != results.cend(); r++ )
                {
                    Action* startGame = new StartGame
                    ( 
                        "data/Menu", 
                        "loadGameSelection", 
                        options_, 
                        *r 
                    );                   
                    Player player( r->pseudo_, r->id_, r->nbLevelSuceeded_ );
                    startGame->preTreatmentStatement( &player, nullptr );

                    actions.push_back( startGame );
                }

                Selection::select(
                    actions,
                    "data/Menu",
                    "selection1"
                );
            }
        }
};

#endif