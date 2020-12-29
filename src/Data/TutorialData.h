#ifndef TUTORIAL_DATA_H
#define TUTORIAL_DATA_H

/*! 
    * \file TutorialData.h
*/

#include "Data.h"

class TutorialData : public Data
{
    private:
        std::string name_;
        std::vector<std::string> tutorialStatement_;

    public:
        TutorialData
        ( 
            const std::string& folderFromRoot, 
            const std::string& fileName 
        );

        void readData();

        const std::string& name() const { return name_; }
        const std::vector<std::string> tutorialStatement() const { return tutorialStatement_; }
};

#endif