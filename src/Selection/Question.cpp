/*!
    * \file Question.cpp
*/

#include "Question.h"

#include "Selection.h"

bool Question::question
( 
    const int& levelNumber,
    const int& indexQuestion,
    const std::vector<Answer*>& answers
)
{
    int result = Selection::select(
        levelNumber,
        indexQuestion,
        convertAnswersToActions( answers )
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