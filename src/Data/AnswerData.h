#ifndef ANSWER_DATA_H
#define ANSWER_DATA_H

/*! 
    * \file AnswerData.h
*/

#include "ActionData.h"

class AnswerData : public ActionData
{   
    private:
        bool correctOrNot_;

    public:
        AnswerData( const nlohmann::json& jsonObject );
        AnswerData( const std::string& folderFromRoot, const std::string& nameFile ); 

        void readData() override;

        const bool& correctOrNot() const { return correctOrNot_; }
        
};

#endif