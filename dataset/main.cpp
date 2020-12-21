#include <set>
#include <string>
#include <fstream>

#include <iostream>

#include <nlohmann/json.hpp>

nlohmann::json readJsonFile( const std::string& path )
{    
    // open json file
    std::ifstream jsonFile( path, std::ifstream::binary );

    // check if the file is opened
    assert( jsonFile.is_open() );

    // declare json C++ object
    nlohmann::json jsonObject;

    // read jsonfile 
    jsonFile >> jsonObject;

    jsonFile.close();  

    return jsonObject;
}

void readListeDesPrenoms( std::set<std::string>& listFeminineName )
{
    nlohmann::json jsonObject = readJsonFile( "../dataset/liste_des_prenoms.json" );

    for ( auto i = jsonObject.cbegin(); i != jsonObject.cend(); i++ )
    {
        if ( ((std::string) (*i)["fields"]["sexe"]) == "F" )
        {
            std::string name = (std::string) (*i)["fields"]["prenoms"];

            listFeminineName.insert( name );
        }
    }
}

int main()
{
    std::set<std::string> listFeminineName;

    readListeDesPrenoms( listFeminineName );

    nlohmann::json jsonObject( listFeminineName );

    std::ofstream jsonFile( "../dataset/prenoms_feminins.json", std::ofstream::binary );

    jsonFile << jsonObject;

    jsonFile.close();

    return 0;
}

