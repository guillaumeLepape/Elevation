#ifndef QUESTION_DATA_H
#define QUESTION_DATA_H

/*!
    * \file QuestionData.h
*/

#include "Data.h"

#include <tuple>

class QuestionData : public Data
{
    private:
        std::string questionName_;
        std::vector<std::tuple<std::string, int, bool>> answer_;

    public:
        QuestionData( const int& LevelNumber, const int& questionIndex );

        void readData() override;

        const std::string& questionName() const { return questionName_; }
        const std::vector<std::tuple<std::string, int, bool>>& answer() const { return answer_; }
};

#endif
