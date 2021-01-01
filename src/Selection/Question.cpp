/*!
    * \file Question.cpp
*/

#include "Question.h"

#include "Selection.h"

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
