/*!
    * \file Question.cpp
*/

#include "Question.h"

bool Question::question
( 
    const std::vector<Answer*>& answers,
    const std::string& folderFromRoot,
    const std::string& nameFile
)
{
    int result = Selection::select(
        (const std::vector<Action*>&) answers,
        folderFromRoot,
        nameFile
    );

    return answers[result]->correctOrNot();
}

bool Question::question
(
    const std::vector<Answer*>& answers,
    const std::string& title
)
{
    int result = Selection::select(
        (const std::vector<Action*>&) answers,
        title
    );

    return answers[result]->correctOrNot();
}