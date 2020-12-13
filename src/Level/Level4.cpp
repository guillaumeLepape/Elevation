#include "Level4.h"

#include "../Selection/Selection.h"
#include "../Selection/Question.h"


void Level4::startLevel()
{
    Plug plug( "Freeze Corleone", 20 );

    Message message( "../messages/messageLevel4.json" );

    message.writeHeader();
    message.writeInConsole( player_, &plug, 0 );

    firstQuestion( &plug, message );

    secondQuestion( &plug, message );

    thirdQuestion( &plug, message );

    std::cout << "\n";
}

void Level4::firstQuestion( Plug* plug, const Message& message )
{
    ListAnswers listAnswers
    ( 
        player_, 
        plug, 
        message, 
        {
            OneAnswer( "Oui, bien sur !", 1, false ),
            OneAnswer( "Bien sur, les américains l'ont fait pour niquer les russes.", 1, false ),
            OneAnswer( "Non, l'alunissage a eu lieu au Nevada.", 2, true ),
        } 
    ); 

    // while user don't answer correctly the question
    while ( !Question::question( "Les hommes sont-ils allez sur la Lune ?", listAnswers ) )
    {}
}

void Level4::secondQuestion( Plug* plug, const Message& message )
{
    ListAnswers listAnswers
    (
        player_,
        plug,
        message,
        {
            OneAnswer( "Euh ...", 1, false ),
            OneAnswer( "Pour montrer leurs supériorités, les américains ont préféré mentir car ils n'avaient pas les moyens technologiques d'y aller.",
            1, false),
            OneAnswer( "Pour cacher qu'en fait la Terre est plate.", 2, true )
        }
    );

    while( !Question::question( "Pourquoi le faux alunissage a été caché ?", listAnswers ) )
    {}
}

void Level4::thirdQuestion( Plug* plug, const Message& message )
{
    ListAnswers listAnswers
    (
        player_,
        plug,
        message,
        {
            OneAnswer( "Pour cacher la grand plan des élites qui consiste à réduire drastiquement la population.", 3, true ),
            OneAnswer( "Pour cacher le projet d'Elon Musk, Bill Gates et Laurent Alexandre constitant à implémenter des puces à la population pour les controler.", 3, true),
            OneAnswer( "Pour cacher que toutes gouvernements sont à la solde d'un organisation secrète dirigé par les reptiliens.", 3, true )

        }
    );

    while( !Question::question( "Pourquoi vouloir masquer tout ca ?", listAnswers ) )
    {}
}