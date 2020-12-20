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
        convertAnswersToActions( answers ),
        folderFromRoot,
        nameFile
    );

    return answers[result]->correctOrNot();
}

std::vector<Action*> Question::convertAnswersToActions( const std::vector<Answer*>& answers )
{
    std::vector<Action*> actions;

    for ( auto i = answers.cbegin(); i != answers.cend(); i++ )
    {
        actions.push_back( *i );
    }

    return actions;
}