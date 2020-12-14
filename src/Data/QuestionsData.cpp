/*!
    * \file QuestionsData.cpp
*/

#include "QuestionsData.h"

QuestionsData::QuestionsData( const int& levelNumber ) :
    Data( levelNumber, "question" )
{
    readData();
}

void QuestionsData::readData()
{
    nbQuestion_ = jsonObject_["nbQuestion"];

    for ( int i = 0; i < nbQuestion_; i++ )
    {
        QuestionData questionData( levelNumber_, i ); 

        questions_.push_back( questionData );
    }
}