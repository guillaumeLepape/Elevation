#ifndef HEADER_WRITER_H
#define HEADER_WRITER_H

/*!
    * \file HeaderWriter.h
*/

#include "Writer.h"

class HeaderWriter
{
    private:
        HeaderData headerData_;

    public:
        HeaderWriter( const nlohmann::json& jsonObject );
        HeaderWriter( const std::string& nameLevel, const int& hour, const int& minut );
        HeaderWriter( const HeaderData& headerData );
        HeaderWriter( const std::string& folderFromRoot, const std::string& fileName );

        void writeHeader() const;
};

#endif