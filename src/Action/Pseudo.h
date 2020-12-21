#ifndef PSEUDO_H
#define PSEUDO_H

/*!
    * \file Pseudo.h
*/

#include "Action.h"

#include "../Writer/MessageHandler.h"
#include "../Data/FeminineNameData.h"

class Pseudo : public Action
{
    private: 
        Player* const player_;
        const MessageHandler& messageHandler_;

        void formatString( std::string& str )
        {
            str[0] = std::toupper( str[0] );
            for ( int i = 1; i < str.length(); i++ )
            {
                str[i] = std::tolower( str[i] );
            }
        }

    public:
        explicit Pseudo
        ( 
            Player* const player, 
            const MessageHandler& messageHandler,
            const std::string& folderFromRoot,
            const std::string& nameFile
        ) : 
            Action( folderFromRoot, nameFile ),
            messageHandler_( messageHandler ),
            player_(player)
        {

        }
        void triggerAction() override 
        {
            actionWriter_.writeStatement( player_, nullptr );

            FeminineNameData feminineNameData( "dataset", "prenoms_feminins" );
            auto feminineName = feminineNameData.feminineName();

            std::string pseudo;
            std::cin >> pseudo;
            formatString( pseudo );

            while ( feminineName.find(pseudo) 
                    == feminineName.end() )
            {

                messageHandler_.writeMessage(1);
                actionWriter_.writeStatement( player_, nullptr );

                std::cin >> pseudo;
                formatString( pseudo );
            } 
            
            player_->setPseudo(pseudo);

            actionWriter_.writeResult( player_, nullptr );
        }
};

#endif