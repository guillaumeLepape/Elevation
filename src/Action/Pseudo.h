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
        explicit Pseudo( Player* const player ) : 
            Action( "Comment t'apelles tu ?" ), player_(player)
        {

        }
        void triggerAction() const override 
        {
            std::cout << "\n Je ne souviens plus de mon prénom. Comment t'appelle tu ? ";
            std::string pseudo;
            std::cin >> pseudo; 
            player_->setPseudo(pseudo);
        }
};

#endif