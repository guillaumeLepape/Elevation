#ifndef DATA_H
#define DATA_H

/*!
    * \file Data.h
*/

#include <nlohmann/json.hpp>

class Data
{
    private:
        void openFile( const std::string& fileName );

    protected:
        int levelNumber_;
        nlohmann::json jsonObject_;

        virtual void readData() = 0;

    public:
        Data();
        Data( const int& levelNumber, const std::string& fileName );
        virtual ~Data() {}
};

#endif