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
    // checking if the result already exist or not by comparing the id
    bool exist = false;
    
    for ( int i = 0; i < results_.size(); i++ )
    {
        if ( result.id_ == results_[i].id_ )
        {
            exist = true;
        }
    }

    // if result is not in the global results, add it
    if ( !exist )
        results_.push_back( result );
}

void ResultsData::writeData() const 
{
    std::string path = "../results/results.json";
    
    // open json file
    std::ofstream jsonFile( path );

    // check if the file is opened
    assert( jsonFile.is_open() );

    nlohmann::json jsonObjectOutput;

    for ( int r = 0; r < results_.size(); r++ )
    {
        jsonObjectOutput[r]["pseudo"] = results_[r].pseudo_;
        jsonObjectOutput[r]["id"] = results_[r].id_;
        jsonObjectOutput[r]["nbLevelSuceeded"] = results_[r].nbLevelSuceeded_;
    }

    // read jsonfile 
    jsonFile << jsonObjectOutput;

    jsonFile.close();  
}