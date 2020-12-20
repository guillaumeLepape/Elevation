#ifndef HEADER_WRITER_H
#define HEADER_WRITER_H

/*!
    * \file HeaderWriter.h
*/

#include "../Data/HeaderData.h"

class HeaderWriter
{
    private:
        HeaderData headerData_;

    public:
        HeaderWriter( const nlohmann::json& jsonObject );
        HeaderWriter( const HeaderData& headerData );
        HeaderWriter( const std::string& folderFromRoot, const std::string& fileName );

        void writeHeader() const;
};

#endif