#ifndef RESULTS_DATA_H
#define RESULTS_DATA_H

/*!
    * \file ResultsData.h
*/

#include "Data.h"

#include <fstream>

struct Result
{
    std::string pseudo_;
    std::string id_;
    int nbLevelSuceeded_;
};

class ResultsData : public Data
{
    private:
        std::vector<Result> results_;

    public:
        ResultsData();

        void readData() override;

        void addResult( const Result& result );
        void writeData() const; 

        const std::vector<Result>& results() const { return results_; }
};

#endif