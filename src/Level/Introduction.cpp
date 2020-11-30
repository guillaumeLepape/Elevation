#include "Introduction.h"

#include "../Message/Message.h"

#include <iostream>

void Introduction::getPseudo() const
{
    std::cout << "\n Je ne souviens plus de mon prénom. Comment t'appelle tu ? ";
    std::string pseudo;
    std::cin >> pseudo; 
    player_->setPseudo(pseudo);
    std::cout << "\n " << player_->pseudo() 
        << " : Bon d'accord " 
        << player_->pseudo() 
        << ", ça fera l'affaire.";
    std::cout << "\n";
}

void Introduction::startLevel()
{
    Message( "../messages/messageStartTime.json", player_, nullptr );

    getPseudo();
}