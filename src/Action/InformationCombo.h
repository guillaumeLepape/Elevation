#ifndef INFORMATION_COMBO_H
#define INFORMATION_COMBO_H

/*!
    * \file InformationCombo.h
*/

#include "Action.h"

#include "ComboWriter.h"

class InformationCombo : public Action
{
    private:
        std::vector<Combo*> combos_;

    public:
        InformationCombo
        ( 
            const std::vector<Combo*>& combos,
            const std::string& statement, 
            const std::string& result
        ) :
            Action( statement, result ),
            combos_( combos )
        {

        }

        void triggerAction() override
        {
            for ( long unsigned int i = 0; i < combos_.size(); i++ )
            {
                ComboWriter comboWriter( combos_[i] );
                comboWriter.informationCombo();
            }
        }
};

#endif