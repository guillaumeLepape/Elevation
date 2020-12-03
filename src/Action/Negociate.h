#ifndef NEGOCIATE_H
#define NEGOCIATE_H

/*!
    * \file Negociate.h
*/

#include "Action.h"

class Negociate : public Action
{
    private: 
        Player* const player_;
        Plug* const plug_;
        const Message& message_;

    public:
        explicit Negociate( Player* const player, Plug* const plug, const Message& message ) :
            Action("Ok, je veux bien négocier. Tu proposes combien ?"), 
            player_(player), 
            plug_(plug), 
            message_(message)
        {

        }
        void triggerAction() const override 
        {
            bool out = false;
            while ( !out )
            {
                message_.writeInConsole( player_, plug_, 1 );
                std::string priceStr;
                std::cin >> priceStr;
                int price =  std::stoi( priceStr ); 

                if ( price > plug_->price() )
                {
                    message_.writeInConsole( player_, plug_, 2 );
                }
                else if ( price <= plug_->price() && plug_->price() - 30 <= price ) 
                {
                    out = true;
                    message_.writeInConsole( player_, plug_, 4 );
                    player_->increaseMoney( -price );
                }
                else 
                {
                    message_.writeInConsole( player_, plug_, 3 );
                }
            }
        }
};

#endif