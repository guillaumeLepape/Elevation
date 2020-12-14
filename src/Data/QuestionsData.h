#ifndef QUESTIONS_DATA_H
#define QUESTIONS_DATA_H

/*!
    * \file Data.h
*/

#include "Data.h"
#include "QuestionData.h"

class QuestionsData : public Data
{
    private:
        int nbQuestion_;
        std::vector<QuestionData> questions_;

    public:
        QuestionsData( const int& levelNumber );
        
        void readData() override;

        const std::vector<QuestionData>& questions() const { return questions_; }
};

#endif