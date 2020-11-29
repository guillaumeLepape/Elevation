#ifndef QUIT_H
#define QUIT_H

#include "Action.h"

class Quit : public Action
{
    public:
        Quit() : Action( "Quitter" ) {}
        void triggerAction() const 
        { 
            std::cout << "Quitter le jeu" << std::endl; 
        }
};

#endif