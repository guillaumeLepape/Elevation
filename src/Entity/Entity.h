#ifndef ENTITY_H
#define ENTITY_H

/*!
    * \file Entity.h
*/

#include <string>

class Entity
{
    protected:
        std::string name_;
        int nbLifePoints_;
        int maxNbLifePoints_;

        Entity( const std::string& name, const int& nbLifePoints, const int& maxNbLifePoints );

    public:
        virtual ~Entity() = default;

        /*!
            * \brief pseudo accesor 
            * \return pseudo of player
        */        
        const std::string& name() const { return name_; }
        
        /*!
            * \brief pseudo mutator 
            * \param pseudo : new pseudo
        */        
        void changeName( const std::string& name ) { name_ = name; }

        // Accessor of nbLifePoints_ attribute
        const int& nbLifePoints() const { return nbLifePoints_; }

        int missingLifePoints() const { return maxNbLifePoints_ - nbLifePoints_; }

        const int& maxLifePoints() const { return maxNbLifePoints_; }

        // Increase the number of life points by the arg nbLifePoints
        void increaseLifePoints( const int& nbLifePoints ) 
        { 
            if ( nbLifePoints_ + nbLifePoints >= maxNbLifePoints_ )
            {
                nbLifePoints_ = maxNbLifePoints_;
            }
            else
            {
                nbLifePoints_ += nbLifePoints; 
            }
        }
        // Decrease the number of life points by the arg nbLifePoints
        void decreaseLifePoints( const int& nbLifePoints ) { nbLifePoints_ -= nbLifePoints; }

        bool fullLife() const { return nbLifePoints_ == maxNbLifePoints_; }

        /*!
            \brief State of player : dead or alive 
            \return true if the number of life points is null or negative, false else
        */
        bool dead() const { return ( nbLifePoints_ <= 0 ); }

        std::string healthBar() const;
};

#endif