#ifndef ACTION_H
#define ACTION_H

#include <string>

class Action
{
    protected:
        std::string statement_;

    public:
        Action( const std::string& statement ) : statement_( statement ) {}
        virtual void triggerAction() const = 0;

        const std::string& statement() const { return statement_; }

        virtual ~Action() {}
};

#endif