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
    HeaderWriter headerWriter( data::Level7::nameLevel, data::Level7::hour, data::Level7::minut );

    Level::endOfLevel();
    std::cout << "\n";
}