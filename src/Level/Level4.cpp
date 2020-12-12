#include "Level4.h"

#include "../Selection/Selection.h"
#include "../Action/WrongAnswer.h"
#include "../Action/CorrectAnswer.h"
// #include "../Selection/Question.h"


void Level4::startLevel()
{
    Plug* plug = new Plug( "Freeze Corleone", 20 );

    Message message( "../messages/messageLevel4.json" );

    message.writeHeader();
    message.writeInConsole( player_, plug, 0 );

    firstQuestion( plug, message );

    secondQuestion( plug, message );

    thirdQuestion( plug, message );

    delete plug;

    std::cout << "\n";
}

void Level4::firstQuestion( Plug* plug, const Message& message )
{
    int resultSelection = 0;

    // while the answer is not good, the plug repeat the question
    while( resultSelection != 2 )
    {
        WrongAnswer firstWrongAnswer
        ( 
            "Oui, bien sur !", 
            player_, 
            plug, 
            message,
            1
        );

        WrongAnswer secondWrongAnswer
        ( 
            "Bien sur, les américains l'ont fait pour niquer les russes.",
            player_,
            plug, 
            message,
            1
        );

        CorrectAnswer correctAnswer
        ( 
            "Non, l'alunissage a eu lieu au Nevada.",
            player_,
            plug, 
            message,
            2
        );

        resultSelection = Selection::select(
            "Les hommes sont-ils allez sur la Lune ?",
            { &firstWrongAnswer, &correctAnswer, &secondWrongAnswer }
        );
    }
}

void Level4::secondQuestion( Plug* plug, const Message& message )
{
    int resultSelection = 0;

    // while the answer is not good, the plug repeat the question
    while( resultSelection != 3 )
    {
        WrongAnswer firstWrongAnswer
        ( 
            "Euh ...", 
            player_, 
            plug, 
            message,
            1
        );

        WrongAnswer secondWrongAnswer
        ( 
            "Pour montrer leurs supériorités, les américains ont préféré mentir car ils n'avaient pas les moyens technologiques d'y aller.",
            player_,
            plug, 
            message,
            1
        );

        CorrectAnswer correctAnswer
        ( 
            "Pour cacher qu'en fait la Terre est plate.",
            player_,
            plug, 
            message,
            2
        );

        resultSelection = Selection::select(
            "Pourquoi le faux alunissage a été caché ?",
            { &firstWrongAnswer, &secondWrongAnswer, &correctAnswer }
        );
    }
}

void Level4::thirdQuestion( Plug* plug, const Message& message )
{
    int resultSelection = 0;

    // while the answer is not good, the plug repeat the question
    while( resultSelection != 1 && resultSelection != 2 && resultSelection != 3 )
    {
        CorrectAnswer firstCorrectAnswer
        ( 
            "Pour cacher la grand plan des élites qui consiste à réduire drastiquement la population.", 
            player_, 
            plug, 
            message,
            3
        );

        CorrectAnswer secondCorrectAnswer
        ( 
            "Pour cacher le projet d'Elon Musk, Bill Gates et Laurent Alexandre constitant à implémenter des puces à la population pour les controler.",
            player_,
            plug, 
            message,
            3
        );

        CorrectAnswer thirdCorrectAnswer
        ( 
            "Pour cacher que toutes gouvernements sont à la solde d'un organisation secrète dirigé par les reptiliens.",
            player_,
            plug, 
            message,
            3
        );

        resultSelection = Selection::select(
            "Pourquoi vouloir masquer tout ca ?",
            { &firstCorrectAnswer, &secondCorrectAnswer, &thirdCorrectAnswer }
        );
    }
}