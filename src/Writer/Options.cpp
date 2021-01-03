/*!
    * \file Options.cpp
*/

#include "Options.h"
#include <iostream>

Options::Options( int argc, char* argv[] ) : 
    noRule_(false), 
    help_(false), 
    desc_("Allowed options")
{
    initializeAttribute( argc, argv );
}

void Options::initializeAttribute( int argc, char* argv[] )
{
    try 
    {
        desc_.add_options()
        ("help,h", boost::program_options::bool_switch(&help_), "print usage message")
        ("rule,r", boost::program_options::bool_switch(&noRule_), "If this option is selected, the rules and tutorials are not printed");

        boost::program_options::variables_map vm;
        boost::program_options::store(
            boost::program_options::parse_command_line(argc, argv, desc_), 
            vm
        );
        boost::program_options::notify(vm);    
    }
    catch (std::exception& e) 
    {
        std::cerr << e.what() << "\n";
    }
}