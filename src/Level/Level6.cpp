/*!
    * \file Level6.h
*/

#include "Level6.h"

#include <iostream>

#include "HeaderWriter.h"
#include "MessageWriter.h"

#include "Languages.h"

void Level6::startLevel( const Options& options )
{
    HeaderWriter headerWriter( data::Level6::nameLevel, data::Level6::hour, data::Level6::minut );
    headerWriter.writeHeader();

    Level::endOfLevel();
    std::cout << "\n";
}