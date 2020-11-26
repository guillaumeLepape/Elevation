#ifndef ACTION_H
#define ACTION_H

class Action
{
    public:
        Action();
        virtual void triggerAction() const = 0;
};

#endif