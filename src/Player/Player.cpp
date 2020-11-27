#include "Player.h"

#include <iostream>

Player::Player( const std::string& pseudo ) : 
    pseudo_(pseudo),
    nbLifePoints_(100)
{

}

void Player::printState()
{
    std::cout << "\n" << pseudo_;
    std::cout << "\n" << nbLifePoints_;
    std::cout << "\n";
}