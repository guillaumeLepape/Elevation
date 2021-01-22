/*!
    * \file Question.cpp
*/

#include "Question.h"

#include "Selection.h"

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