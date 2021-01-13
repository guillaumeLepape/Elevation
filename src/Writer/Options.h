#ifndef OPTIONS_H
#define OPTIONS_H

/*!
    * \file Options.h
*/

#include <boost/program_options.hpp>

class Options
{
    private:
        void initializeAttribute( int argc, char* argv[] );

    public:
        Options( int argc, char* argv[] );

        bool noRule_;
        bool help_;
        boost::program_options::options_description desc_;
};

#endif