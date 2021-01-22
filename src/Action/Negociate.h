#ifndef NEGOCIATE_H
#define NEGOCIATE_H

/*!
    * \file Negociate.h
*/

#include "Action.h"

#include "MessageWriter.h"

class Negociate : public Action
{
    private: 
        Player* const player_;
        Plug* const plug_;

    public:
        explicit Negociate
        (
            Player* const player, 
            Plug* const plug, 
            const std::string& folderFromRoot,
            const std::string& fileName
        ) :
            Action( folderFromRoot, fileName ),
            player_(player), 
            plug_(plug) 
        {

        }

        explicit Negociate
        (
            Player* const player, 
            Plug* const plug, 
            const std::tuple<bool, std::string> statement,
            const std::tuple<bool, std::string> result
        ) :
            Action( statement, result ),  
            player_(player), 
            plug_(plug) 
        {

        }

        void triggerAction() override 
        {
            bool out = false;

            MessageWriter messageWriter1
            ( 
                data::Level2::message1, 
                player_->pseudo(),
                plug_->name() 
            );
            messageWriter1.writeMessage();

            while ( !out )
            {
                std::string priceStr;

                actionWriter_.writeStatement();
                std::cin >> priceStr;
                int price = std::stoi( priceStr ); 
                player_->setPrice( price );

                if ( price > plug_->price() )
                {
                    MessageWriter messageWriter2
                    ( 
                        data::Level2::message2,
                        player_->pseudo(),
                        plug_->name()
                    );
                    messageWriter2.writeMessage();
                }
                else if ( price <= plug_->price() && plug_->price() - 30 <= price ) 
                {
                    out = true;
                    MessageWriter messageWriter4
                    ( 
                        data::Level2::message4,
                        player_->pseudo(),
                        plug_->name()
                    );
                    messageWriter4.writeMessage();

                    player_->increaseMoney( -price );
                }
                else 
                {
                    MessageWriter messageWriter3
                    ( 
                        data::Level2::message3,
                        player_->pseudo(),
                        plug_->name()
                    );
                    messageWriter3.writeMessage();
                } 
            }
            actionWriter_.preTreatmentResult( player_, plug_ );
            actionWriter_.writeResult();
            
            MessageWriter messageWriter5
            ( 
                data::Level2::message5,
                player_->pseudo(),
                plug_->name()
            );
            messageWriter5.writeMessage();
        }
};

#endif