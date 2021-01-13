#ifndef NOTHING_H
#define NOTHING_H

/*!
    * \file Nothing.h
*/

#include "Action.h"

class Nothing : public Action
{
    public:
        Nothing
        ( 
            const std::string& folderFromRoot,
            const std::string& nameFile 
        ) :
            Action( folderFromRoot, nameFile )
        {

        }

        void triggerAction() override
        {

        }
};

#endif