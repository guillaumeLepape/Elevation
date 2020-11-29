#include "Player.h"

#include <iostream>

Player::Player() : 
    pseudo_("Joueur"),
    nbLifePoints_(100)
{

}

void Player::printState()
{
    std::cout << "\n" << pseudo_;
    std::cout << "\n" << nbLifePoints_;
    std::cout << "\n";
}