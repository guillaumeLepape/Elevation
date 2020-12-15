/*!
    * \file HeaderWriter.cpp
*/

#include "HeaderWriter.h"

#include <iomanip>

#include "Pause.h"
#include "../color.h"

HeaderWriter::HeaderWriter( const HeaderData& headerData ) :
    headerData_( headerData )
{

}

void HeaderWriter::writeHeader() const
{
    Pause::pause();

    // print level name
    std::cout << "\n " << REDSIDEBAR << BOLDWHITE << headerData_.nameLevel() << RESET;
    std::cout << "\n" << BOLDBLACK << "========" << RESET;

    // print the hour
    std::cout << "\n " << BOLDWHITE;
    std::cout << std::setfill('0') << std::setw(2) << headerData_.hour();
    std::cout << "h";
    std::cout << std::setfill('0') << std::setw(2) << headerData_.minut();
    std::cout << RESET;
    std::cout << "\n" <<  BOLDBLACK << "========" << RESET;
}