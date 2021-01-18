#ifndef RESULTS_DATA_H
#define RESULTS_DATA_H

/*!
    * \file ResultsData.h
*/

#include "Data.h"

#include <fstream>
#include <list>

class ResultsData : public Data
{
    private:
        std::list<Player> results_;

    public:
        ResultsData();

        void readData() override;

        void addResult( const Player& player );
        void writeData() const; 

        const std::list<Player>& results() const { return results_; }
};

#endif