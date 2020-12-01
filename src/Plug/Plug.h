#ifndef PLUG_H
#define PLUG_H

#include <string>

class Plug 
{
    private:
        std::string name_;
        int price_;
    public:
        explicit Plug( const std::string& name, const int& price );
        const std::string& name() const { return name_; }
        const int& price() const { return price_; }
};

#endif