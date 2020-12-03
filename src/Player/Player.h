#ifndef PLAYER_H
#define PLAYER_H

/*!
    * \file Player.h
*/

#include <string>

class Player
{
    private:
        std::string pseudo_;
        int nbLifePoints_;
        int money_;
        bool dead_;

    public:
        Player();
        void printState();

        const std::string& pseudo() const { return pseudo_; }
        void setPseudo( const std::string& pseudo ) { pseudo_ = pseudo; } 

        void increaseMoney( const int& money ) { money_ += money; }

        const bool& dead() const { return dead_; }
        void setDead( const bool& dead ) { dead_ = dead; }
};  

#endif