/*!
    * \file HeaderData.cpp
*/

#include "HeaderData.h"

HeaderData::HeaderData( const nlohmann::json& jsonObject ) : 
    Data( jsonObject )
{
    readData();
}

HeaderData::HeaderData( const std::string& folderFromRoot, const std::string& fileName ) :
    Data( folderFromRoot, fileName )
{
    readData();
}

HeaderData::HeaderData( const std::string& nameLevel, const int& hour, const int& minut ) :
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
