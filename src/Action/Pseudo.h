#ifndef PSEUDO_H
#define PSEUDO_H

/*!
    * \file Pseudo.h
*/

#include "Action.h"

class Pseudo : public Action
{
    private: 
        Player* const player_;

    public:
        explicit Pseudo
        ( 
            Player* const player, 
            const std::string& folderFromRoot,
            const std::string& nameFile
        ) : 
            Action( folderFromRoot, nameFile ),
            player_(player)
        {

        }
        void triggerAction() const override 
        {
            actionWriter_.writeStatement( player_, nullptr );

            std::string pseudo;
            std::cin >> pseudo; 
            
            player_->setPseudo(pseudo);

            actionWriter_.writeResult( player_, nullptr );
        }
};

#endif