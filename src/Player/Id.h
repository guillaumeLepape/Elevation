#ifndef ID_H
#define ID_H

/*!
    * \file Id.h
*/

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/lexical_cast.hpp>

class Id
{
    public:
        static std::string generateId()
        {
	        auto gen = boost::uuids::random_generator();
	        boost::uuids::uuid id = gen();

	        return boost::uuids::to_string(id);
        }
};

#endif