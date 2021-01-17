#ifndef START_GAME_H
#define START_GAME_H

/*!
    * \file StartGame.h
*/

#include "LevelFactory.h"
#include "Id.h"

class StartGame : public Action
{
    private:
        Player player_;
        const Options& options_;

    public: 
        StartGame
        ( 
            const std::string& folderFromRoot, 
            const std::string& nameFile,
            const Options& options,
            const Player& player 
                = Player( "Joueur", Id::generateId(), 0 )
        ) : 
            Action( folderFromRoot, nameFile ),
            player_( player ),
            options_( options )
        {

        }

        StartGame
        (
            const std::tuple<bool, std::string>& statement,
            const std::tuple<bool, std::string>& result,
            const Options& options,
            const Player& player 
                = Player( "Joueur", Id::generateId(), 0 ) 
        ) : 
            Action( statement, result ),
            player_( player ),
            options_( options )
        {

        }

        void triggerAction() override
        {       
            int i = 0;
            for ( i = player_.nbLevelSuceeded(); i < 6; i++ )
            {
                std::unique_ptr<Level> level = LevelFactory::newLevel( &player_, i );

                level->startLevel( options_ );
            }

            WriteResults writeResults( &player_, data::Menu::statementSaveAndQuit, data::Menu::resultSaveAndQuit );
            writeResults.triggerAction();
        }
};

#endif