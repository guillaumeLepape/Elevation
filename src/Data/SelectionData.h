#ifndef SELECTION_DATA_H
#define SELECTION_DATA_H

/*!
    * \file SelectionData.h
*/

#include "Data.h"

class SelectionData : public Data
{
    private:
        std::string title_;

    public:
        SelectionData( const int& levelNumber, const int& indexSelection );
        void readData() override;

        const std::string& title() const { return title_; }
};

#endif