/*!
    * \file Level10.cpp
*/

#include "Level10.h"

#include <iostream>

#include "HeaderWriter.h"

#include "Languages.h"

void Level10::startLevel()
{
    HeaderWriter headerWriter( data::Level10::nameLevel, data::Level10::hour, data::Level10::minut );
    headerWriter.writeHeader();

    Level::endOfLevel();
    std::cout << "\n";
}