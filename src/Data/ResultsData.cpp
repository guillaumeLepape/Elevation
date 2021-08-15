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

ResultsData::~ResultsData() 
{
    for ( auto p = results_.cbegin(); p != results_.cend(); p++ )
    {
        delete *p;
    }
}

void ResultsData::readData()
{
    for ( auto i = jsonObject_.cbegin(); i != jsonObject_.cend(); i++ )
    {
        results_.push_back( Player::readJson( *i ) );
    }
}

void ResultsData::addResult( Player* const player )
{
    const int& id = player->id();
    results_.remove_if( [&id]( Player* const player_lambda ) { return player_lambda->id() == id; } );

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

    std::for_each( 
        std::cbegin(results_), 
        std::cend(results_), 
        [&jsonObjectOutput](const auto& res) { 
            nlohmann::json jsonPlayer = res->writeJson();
            jsonObjectOutput.push_back( jsonPlayer ); 
        } 
    );

    // read jsonfile 
    jsonFile << std::setw(4) << jsonObjectOutput;

    jsonFile.close();  
}