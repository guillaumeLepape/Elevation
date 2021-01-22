#ifndef DEAD_H
#define DEAD_H

/*!
    * \file Dead.h
*/

// forward declaration of Plug class
class Plug;

#include "Action.h"


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
        // {
            // if ( plug_->deadOrNot() )
            // {
            //     actionWriter_.writeResult();
            // }
        // };
};

#endif