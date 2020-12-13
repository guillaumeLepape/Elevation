#ifndef LIST_ANSWERS_H
#define LIST_ANSWERS_H

/*!
    * \file ListAnswers.h
*/

#include <map>

#include "../Action/Answer.h"

struct OneAnswer
{
    OneAnswer
    ( 
        const std::string& statement, 
        const int& indexMessage, 
        const bool& correctOrNot 
    ) : statement_( statement ), 
        indexMessage_( indexMessage ), 
        correctOrNot_( correctOrNot )
    {}

    std::string statement_;
    int indexMessage_;
    bool correctOrNot_;
};

class ListAnswers : public std::vector<Answer*>
{
    public: 
        ListAnswers
        ( 
            Player* player, 
            Plug* plug, 
            const Message& message, 
            const std::vector<OneAnswer>& answers
        );
};

#endif