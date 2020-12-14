#ifndef DATA_H
#define DATA_H

/*!
    * \file Data.h
*/

#include <nlohmann/json.hpp>

class Data
{
    protected:
        int levelNumber_;
        nlohmann::json jsonObject_;

    public:
        Data( const int& levelNumber, const std::string& fileName );
        virtual void readData() = 0;
        virtual ~Data() {}
};

#endif