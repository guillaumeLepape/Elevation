/*! 
    * \file AnswerWriter.cpp
*/

#include "AnswerWriter.h"

AnswerWriter::AnswerWriter
( 
    const std::string& statement, 
    const std::string& result, 
    const bool& correctOrNot 
) :
    ActionWriter( statement, result ),
    correctOrNot_( correctOrNot )
{

}