/*!
    * \file HeaderData.cpp
*/

#include "HeaderData.h"

HeaderData::HeaderData( const int& levelNumber ) :
    Data( levelNumber, "header" )
{
    readData();
}

HeaderData::HeaderData
( 
    const std::string& nameLevel, 
    const int& hour, 
    const int& minut 
) : 
    Data(), 
    nameLevel_( nameLevel ),
    hour_( hour ),
    minut_( minut )
{

}

void HeaderData::readData()
{
    nameLevel_ = (std::string) jsonObject_["nameLevel"];
    hour_ = jsonObject_["hour"];
    minut_ = jsonObject_["minut"];
}
