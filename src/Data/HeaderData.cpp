/*!
    * \file HeaderData.cpp
*/

#include "HeaderData.h"

HeaderData::HeaderData( const int& levelNumber ) :
    Data( levelNumber, "header" )
{
    readData();
}

void HeaderData::readData()
{
    nameLevel_ = (std::string) jsonObject_["nameLevel"];
    hour_ = jsonObject_["hour"];
    minut_ = jsonObject_["minut"];
}
