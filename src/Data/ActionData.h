#ifndef ACTION_DATA_H
#define ACTION_DATA_H

/*!
    * \file ActionData.h
*/

#include "Data.h"

class ActionData : public Data
{
    private:
        bool token_;        
        std::string statement_;

    public:
        ActionData( const int& levelNumber, const std::string& nameFile );

        void readData() override;

        const std::string& statement() const { return statement_; }
};

#endif