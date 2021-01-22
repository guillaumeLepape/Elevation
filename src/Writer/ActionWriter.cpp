/*!
    * \file ActionWriter.cpp
*/

#include "ActionWriter.h"

#include "Pause.h"

#include <cpp-terminal/terminal.h>

ActionWriter::ActionWriter
( 
    const std::string& statement, 
    const std::string& result
) :
    statement_( statement),
    result_( result )
{

}

void ActionWriter::writeStatement() const
{        
        std::cout << "\n " 
            << Term::color( Term::fg::black )
            << Term::color( Term::bg::yellow )
            << Term::color( Term::style::bold ) 
            << statement_
            << Term::color( Term::fg::reset )
            << Term::color( Term::bg::reset )
            << Term::color( Term::style::reset ) 
            << " : ";    
}

void ActionWriter::writeResult() const 
{
    Pause::pause();
    std::cout << "\n " 
        << Term::color( Term::fg::yellow )
        << Term::color( Term::style::bold ) 
        << result_
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );
}