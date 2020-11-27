#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
    private:
        std::string pseudo_;
        int nbLifePoints_;

    public:
        Player( const std::string& pseudo );
        void printState();
};  

#endif