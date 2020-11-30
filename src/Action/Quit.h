#ifndef QUIT_H
#define QUIT_H

#include "Action.h"
#include <iostream>

class Quit : public Action
{
    public:
        Quit() : Action( "Quitter" ) {}
        void triggerAction() const override  
        { 
            std::cout << "Quitter le jeu" << std::endl; 
        }
};

#endif