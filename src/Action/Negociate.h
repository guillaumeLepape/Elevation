#ifndef NEGOCIATE_H
#define NEGOCIATE_H

/*!
    * \file Negociate.h
*/

#include "Action.h"

#include "MessageHandler.h"

class Negociate : public Action
{
    private: 
        Player* const player_;
        Plug* const plug_;
        const MessageHandler& messageHandler_;

    public:
        explicit Negociate
        (
            Player* const player, 
            Plug* const plug, 
            const MessageHandler& messageHandler,
            const std::string& folderFromRoot,
            const std::string& fileName
        ) :
            Action( folderFromRoot, fileName ),
            player_(player), 
            plug_(plug), 
            messageHandler_(messageHandler)
        {

        }

        explicit Negociate
        (
            Player* const player, 
            Plug* const plug, 
            const MessageHandler& messageHandler,
            const std::tuple<bool, std::string> statement,
            const std::tuple<bool, std::string> result
        ) :
            Action( statement, result ),  
            player_(player), 
            plug_(plug), 
            messageHandler_(messageHandler)      
        {

        }

        void triggerAction() override 
        {
            bool out = false;

            messageHandler_.writeMessage(1);

            while ( !out )
            {
                std::string priceStr;

                actionWriter_.writeStatement();
                std::cin >> priceStr;
                int price = std::stoi( priceStr ); 
                player_->setPrice( price );

                if ( price > plug_->price() )
                {
                    messageHandler_.writeMessage(2);
                }
                else if ( price <= plug_->price() && plug_->price() - 30 <= price ) 
                {
                    out = true;
                    messageHandler_.writeMessage(4);

                    player_->increaseMoney( -price );
                }
                else 
                {
                    messageHandler_.writeMessage(3);
                } 
            }
            actionWriter_.preTreatmentResult( player_, plug_ );
            actionWriter_.writeResult();
            
            messageHandler_.writeMessage(5);
        }
};

#endif