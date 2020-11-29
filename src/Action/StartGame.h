#ifndef START_GAME_H
#define START_GAME_H

#include "Action.h"
#include "../Level/Level1.h"
#include "../Level/Level2.h"
#include "../Player/Player.h"
#include "../Message/Message.h"

class StartGame : public Action
{
    private: 
        std::string getPseudo() const
        {
            std::cout << "\n Je ne souviens plus de mon prénom. Comment t'appelle tu ? ";
            std::string pseudo;
            std::cin >> pseudo; 
            std::cout << "\n Bon d'accord " << pseudo << ", ça fera l'affaire.";
            std::cout << "\n";

            return pseudo;
        }

    public: 
        StartGame() : Action( "Commencer une partie" ) {}
        void triggerAction() const
        {
            Message( "../messages/messageStartTime.json" );

            const std::string pseudo = getPseudo();
            
            // Create Player instance
            Player player(pseudo);

            // Create Level 1 instance
            Level1 level1(player);

            // Start the first level
            level1.startLevel();

            Level2 level2(player);
            level2.startLevel();
        }
};

#endif