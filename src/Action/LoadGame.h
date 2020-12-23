#ifndef LOAD_GAME_H
#define LOAD_GAME_H

/*!
    * \file LoadGame.h
*/

#include "Action.h"

#include "color.h"

class LoadGame : public Action
{
    public:
        LoadGame
        ( 
            const std::string& folderFromRoot, 
            const std::string& nameFile 
        ) :
            Action( folderFromRoot, nameFile )
        {

        }

        void triggerAction() override
        {
            ResultsData resultsData;
            const auto& results = resultsData.results();

            if ( results.size() == 0 )
            {
                std::cout << "\n " << BOLDRED << "Aucune partie ne peut être chargé." << RESET;
                std::cout << "\n";
            }
            else
            {
                std::vector<Action*> actions;
                for ( int i = 0; i < results.size(); i++ )
                {
                    actions.push_back( new StartGame( "data/Menu", "loadGameSelection", results[i] ) );
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