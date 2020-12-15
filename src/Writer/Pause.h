#ifndef PAUSE_H
#define PAUSE_H

/*!
    * \file Pause.h
*/

#include <string>
#include <iostream>

/*!
    * \class Pause
    * \brief class with only one static function to pause message
*/

class Pause
{
    public: 
        /*!
            * \brief Pause
            * pause message and waiting for enter entry 
        */
        static void pause()
        {
            std::string myString = "";

            do 
            {
                std::getline(std::cin, myString);
            }   
            while (myString.length() != 0);
        }
};

#endif