#ifndef PSEUDO_H
#define PSEUDO_H

/*!
    * \file Pseudo.h
*/

#include "Action.h"

#include "MessageWriter.h"
#include "ListNameData.h"

class Pseudo : public Action
{
    private: 
        Player* const player_;

        void formatString( std::string& str )
        {
            str[0] = std::toupper( str[0] );
            for ( long unsigned int i = 1; i < str.length(); i++ )
            {
                str[i] = std::tolower( str[i] );
            }
        }

    public:
        explicit Pseudo 
        (
            Player* const player, 
            const std::string& statement,
            const std::string& result
        ) :
            Action( statement, result ),
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
                MessageWriter messageWriter
                ( 
                    data::Introduction::message1, 
                    player_->pseudo(), 
                    "" 
                );
                messageWriter.writeMessage();
                actionWriter_.writeStatement();

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
                    MessageWriter messageWriter2
                    ( 
                        data::Introduction::message2, 
                        player_->pseudo(), 
                        "" 
                    );
                    messageWriter2.writeMessage();
                }
                // If pseudo doesn't appear in the two previous dataset,
                // consider that this name doesn't exist
                else 
                {
                    MessageWriter messageWriter3
                    ( 
                        data::Introduction::message3, 
                        player_->pseudo(), 
                        "" 
                    );
                    messageWriter3.writeMessage();
                }
            }

            player_->setPseudo(*ptrPseudo);

            actionWriter_.updateResult( data::Action::resultPseudo( player_->pseudo() ) );
            actionWriter_.writeResult();
        }
};

#endif