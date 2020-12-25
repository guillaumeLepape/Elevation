#ifndef START_GAME_H
#define START_GAME_H

/*!
    * \file StartGame.h
*/

#include <memory>

#include "LevelFactory.h"
#include "Id.h"
#include "ResultsData.h"
#include "Action.h"

class StartGame : public Action
{
    private:
        Player player_;

    public: 
        StartGame
        ( 
            const std::string& folderFromRoot, 
            const std::string& nameFile,
            const Result& result 
                = { "Joueur", Id::generateId(), 0 }
        ) : 
            Action( folderFromRoot, nameFile ),
            player_( result.pseudo_, result.id_, result.nbLevelSuceeded_ )
        {

        }

        void triggerAction() override
        {       
            int i = 0;
            for ( i = player_.nbLevelSuceeded(); i < 6; i++ )
            {
                std::unique_ptr<Level> level = LevelFactory::newLevel( &player_, i );

                level->startLevel();
            }

            ResultsData resultsData;
            resultsData.addResult( { player_.pseudo(), player_.id(), i-1 } );
            resultsData.writeData();
        }
};

#endif