#ifndef DEAD_H
#define DEAD_H

/*!
    * \file Dead.h
*/

#include "Action.h"

// forward declaration of Plug class
class Plug;

class Dead : public Action
{
    private:
        const Plug* const plug_;

    public:
        Dead
        (
            const Plug* const plug,
            const std::string& statement,
            const std::string& result
        );

        void triggerAction() override;
};

#endif