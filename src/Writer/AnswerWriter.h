#ifndef ANSWER_WRITER_H
#define ANSWER_WRITER_H

/*!
    * \file AnswerWriter.h
*/

#include "ActionWriter.h"

class AnswerWriter : public ActionWriter
{
    private:
        bool correctOrNot_;

    public:
        AnswerWriter
        ( 
            const std::string& statement, 
            const std::string& result, 
            const bool& correctOrNot 
        );

        const bool& correctOrNot() const { return correctOrNot_; }
};

#endif