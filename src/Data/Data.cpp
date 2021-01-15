/*!
    * \file Data.cpp
*/

#include "Data.h"

#include <fstream>

Data::Data( const nlohmann::json& jsonObject ) :
    jsonObject_( jsonObject )
{
    
}

Data::Data( const std::string& folderFromRoot, const std::string& fileName )
{
    openFile( folderFromRoot, fileName );
}

void Data::openFile( const std::string& folderFromRoot, const std::string& fileName ) 
{
    std::string path = folderFromRoot + "/" + fileName + ".json";
    
    // open json file
    std::ifstream messageFile( path, std::ifstream::binary );

    // check if the file is opened
    assert( messageFile.is_open() );

    // read jsonfile 
    messageFile >> jsonObject_;

    messageFile.close();  
}