#ifndef PLUG_H
#define PLUG_H

/*!
    * \file Plug.h
*/

#include <string>

class Plug 
{
    private:
        const std::string name_;
        const int price_;
        int lifePoints_;

    public:
        explicit Plug( const std::string& name, const int& price, const int& lifePoints = 100 );
        const std::string& name() const { return name_; }
        const int& price() const { return price_; }

        const int& lifePoints() const { return lifePoints_; }
        void decreaseLifePoints( const int& lifePoints) { lifePoints_ -= lifePoints; } 
};

#endif