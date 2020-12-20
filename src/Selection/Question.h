#ifndef QUESTION_H
#define QUESTION_H

/*!
    * \file Question.h
*/

// #include "ListAnswers.h"
#include "../Action/Answer.h"

class Question
{   
    private:
        static std::vector<Action*> convertAnswersToActions( const std::vector<Answer*>& answers );

        Question() {}

    public:
        static bool question
        ( 
            const std::vector<Answer*>& answers,
            const std::string& folderFromRoot,
            const std::string& nameFile
        );
};

#endif