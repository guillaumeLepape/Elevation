#ifndef PLUG_H
#define PLUG_H

#include <string>

class Plug 
{
    private:
        std::string name_;
    public:
        explicit Plug( const std::string& name );
        const std::string& name() const { return name_; }
};

#endif