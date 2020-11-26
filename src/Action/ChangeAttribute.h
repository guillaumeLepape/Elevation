#ifndef CHANGE_ATTRIBUTE_H
#define CHANGE_ATTRIBUTE_H

#include "Action.h"

class ChangeAttribute : public Action
{
    private:
        int lambda;
    public:
        ChangeAttribute() {}
        void triggerAction() const
        {

        }
};

#endif