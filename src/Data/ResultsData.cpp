/*!
    * \file ResultsData.cpp
*/

#include "ResultsData.h"

#include <iomanip>

ResultsData::ResultsData() :
    Data( "results", "results" )
{
    readData();
}

void ResultsData::readData()
{
    for ( auto i = jsonObject_.cbegin(); i != jsonObject_.cend(); i++ )
    {
        results_.push_back( *(Player::readJson( *i )) );
    }
}

void ResultsData::addResult( const Player& player )
{
    const std::string& id = player.id();
    auto x = [&id]( const Player& player_lambda ) { return player_lambda.id() == id; };
    results_.remove_if( x );

    results_.push_back( player );
}

void ResultsData::writeData() const 
{
    std::string path = "results/results.json";
    
    // open json file
    std::ofstream jsonFile( path );

    // check if the file is opened
    assert( jsonFile.is_open() );

    nlohmann::json jsonObjectOutput;

    for ( auto r = results_.cbegin(); r != results_.cend(); r++ )
    {
        nlohmann::json jsonPlayer = r->writeJson();
        jsonObjectOutput.push_back( jsonPlayer );
    }

    // read jsonfile 
    jsonFile << std::setw(4) << jsonObjectOutput;

    jsonFile.close();  
}