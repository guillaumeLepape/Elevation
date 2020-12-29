/*!
    * \file TutorialData.cpp
*/

#include "TutorialData.h"

TutorialData::TutorialData
(
    const std::string& folderFromRoot,
    const std::string& fileName
) : 
    Data( folderFromRoot, fileName )
{
    readData();
}

void TutorialData::readData()
{
    name_ = jsonObject_["name"];

    for ( auto i = jsonObject_["tutorialStatement"].cbegin(); i != jsonObject_["tutorialStatement"].cend(); i++ )
    {
        tutorialStatement_.push_back( *i );
    }
}