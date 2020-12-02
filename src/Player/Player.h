#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
    private:
        std::string pseudo_;
        int nbLifePoints_;
        int money_;

    public:
        Player();
        void printState();
        const std::string& pseudo() const { return pseudo_; }
        void setPseudo( const std::string& pseudo ) { pseudo_ = pseudo; } 
        void increaseMoney( const int& money ) { money_ += money; }
};  

#endif