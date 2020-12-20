#ifndef ANSWER_WRITER_H
#define ANSWER_WRITER_H

/*!
    * \file AnswerWriter.h
*/

#include "../Data/AnswerData.h"

class AnswerWriter
{
    private:
        AnswerData answerData_;

    public:
        AnswerWriter
        ( 
            const int& levelNumber, 
            const std::string& nameFile  
        ) : 
            answerData_( levelNumber, nameFile )
        {};

        const AnswerData& answerData() const { return answerData_; }
};

#endif