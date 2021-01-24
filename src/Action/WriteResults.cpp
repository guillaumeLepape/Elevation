/*!
    * \file WriteResults.cpp
*/

#include "WriteResults.h"

#include <iostream>

#include "Player.h"
#include "ResultsData.h"

WriteResults::WriteResults
(
    const Player* const player,
    const std::string& statement,
    const std::string& result
) : 
    Action( statement, result ),
    player_( player )
{

}

void WriteResults::triggerAction()
{
    ResultsData resultsData;
    resultsData.addResult( *player_ );
    resultsData.writeData();

    actionWriter_.writeResult();
    std::cout << "\n";
}