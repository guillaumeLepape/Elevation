#ifndef LOAD_GAME_H
#define LOAD_GAME_H

/*!
    * \file LoadGame.h
*/

#include "StartGame.h"

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

        LoadGame
        (
            const std::tuple<bool, std::string>& statement,
            const std::tuple<bool, std::string>& result,
            const Options& options
        ) :
            Action( statement, result ),
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
                    << "Aucune partie ne peut etre chargé." 
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
                        data::Menu::statementChooseLoadedGame, 
                        data::Menu::resultChooseLoadedGame, 
                        options_, 
                        *r 
                    );                   
                    Player player = *r;
                    startGame->preTreatmentStatement( &player, nullptr );

                    actions.push_back( startGame );
                }

                Selection::select(
                    actions,
                    data::Menu::titleLoadGameMenu
                );
            }
        }
};

#endif