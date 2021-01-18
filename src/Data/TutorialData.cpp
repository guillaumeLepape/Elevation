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

TutorialData::TutorialData
(
    const std::string& title,
    const std::vector<std::string>& tutorialStatement
) :
    title_( title ),
    tutorialStatement_( tutorialStatement )
{

}

void TutorialData::readData()
{
    title_ = jsonObject_["title"];

    for ( auto i = jsonObject_["tutorialStatement"].cbegin(); i != jsonObject_["tutorialStatement"].cend(); i++ )
    {
        tutorialStatement_.push_back( *i );
    }
}