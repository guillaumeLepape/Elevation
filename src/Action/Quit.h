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
            const std::string& folderFromRoot, 
            const std::string& nameFile
        ) : 
            Action( folderFromRoot, nameFile )
        {

        }

        void triggerAction() override  
        { 
            actionWriter_.writeResult( nullptr, nullptr );
        }
};

#endif