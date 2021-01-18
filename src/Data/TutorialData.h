#ifndef TUTORIAL_DATA_H
#define TUTORIAL_DATA_H

/*! 
    * \file TutorialData.h
*/

#include "Data.h"

class TutorialData : public Data
{
    private:
        std::string title_;
        std::vector<std::string> tutorialStatement_;

    public:
        TutorialData
        ( 
            const std::string& folderFromRoot, 
            const std::string& fileName 
        );

        TutorialData
        (
            const std::string& title,
            const std::vector<std::string>& tutorialStatement
        );

        void readData();

        const std::string& title() const { return title_; }
        const std::vector<std::string> tutorialStatement() const { return tutorialStatement_; }
};

#endif