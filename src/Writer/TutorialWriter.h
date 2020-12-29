#ifndef TUTORIAL_WRITER_H
#define TUTORIAL_WRITER_H

/*!
    * \file TutorialWriter.h
*/

#include "TutorialData.h"

class TutorialWriter
{
    private:
        TutorialData tutorialData_;

    public:
        TutorialWriter
        ( 
            const std::string& folderFromRoot, 
            const std::string& fileName 
        );

        void writeTutorial() const;
};

#endif