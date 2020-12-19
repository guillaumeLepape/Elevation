#ifndef QUIT_H
#define QUIT_H

/*!
    * \file Quit.h
*/

#include "Action.h"

class Quit : public Action
{
    public:
        Quit() : Action( -1, "quit", false ){}
        void triggerAction() const override  
        { 
            std::cout << "\n Fin du jeu";
            std::cout << "\n"; 
        }
};

#endif