#ifndef QUIT_H
#define QUIT_H

/*!
    * \file Quit.h
*/

#include "Action.h"

class Quit : public Action
{
    public:
        Quit() : Action( "Quitter" ) {}
        void triggerAction() const override  
        { 
            std::cout << "\n Fin du jeu";
            std::cout << "\n"; 
        }
};

#endif