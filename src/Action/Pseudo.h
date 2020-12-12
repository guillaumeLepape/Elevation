#ifndef PSEUDO_H
#define PSEUDO_H

/*!
    * \file Pseudo.h
*/

#include "Action.h"
#include "../color.h"

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
            Message message( "../messages/messagePseudo.json" );
            message.writeInConsole( player_, nullptr, 0 );
            std::cout << "\n " << BOLDCYAN << "Entrez votre pseudo : " << RESET;
            std::string pseudo;
            std::cin >> pseudo; 
            // std::cout << "\n";
            player_->setPseudo(pseudo);
        }
};

#endif