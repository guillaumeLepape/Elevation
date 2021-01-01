/*!
    * \file ActionWriter.cpp
*/

#include "ActionWriter.h"

#include "Pause.h"
#include "Token.h"

#include <cpp-terminal/terminal.h>

ActionWriter::ActionWriter( const nlohmann::json& jsonObject ) :
    actionData_( jsonObject )
{

}

ActionWriter::ActionWriter( const ActionData& actionData ) :
    actionData_( actionData )
{

}

ActionWriter::ActionWriter( const std::string& folderFromRoot, const std::string& nameFile ) :
    actionData_( folderFromRoot, nameFile )
{

}

void ActionWriter::writeStatement() const
{        
        std::cout << "\n " 
            << Term::color( Term::fg::black )
            << Term::color( Term::bg::yellow )
            << Term::color( Term::style::bold ) 
            << actionData_.statement()
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
        << actionData_.result()
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset );
}