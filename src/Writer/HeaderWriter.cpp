/*!
    * \file HeaderWriter.cpp
*/

#include "HeaderWriter.h"

#include <iomanip>

#include "Pause.h"

#include <cpp-terminal/terminal.h>

HeaderWriter::HeaderWriter( const nlohmann::json& jsonObject ) :
    headerData_( jsonObject )
{

}

HeaderWriter::HeaderWriter( const HeaderData& headerData ) :
    headerData_( headerData )
{

}

HeaderWriter::HeaderWriter( const std::string& folderFromRoot, const std::string& fileName ) :
    headerData_( folderFromRoot, fileName )
{

}

void HeaderWriter::writeHeader() const
{
    Pause::pause();

    // print level name
    std::cout << "\n " 
        << Term::color( Term::bg::red )
        << Term::color( Term::style::bold ) 
        << headerData_.nameLevel() 
        << Term::color( Term::bg::reset )
        << Term::color( Term::style::reset );
        
    std::cout << "\n"
        << Term::color( Term::fg::black )
        << Term::color( Term::style::bold ) 
        << "========" 
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset ); 

    // print the hour
    std::cout << "\n " << Term::color( Term::style::bold );
    std::cout << std::setfill('0') << std::setw(2) << headerData_.hour();
    std::cout << "h";
    std::cout << std::setfill('0') << std::setw(2) << headerData_.minut();
    std::cout << Term::color( Term::style::reset );

    std::cout << "\n" 
        << Term::color( Term::fg::black )
        << Term::color( Term::style::bold )
        << "========" 
        << Term::color( Term::fg::reset )
        << Term::color( Term::style::reset ); 
}