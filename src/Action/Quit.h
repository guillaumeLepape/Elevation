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
        );

        void triggerAction() override;
};

#endif