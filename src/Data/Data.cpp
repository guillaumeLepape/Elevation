/*!
    * \file Data.cpp
*/

#include "Data.h"

#include <fstream>

Data::Data( const int& levelNumber, const std::string& fileName ) :
    levelNumber_( levelNumber )
{
    std::string path = "../data/";
    
    if ( levelNumber == 0 ) 
    {
        path += "Introduction/";
    }
    else
    {   
        path += "Level" + std::to_string(levelNumber) + "/";
    }

    path += fileName;
    path += ".json";
    
    // open json file
    std::ifstream messageFile( path, std::ifstream::binary );

    // check if the file is opened
    assert( messageFile.is_open() );

    // read jsonfile 
    messageFile >> jsonObject_;

    messageFile.close();  
}