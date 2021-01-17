#ifndef QUESTION_H
#define QUESTION_H

/*!
    * \file Question.h
*/

// #include "ListAnswers.h"
#include "Answer.h"

class Question
{   
    private:
        Question() {}

    public:
        static bool question
        ( 
            const std::vector<Answer*>& answers,
            const std::string& folderFromRoot,
            const std::string& nameFile
        );

        static bool question
        (
            const std::vector<Answer*>& answers,
            const std::string& title
        );
};

#endif