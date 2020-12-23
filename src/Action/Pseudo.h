#ifndef PSEUDO_H
#define PSEUDO_H

/*!
    * \file Pseudo.h
*/

#include "Action.h"

#include "MessageHandler.h"
#include "ListNameData.h"

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
            // actionWriter_.writeStatement( player_, nullptr );

            ListNameData feminineNameData( "dataset", "prenoms_feminins" );
            std::set<std::string> feminineName = feminineNameData.listName();

            ListNameData masculineNameData( "dataset", "prenoms_masculins" );
            std::set<std::string> masculineName = masculineNameData.listName();

            std::string* ptrPseudo(0);
            bool out = false;

            while ( !out )
            {
                // Inform the user that he have to enter an information (his pseudo)
                messageHandler_.writeMessage(1);
                actionWriter_.writeStatement( player_, nullptr );

                // Get pseudo from user
                std::string pseudo;
                std::cin >> pseudo;
                formatString( pseudo );
                ptrPseudo = &pseudo;
                
                // Check if chosen pseudo is in the feminine name dataset
                if ( feminineName.find(pseudo) 
                    != feminineName.end() )
                {
                    out = true;
                }
                // Check if chosen pseudo is in the masculine name dataset
                else if ( masculineName.find(pseudo) 
                    != masculineName.end() )
                {
                    messageHandler_.writeMessage(2);
                }
                // If pseudo doesn't appear in the two previous dataset,
                // consider that this name doesn't exist
                else 
                {
                    messageHandler_.writeMessage(3);
                }
            }

            player_->setPseudo(*ptrPseudo);

            actionWriter_.writeResult( player_, nullptr );
        }
};

#endif