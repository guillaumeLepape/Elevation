/*!
    * \file SelectionData.cpp
*/

#include "SelectionData.h"

SelectionData::SelectionData( const int& levelNumber, const int& indexSelection ) :
    Data( levelNumber, "selection" + std::to_string( indexSelection ) )
{
    readData();
}

void SelectionData::readData() 
{
    title_ = jsonObject_["title"];
    for ( int i = 0; i < jsonObject_["propositions"].size(); i++ )
    {
        propositions_.push_back( jsonObject_["propositions"][i] );
    }
}