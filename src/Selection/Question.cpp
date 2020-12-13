/*!
    * \file Question.cpp
*/

#include "Question.h"

#include "Selection.h"

bool Question::question
( 
    const std::string& questionName, 
    const ListAnswers& listAnswers 
)
{
    std::vector<Action*> actions;

    for ( int i = 0; i < listAnswers.size(); i++ )
    {
        actions.push_back( listAnswers[i] );
    }

    int result = Selection::select(
        questionName,
        actions
    );

    return listAnswers[result]->correctOrNot(); 
}