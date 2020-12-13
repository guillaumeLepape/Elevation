#ifndef QUESTION_H
#define QUESTION_H

/*!
    * \file Question.h
*/

#include "ListAnswers.h"

class Question
{   
    private:
        Question() {}

    public:
        static bool question
        ( 
            const std::string& questionName, 
            const ListAnswers& listAnswers 
        );
};

#endif