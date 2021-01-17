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

        Nothing
        (
            const std::tuple<bool, std::string> statement,
            const std::tuple<bool, std::string> result
        ) :
            Action( statement, result )
        {
            
        }

        void triggerAction() override
        {

        }
};

#endif