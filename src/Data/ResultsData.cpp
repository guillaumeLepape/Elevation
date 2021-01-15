/*!
    * \file ResultsData.cpp
*/

#include "ResultsData.h"

ResultsData::ResultsData() :
    Data( "results", "results" )
{
    readData();
}

void ResultsData::readData()
{
    for ( auto i = jsonObject_.cbegin(); i != jsonObject_.cend(); i++ )
    {
        Result result = 
        { 
            (*i)["pseudo"], 
            (*i)["id"], 
            (*i)["nbLevelSuceeded"] 
        };
        results_.push_back(result);
    }
}

void ResultsData::addResult( const Result& result )
{
    const std::string& id = result.id_;
    auto x = [&id]( const Result& r_lambda ) { return r_lambda.id_ == id; };
    results_.remove_if( x );

    results_.push_back( result );
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
        jsonObjectOutput.push_back( 
            { 
                { "pseudo", r->pseudo_ },
                { "id", r->id_ },
                { "nbLevelSuceeded", r->nbLevelSuceeded_ }
            }
        );
    }

    // read jsonfile 
    jsonFile << jsonObjectOutput;

    jsonFile.close();  
}