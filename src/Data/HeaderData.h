#ifndef HEADER_DATA_H
#define HEADER_DATA_H

/*!
    * \file HeaderData.h
*/

#include "Data.h"

class HeaderData : public Data
{
    private:
        std::string nameLevel_;
        int hour_;
        int minut_;

    public:
        HeaderData( const int& levelNumber );
        HeaderData( const std::string& nameLevel, const int& hour, const int& minut );

        void readData() override;

        const std::string& nameLevel() const { return nameLevel_; }
        const int& hour() const { return hour_; }
        const int& minut() const { return minut_; }
};

#endif