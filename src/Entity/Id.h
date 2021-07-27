#ifndef ID_H
#define ID_H

/*!
    * \file Id.h
*/

#include <random>

class Id
{
    public:
        static int generateId()
        {
            std::random_device rd;
	        return rd();
        }
};

#endif