#ifndef QUIT_H
#define QUIT_H

/*!
    * \file Quit.h
*/

#include "Action.h"

class Quit : public Action
{
    public:
        Quit
        ( 
            const std::string& statement, 
            const std::string& result
        ) : 
            Action( statement, result )
        {

        }

        void triggerAction() override  
        { 
            actionWriter_.writeResult();
            std::cout << "\n";
            exit(0);
        }
};

#endif