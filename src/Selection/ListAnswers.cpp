/*!
    * \file ListAnswers.cpp
*/

#include "ListAnswers.h"

ListAnswers::ListAnswers
( 
    Player* player, 
    Plug* plug, 
    const Message& message, 
    const std::vector<OneAnswer>& answers
)
{
    for ( auto oneAnswer = answers.cbegin(); oneAnswer != answers.cend(); oneAnswer++ )
    {
        std::vector<Answer*>::push_back
        ( 
            new Answer
            (
                oneAnswer->statement_, 
                player, 
                plug, 
                message, 
                oneAnswer->indexMessage_,
                oneAnswer->correctOrNot_ 
            )
        );
    }
}