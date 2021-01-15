#ifndef RESULTS_DATA_H
#define RESULTS_DATA_H

/*!
    * \file ResultsData.h
*/

#include "Data.h"

#include <fstream>
#include <list>

class Result
{
    public:
        std::string pseudo_;
        std::string id_;
        int nbLevelSuceeded_;

        friend bool operator<( const Result& result1, const Result& result2 )
        {
            return ( result1.id_ < result2.id_ );
        }

};

class ResultsData : public Data
{
    private:
        std::list<Result> results_;

    public:
        ResultsData();

        void readData() override;

        void addResult( const Result& result );
        void writeData() const; 

        const std::list<Result>& results() const { return results_; }
};

#endif