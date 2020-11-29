#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
    private:
        std::string pseudo_;
        int nbLifePoints_;

    public:
        Player();
        void printState();
        const std::string& pseudo() const { return pseudo_; }
        void setPseudo( const std::string& pseudo ) { pseudo_ = pseudo; } 
};  

#endif