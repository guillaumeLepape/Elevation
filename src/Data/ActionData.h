#ifndef ACTION_DATA_H
#define ACTION_DATA_H

/*!
    * \file ActionData.h
*/

#include "Data.h"

class ActionData : public Data
{
    private:
        bool tokenStatement_;        
        std::string statement_;

        bool tokenResult_;
        std::string result_;

    public:
        ActionData( const int& levelNumber, const std::string& nameFile );

        virtual void readData() override;

        const bool& tokenStatement() const { return tokenStatement_; }
        const std::string& statement() const { return statement_; }

        const bool& tokenResult() const { return tokenResult_; }
        const std::string& result() const { return result_; }
};

#endif