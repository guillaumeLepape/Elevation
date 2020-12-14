#ifndef HEADER_WRITER_H
#define HEADER_WRITER_H

/*!
    * \file HeaderWriter.h
*/

#include "../Data/HeaderData.h"

class HeaderWriter
{
    private:
        const HeaderData& headerData_;

    public:
        HeaderWriter( const HeaderData& headerData );
        void writeHeader() const;
};

#endif