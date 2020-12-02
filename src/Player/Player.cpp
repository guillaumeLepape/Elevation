#include "Player.h"

#include <iostream>

Player::Player() : 
    pseudo_("Joueur"),
    nbLifePoints_(100),
    money_(200),
    dead_(false)
{

}

void Player::printState()
{
    std::cout << "\n" << pseudo_;
    std::cout << "\n" << nbLifePoints_;
    std::cout << "\n" << money_;
    std::cout << "\n";
}