#ifndef FRENCH_DATA_H
#define FRENCH_DATA_H

#include <cassert>

#include "NameSpeaker.h"

namespace data
{
    namespace Introduction
    {
        // Introduction data
        // ***********************************

        // Header data
        inline std::string nameLevel = "Introduction : Dur réveil";
        inline int hour = 13;
        inline int minut = 12;

        // Messages data
        inline Message message0 = {
            {NameSpeaker::description, "Vous vous réveillez chez vous avec de vagues souvenirs de la soirée que vous avez passé chez votre amie."},
            {NameSpeaker::player, "C'est certainement dû à la consommation massive et diverse de drogues."},
            {NameSpeaker::player, "Il me faut persister sur cette lancée en allant m'approvisionnez auprès de mes 10 dealeurs préférés."},
            {NameSpeaker::description, "La consommation de ces 10 drogues est votre seul moyen de changer radicalement votre existence."}
        };

        inline Message message1 = {
            {NameSpeaker::player, "Je ne souviens plus de mon prénom. Comment je m'appelle ?"}
        };  

        inline Message message2 = {
            {NameSpeaker::player, "Euh, je suis plutôt sûr d'être une femme."}
        };

        inline Message message3 = {
            {NameSpeaker::player, "Ce prénom n'existe pas."}
        };

        inline Message message4( const std::string& pseudo )
        {
            return {{ NameSpeaker::player, "Bon d'accord " + pseudo + ", ça fera l'affaire." }};
        }
    } // namespace Introduction

    namespace Level1
    {
        // Level 1 data
        // ***********************************

        // Header data
        inline std::string nameLevel = "Niveau 1 : Beuh";
        inline int hour = 14;
        inline int minut = 35;

        // Messages data
        inline Message message0
        ( 
            const std::string& pseudo, 
            const std::string& plugName,
            const int& pricePlug 
        )
        {
            return { 
                {NameSpeaker::player, "Bon, c'est parti."},
                {NameSpeaker::description, "Vous arrivez en bas du batiment"},
                {NameSpeaker::plug, "Ca va, " + pseudo + " ?"},
                {NameSpeaker::player, "Et toi, " + plugName + " ?"},
                {NameSpeaker::plug, "Comme d'habitude ? C'est " + std::to_string( pricePlug ) + "€."},
                {NameSpeaker::player, "Tiens."},
                {NameSpeaker::action, "Vous perdez " + std::to_string( pricePlug ) + "€."},
                {NameSpeaker::plug, "Bonne journée."},
                {NameSpeaker::player, "A la prochaine."},
                {NameSpeaker::description, "Roule. Fume."}
            };
        }
    } // namespace Level1

    namespace Level2
    {
        // Level 2 data
        // ***********************************

        // Header data
        inline std::string nameLevel = "Niveau 2 : Coke";
        inline int hour = 15;
        inline int minut = 10;

        // Messages data
        inline Message message0( const std::string& plugName, const int& pricePlug )
        {
            return {
                {NameSpeaker::player, "Salut, " + plugName + "."} ,
                {NameSpeaker::plug, "Ca va ? Tu cherches quoi ?"} ,
                {NameSpeaker::player, "De la C."} ,
                {NameSpeaker::plug, "C'est " + std::to_string(pricePlug) + "€ le gramme."} ,
                {NameSpeaker::player, "Putain, c'est un peu cher."} ,
                {NameSpeaker::plug, "C'est pas négociable."} ,
                {NameSpeaker::player, "Aller j'ai pas masse de tunes."} 
            };
        }

        inline Message message1 = {
            {NameSpeaker::plug, "Ok, je veux bien négocier. Tu proposes combien ?"}
        };  

        inline Message message2 = {
            {NameSpeaker::plug, "T'es con ou quoi ?"}
        };

        inline Message message3 = {
            {NameSpeaker::plug, "Je peux pas me permettre ca."}
        };

        inline Message message4 = {
            {NameSpeaker::plug, "Ca me convient. Tiens. A la prochaine."}
        };

        inline Message message5 = {
            {NameSpeaker::player, "Merci. Salut."},
            {NameSpeaker::description, "Carte VISA. Sniffe."}
        };
    } // namespace Level2

    namespace Level3
    {
        inline std::string nameLevel = "Niveau 3 : Shit";
        inline int hour = 16;
        inline int minut = 4;

        inline Message message0 = {
            {NameSpeaker::description, "Vous arrivez en bas du bloc."},
            {NameSpeaker::player, "Salut !"},
            {NameSpeaker::plug, "Tu veux quoi."},
            {NameSpeaker::player, "T'as quelque chose pour 10 balles."},
            {NameSpeaker::plug, "Non, c'est minimum 20 balles."},
            {NameSpeaker::player, "Ok, ca va être juste."},
            {NameSpeaker::plug, "C'est 20 balles ou rien."},
            {NameSpeaker::description, "Vous vous taisez. Vous serrez le poing."},
            {NameSpeaker::plug, "Qu'est ce qui t'arrive, meuf ? Tu as l'air grave défoncée."},
            {NameSpeaker::description, "Il a raison."},
            {NameSpeaker::description, "J'ai pas le temps pour ça. Le sang me monte à la tête."}
        };

        inline Message message1 = {
            {NameSpeaker::plug, "Qu'est ce qui te prends, sale pute."},
            {NameSpeaker::description, "Vous venez de le frapper."},
            {NameSpeaker::plug, "Tu peux pas juste payer ta dose et te casser."}
        };

        inline Message message2( const std::string& plugName )
        {
            return {
                {NameSpeaker::description, "Vous vous placez sur le torse de " + plugName + "."},
                {NameSpeaker::plug, "Batard !"}
            };
        }

        inline Message message3 = {
            {NameSpeaker::plug, "Salope !"}
        };

        inline Message message4 = {
            {NameSpeaker::plug, "Ah."},
            {NameSpeaker::description, "Le produit tombe au sol ainsi qu'un couteau."},
            {NameSpeaker::description, "Vous mettez le shit dans votre poche et saisissez le couteau."}
        };

        inline Message message5 = {
            {NameSpeaker::description, "Roule. Fume."}
        };
    } // namespace Level3

    namespace Level4
    {
        inline std::string nameLevel = "Niveau 4 : Lean";
        inline int hour = 17;
        inline int minut = 15;

        inline Message message0( const std::string& pseudo )
        {
            return {
                { NameSpeaker::description, "Vous arrivez en bas d'un petit appartement où vous trouverez le produit tant convoité." },
                { NameSpeaker::description, "Vous sonnez à la porte." },
                { NameSpeaker::plug, "Ca va " + pseudo + " ?" },
                { NameSpeaker::player, "Tranquille." },
                { NameSpeaker::description, "La porte s'ouvre. Vous montez jusqu'à l'appartement et y pénétrez." },
                { NameSpeaker::plug, "Viens par ici, je peux te faire le produit gratuitement." },
                { NameSpeaker::player, "Gratuit, c'est cool." },
                { NameSpeaker::plug, "Mais tu dois répondre à quelques questions avant." },
                { NameSpeaker::player, "Ok." },
                { NameSpeaker::plug, "Je veux savoir si tu comprends les liens cachés." },
                { NameSpeaker::player, "Euh ... ok." },
                { NameSpeaker::plug, "Première question." } 
            };
        }

        inline Message message1 = {
            { NameSpeaker::plug, "Non, c'est pas ça, réessaie." }
        };

        inline Message message2 = {
            { NameSpeaker::plug, "Yep, c'est ca, question suivante." }
        };

        inline Message message3 = {
            { NameSpeaker::plug, "Quelle niveau ! Tiens." },
            { NameSpeaker::description, "Gobelet. Sip." }
        };
    } // namespace Level4

    namespace Level5
    {
        inline std::string nameLevel = "Niveau 5 : Xanax";
        inline int hour = 19;
        inline int minut = 2;

        inline Message message0 = {
            {NameSpeaker::description, "Vous arrivez en bas du Bones factory tenu par le celebre gang des Bones."},
            {NameSpeaker::plug, "Tu rentres pas."}
        };

        inline Message message1 = {
            {NameSpeaker::player, "Je vais te buter."}
        };

        inline Message message2 = {
            {NameSpeaker::description, "Après avoir tabasser le pauvre homme, vous pénetrez dans le batiment."},
            {NameSpeaker::player, "Fait chier, je controle plus grand chose là."},
            {NameSpeaker::plug, "Hey, toi là."},
            {NameSpeaker::player, "Et merde."}
        };

        inline Message message3 = {
            {NameSpeaker::player, "Encore une personne tuée de ma main, pas le choix faut que je continue."},
            {NameSpeaker::player, "N'empêche j'ai plus d'armes, comment je vais faire."},
            {NameSpeaker::description, "Vous ouvrez la porte qui va vous mener au produit tant convoité."},
            {NameSpeaker::plug, "Non pas ce fou furieux !"}
        };

        inline Message message4 = {
            {NameSpeaker::player, "Putain, il m'a fait mal ce batard."},
            {NameSpeaker::player, "Au moins, j'ai récupéré son couteau, ca pourra mettre utile."}
        };

        inline Message message5 = {
            {NameSpeaker::player, "Qu'est ce qu'il se passe ? Je me sens mieux là."},
            {NameSpeaker::player, "Ca doit être les effets de la drogue."}
        };

        inline Message message6 = {
            {NameSpeaker::player, "En allant par là, je devrais trouver la drogue."},
            {NameSpeaker::plug, "Putain c'est la pétasse qui a buté tout le monde. On s'la fait."},
            {NameSpeaker::player, "Enfin. J'ai plus qu'à buter ces 3 batards et c'est torché."}
        };

        inline Message message7 = {
            {NameSpeaker::description, "Après avoir buter tout le monde, vous ramassez les 3 cachetons qui reste dans la poche du kamikaze."},
            {NameSpeaker::player, "Tout ca pour."},
            {NameSpeaker::description, "Cachetons sur la langue. Verre d'eau."}
        };
    } // namespace Level5

    namespace Level6
    {
        inline std::string nameLevel = "Niveau 6 : Champis";
        inline int hour = 21;
        inline int minut = 10;

        inline Message message0 = {
            {NameSpeaker::player, "Avec toutes ces histoires, il est temps de rentrer chez soi."},
            {NameSpeaker::description, "Arrivée chez vous, vous vous asseyez sur le canapé."},
            {NameSpeaker::player, "Ca tourne, sa mère. J'ai pas fini mais faut que je me repose."},
            {NameSpeaker::player, "Il me reste quelque champis, parfait."},
            {NameSpeaker::description, "Poele. Soupe de champis"},
            {NameSpeaker::player, "Zzzzzzz." },
            {NameSpeaker::player, "Zzzzzzz." },
            {NameSpeaker::player, "Zzzzzzz." }
        };
    } // namespace Level6

    namespace Level7
    {
        inline std::string nameLevel = "Niveau 7 : Kétamine";
        inline int hour = 0;
        inline int minut = 10;

        inline Message message0 = {
            {NameSpeaker::description, "Boum."},
            {NameSpeaker::player, "AHHHHHHHHHHHHHH. QU'EST CE QUI SE PASSE PUTAIN DE MERDE !" },
            {NameSpeaker::description, "Kaboom."},
            {NameSpeaker::plug, "CC je suis là pour te buter."}
        };

        inline Message message1 = {
            {NameSpeaker::player, "Tu as pensé à mon sommeil."},
            {NameSpeaker::player, "Au moins, tu as des trucs sur toi. De la ké parfait."},
            {NameSpeaker::description, "Feuille à rouler. Para."}
        };
    } // namespace Level7

    namespace Level8
    {
        inline std::string nameLevel = "Niveau 8 : Crack (Interlude)";
        inline int hour = 2;
        inline int minut = 12;

        inline Message message0( const std::string& plugName )
        {
            return {
                {NameSpeaker::player, "Ca part en couilles là. Il faut que j'aille voir " + plugName + " pour qu'elle m'aide."},
                {NameSpeaker::player, "J'ai pas de sang sur moi, je peux tappe des hallus maintenant."},
                {NameSpeaker::description, "Malgré votre état, vous arrivez enfin devant chez " + plugName + ", l'une de vos plus fidèles amies."},
                {NameSpeaker::description, "Arrivé devant la porte, celle-ci s'ouvre par miracle."},
                {NameSpeaker::plug, "Pourquoi ?"},
                {NameSpeaker::player, "Ah merde mon couteau."},
                {NameSpeaker::description, "Effectivement elle a un couteau dans la poitrine."},
                {NameSpeaker::plug, "Après tout ce que j'ai fait pour toi."},
                {NameSpeaker::player, "Tu souffres, faut que j'abrège tes souffrances."},
                {NameSpeaker::player, "Avec ce gun c'est parfait."}
            };
        }

        inline Message message1 = {
            {NameSpeaker::description, "BANG ! "},
            {NameSpeaker::description, "PAW !"},
            {NameSpeaker::player, "Deux balles dans le crane ca devrait suffire."},
            {NameSpeaker::player, "Il y a du crack, je vais le fumer ici."},
            {NameSpeaker::description, "Pipe à crack. Briquet."}
        };
    } // namespace Level8

    namespace Level9
    {
        inline std::string nameLevel = "Niveau 9 : LSD (Révélation)";
        inline int hour = 3;
        inline int minut = 35;

        inline Message message0 = {
            {NameSpeaker::player, "Dégage de là."}
        };

        inline Message message1 = {
            {NameSpeaker::player, "Tu te prends pour qui pour me poignarder 3 fois."},
            {NameSpeaker::plug, "C'est toi qui bute tout le monde depuis ce matin."},
            {NameSpeaker::player, "T'as planté la mauvaise personne."}
        };

        inline Message message2 = {
            {NameSpeaker::plug, "Crêve sale pute."}
        };

        inline Message message3 = {
            {NameSpeaker::plug, "Ca cicatrise tout seul, il faut que j'tappe plus fort."}
        };

        inline Message message4 = {
            {NameSpeaker::plug, "J'ai jamais vu ca. T'es un putain d'alien."},
            {NameSpeaker::player, "Non, juste un Dieu."},
            {NameSpeaker::plug, "S'il te plait, me tue pas."},
            {NameSpeaker::player, "J'hésite."},
            {NameSpeaker::player, "Allez, pour s'amuser."}
        };

        inline Message message5 = {
            {NameSpeaker::player, "Cette sensation."},
            {NameSpeaker::player, "Je n'ai jamais rien vécu de tel."},
            {NameSpeaker::player, "Ce sentiment de plénitude."},
            {NameSpeaker::player, "Tous ces meurtres auront servis à quelque chose."}
        };

        inline Message message6 = {
            {NameSpeaker::player, "Encore."},
            {NameSpeaker::player, "Toujours plus de puissance."}
        };

        inline Message message7 = {
            {NameSpeaker::player, "Ca y est, je deviens un dieu."}
        };
    } // namespace Level9

    namespace Level10
    {
        inline std::string nameLevel = "Niveau 10 : Héroine (Désillusion)";
        inline int hour = 7;
        inline int minut = 30;

        inline Message messageMinus1 = {
            {NameSpeaker::plug, "Que fais tu petit chose ?"},
            {NameSpeaker::player, "Viens là, j'ai pas peur de toi."},
            {NameSpeaker::plug, "Tiens, tu peux combattre avec ca."}
        };

        inline Message message0 = {
            {NameSpeaker::player, "Est ce qui se passe, mon corps !"},
            {NameSpeaker::plug, "La drogue te décompose."},
            {NameSpeaker::plug, "Tu es donc bien faible face à ma puissance."},
            {NameSpeaker::plug, "Ah, tu es encore en vie. Je te laisse encore une chance."}
        };

        inline Message message1 = {
            {NameSpeaker::plug, "Tu t'es pris pour qui."},
            {NameSpeaker::plug, "Tu as peut-être détruit toutes ces imbéciles, mais face à moi tu ne peux rien."}
        };

        inline Message message2 = {
            {NameSpeaker::plug, "J'ai décidé de te laisser accomplir ta quête. Tiens prends ca."},
            {NameSpeaker::action, "Héroine ajouté à votre inventaire."},
            {NameSpeaker::description, "Vous consommez le dernier produit tant convoité."},
            {NameSpeaker::player, "J'y suis arrivé."}
        };

        inline Message message3 = {
            {NameSpeaker::player, "Encore."}
        };

        inline Message message4 = {
            {NameSpeaker::plug, "Il est temps que cette imposture cesse."},
            {NameSpeaker::description, "Vous êtes mort."}
        };
    } // namespace Level10

    namespace Outro
    {
        inline std::string nameLevel = "Crédits";
        inline int hour = 0;
        inline int minut = 0;

        inline Message message0 = {
            {NameSpeaker::description, "Programmeur : Jess H."},
            {NameSpeaker::description, "Merci d'avoir jouer à ce jeu !"},
            {NameSpeaker::description, "A la prochaine."}
        };
    } // namespace Outro

    namespace Action
    {
        inline std::string titleChooseWeapon = "Choix de l'arme";
        inline std::string titleChoosePlug = "Choix de l'ennemi";

        inline std::string statementChoosePlug(const std::string& plugName)
        {
            return "Attaquer " + plugName + ".";
        }
        inline std::string resultChoosePlug( const std::string& plugName )
        {
            return "Vous avez choisi d'attaquer " + plugName + ".";
        }
        inline std::string resultPlugAttack(const std::string& plugName, const int& damagePlug)
        {
            return plugName + " vous inflige " + std::to_string(damagePlug) + " points de vie.";
        }

        inline std::string resultDead( const std::string& plugName )
        {
            return plugName + " est mort.";
        }

        // data for pseudo action
        inline std::string statementPseudo( "Entrez votre prénom" );
        inline std::string resultPseudo(const std::string& pseudo)
        {
            return "Votre prénom est à présent : " + pseudo + "."; 
        } 

        // data for negociate action
        inline std::string statementNegociate( "Entrez votre montant" );
        inline std::string resultNegociate( const int& pricePlayer )
        {
            return "Vous perdez " + std::to_string( pricePlayer ) + "€.";
        }

        // data for regeneration action
        inline std::string resultRegeneration( const int& lifePointsRegeneration )
        {
            return "Vous gagnez " + std::to_string( lifePointsRegeneration ) + " points de vie.";
        }

        inline std::string resultAddWeapon( const std::string& nameWeapon )
        {
            return nameWeapon + " ajouté à votre inventaire.";
        }

        inline std::string resultsIncreaseMaxLifePoints( const int& maxLifePoints )
        {
            return "Votre nombre de points de vie maximal augmente de " + std::to_string(maxLifePoints) + " points.";
        }
    } // namespace Action

    namespace Menu 
    {
        // title of startGame menu 
        inline std::string titleStartGameMenu = "Menu";

        // data for startGame action
        inline std::string statementStartGame( "Commencer une nouvelle partie" );
        inline std::string resultStartGame( "La partie commence." );

        // data for loadGame action
        inline std::string statementLoadGame( "Charger une partie" );
        inline std::string resultLoadGame( "Vous avez choisi de charger une partie." );
    
        // data for quit action 
        inline std::string statementQuit( "Quitter le jeu" );
        inline std::string resultQuit( "Fin du jeu" );

        // title of loadGame menu
        inline std::string titleLoadGameMenu = "Choix de la partie";

        // data for the choice of the loaded game 
        inline std::string statementChooseLoadedGame( const std::string& pseudo, const int& levelNumber )
        {
            return "Charger la partie " + pseudo + " au niveau " + std::to_string(levelNumber); 
        }
        inline std::string resultChooseLoadedGame( "Vous avez chois charger une partie." );

        // title of endOfLevel menu
        inline std::string titleContinueMenu = "Niveau terminé";

        // data for continue action 
        inline std::string statementContinue( "Continuer votre partie" );
    
        // data for save and quit action
        inline std::string statementSaveAndQuit( "Quitter" );
        inline std::string resultSaveAndQuit( "Partie sauvegardée" );
    
        // data for game Over action
        inline std::string resultGameOver( "Vous etes mort. Game Over." );
    } // namespace Menu

    namespace Combo
    {
        inline std::string titleFistMeleeWeapon = "Combo Poing-Arme de mélée";
        inline std::string triggerStatementFistMeleeWeapon 
            = "Attaquer un ennemi avec le poing";
        inline std::string triggeredStatementFistMeleeWeapon 
            = "Attaquer le même ennemi avec l'arme de mélée de votre choix. Le combo n'est pas déclenché si vous ne possèdez pas d'arme de mélée.";
        inline std::string malusStatementFistMeleeWeapon
            = "L'attaque avec l'arme de mélée inflige moitié moins de dégats"; 

        inline std::string titleDoubleMeleeWeapon = "Combo Double Couteau";
        inline std::string triggerStatementDoubleMeleeWeapon 
            = "Attaquer un ennemi avec le couteau.";
        inline std::string triggeredStatementDoubleMeleeWeapon 
            = "Attaquer le même ennemi avec la même arme.";
        inline std::string malusStatementDoubleMeleeWeapon 
            = "Le couteau que vous avez utilisé est détruit. Vous pouvez ne pas déclencher le combo. Dans ce cas le couteau n'est pas détruit.";

        inline std::string titleQuadrupleCutter = "Combo Quadruple Cutter";
        inline std::string triggerStatementQuadrupleCutter 
            = "Attaquer un ennemu avec le cutter";
        inline std::string triggeredStatementQuadrupleCutter
            = "Attaquer le même ennemi avec le cutter à 3 reprises.";
        inline std::string malusStatementQuadrupleCutter
            = "Le cutter est détruit et vous ne pouvez plus l'utiliser.";

        inline std::string statementDontCombo = "Ne pas déclencher le combo";
    } // namespace Combo

    namespace Information 
    {
        inline std::string titleInformation = "Informations";
        inline std::string statementInformationWeapon 
            = "Informations sur les armes que vous possèdez.";
        inline std::string statementInformationCombo 
            = "Informations sur les combos disponible lors de ce combat.";
        inline std::string statementNoInformation 
            = "Je ne souhaite pas avoir d'informations.";
        inline std::string statementNoInformationAnymore 
            = "Je ne souhaite pas avoir d'informations et je ne souhaite plus voir le menu d'informations lors de ce combat.";
    } // namespace Information

    namespace Question 
    {
        // First question title
        inline std::string titleFirstQuestion = "Les hommes sont-ils allez sur la Lune ?";
        
        // First Answer
        inline std::string answer1Question1("Oui, bien sur !" );
        inline bool correctOrNotAnswer1Question1 = false;

        // Second Answer
        inline std::string answer2Question1( "Bien sur, les américains l'ont fait pour niquer les russes." );
        inline bool correctOrNotAnswer2Question1 = false;

        // Third Answer
        inline std::string answer3Question1( "Non, l'alunissage a eu lieu au Nevada." );
        inline bool correctOrNotAnswer3Question1 = true;


        // Second question title
        inline std::string titleSecondQuestion = "Pourquoi le faux alunissage a été caché ?";
        
        // First Answer
        inline std::string answer1Question2( "Euh ..." );
        inline bool correctOrNotAnswer1Question2 = false;

        // Second Answer
        inline std::string answer2Question2( "Pour montrer leurs supériorités, les américains ont préféré mentir car ils n'avaient pas les moyens technologiques d'y aller." );
        inline bool correctOrNotAnswer2Question2 = false;

        // Third Answer 
        inline std::string answer3Question2( "Pour cacher qu'en fait la Terre est plate." );
        inline bool correctOrNotAnswer3Question2 = true;


        // Third question title        
        inline std::string titleThirdQuestion = "Pourquoi vouloir masquer tout ça ?";

        // First Answer
        inline std::string answer1Question3( "Pour cacher la grand plan des élites qui consiste à réduire drastiquement la population." );
        inline bool correctOrNotAnswer1Question3 = true;

        // Second Answer
        inline std::string answer2Question3(
            "Pour cacher le projet d'Elon Musk, Bill Gates et Laurent Alexandre constitant à implémenter des puces à la population pour les controler." );
        inline bool correctOrNotAnswer2Question3 = true;

        // Third Answer 
        inline std::string answer3Question3(
            "Pour cacher que toutes gouvernements sont à la solde d'une organisation secrète dirigée par les reptiliens." );v
        inline bool correctOrNotAnswer3Question3 = true;
    } // namespace Question

    namespace Tutorial 
    {
        inline std::string titleCombatSystem = "Tutoriel : Système de combat";
        inline std::vector<std::string> statementCombatSystem( const int& maxNbLifePoints )
        {
            return 
            {
                "Dans ce jeu, les combats se déroulent ainsi.",
                "A chaque tour, vous choisissez d'abord quelle ennemi vous souhaitez attaquer et avec quelle arme.",
                "Une fois que vous avez attaqué, c'est au tour des ennemis.",
                "Ils attaquent avec l'arme dont ils disposent à tour de rôle.",
                "Vous avez " + std::to_string(maxNbLifePoints) + " points de vie. Lorsqu'il descende en dessous de 0, vous êtes mort.",
                "Le combat prend fin lorsque tous les ennemis sont morts ou lorsque vous êtes mort.",
                "Lorsque vous tuez un ennemi vous pouvez récupérer leurs armes."
            };
        }
        
        inline std::string titleCombo = "Tutoriel : Enchaînements";
        inline std::vector<std::string> statementCombo = {
            "Lors des combats des enchaînements peuvent être réalisés pour faire plus de dégats aux ennemis.",
            "Ainsi, au lieu de frapper avec une arme une unique fois lors de votre tour,",
            "vous pouvez frapper avec plusieurs fois. Attention, chaque combo possède un malus."
        };

        inline std::string titleComboFistMeleeWeapon = "Tutoriel : Combo Poing - Arme de mélée";
        inline std::vector<std::string> statementComboFistMeleeWeapon = {
            "En frappant avec le poing un ennemi,",
            "vous pouvez, lors du même tour, frapper le même ennemi avec un arme de mélée.",
            "Dans ce cas, l'arme de mélée infligera moitié moins de dégâts.",
            "En réfléchissant bien, vous pourrez tuer le prochain ennemi en 1 tour,",
            "au lieu de 2. Vous perdez de fait moins de points de vie."
        };

        inline std::string titleComboDoubleMeleeWeapon = "Tutoriel : Arme de mélée + Arme de mélée";
        inline std::vector<std::string> statementComboDoubleMeleeWeapon = {
            "En frappant avec une arme de mélée un ennemi,",
            "vous pouvez, lors du même tour, frapper le même ennemi avec la même arme de mélée.",
            "Si vous decidez de déclencher le combo, vous infligerez double plus de dégats à un ennemi,",
            "mais en contrepartie vous perdez l'arme.",
            "Grace à ce combo, vous pourrez vaincre le prochain ennemi en 1 tour,",
            "sans perdre de points de vie."
        };

        inline std::string titleNoWeapon = "Tutoriel : Subir et revenir";
        inline std::vector<std::string> statementNoWeapon = {
            "Vos poings sont la seule arme qu'il vous reste.",
            "Pas le choix, vous devez subir et revenir.",
            "Pour cela, lorsque vous tuez un ennemi, vous pouvez récupérer son arme si vous n'en disposez pas déjà."
        };

        inline std::string titleRegeneration = "Tutoriel : Regeneration";
        inline std::vector<std::string> statementRegeneration = {
            "Les drogues sont très bonnes pour la santé (dans ce jeu en tout cas).",
            "Elles ouvrent de nouvelles capacité au corps humain.",
            "Parfois, elles permettent de se régénerer de ces blessures.",
            "Bon après, je te dis pas quand tu régéneras, c'est Dieu qui a décidé de ça.",
            "Après comme il existe pas, c'est moi qui est décidé de tout ca.",
            "Oui, j'ai totalement dévié du sujet. Une petite digression ca fait du bien, non ?",
            "Là je t'imagine taper sur entrée en te disant : \"Putain mais qu'est ce qui raconte ce con.",
            "Je voudrai continuer son jeu de merde. D'ailleurs c'est quand que c'est fini ca me saoule.\"",
            "Je comprends.",
            "Une autre théorie faudrait qu'un prénom féminim permet de se régénerer.",
            "Me demander pas pourquoi, c'est comme ca.",
            "Et je vois tous les mecs qui ont mis leur prénom comme des débiles.",
            "C'est vraiment une catastrophe ces hommes, incapacable de se mettre à la place",
            "d'une femme. Bon, bref j'ai fini.",
            "En fait, non lol.",
            "Ah oui, bon courage pour le prochain combat."
        };
    } // namespace Tutorial

    namespace Weapon
    {   
         // generic UseWeapon data statement for fist
        inline std::string statementUseFist("Cognez ! (Poing)");
        // generic UseWeapon data statement for knife
        inline std::string statementUseKnife("Plantez ! (Couteau)");
        // generic UseWeapon data statement for katana
        inline std::string statementUseKatana("Découpez ! (Katana)");
        // generic UseWeapon data statement for cutter
        inline std::string statementUseCutter("Tailladez ! (Cutter)");
        // generic UseWeapon data statement for hammer
        inline std::string statementUseHammer("Martelez ! (Marteau)" );

        inline std::string statementDivineStrike("Frappez comme un Dieu! (Frappe divine)" );

        inline std::string statementUseChopper("Hachez ! (Hachoir)" );
        inline std::string statementUseNoWeapon("");

        // generic UseWeapon data statement for 9mm
        inline std::string statementUseNinemm("Tirez ! (9mm)");
        // generic UseWeapon data statement for 9mm
        inline std::string statementUseAK47("Rafalez ! (AK47)");

        // generic UseWeapon data result
        inline std::string resultUseWeapon(const std::string& plugName, const int& damageWeapon)
        {
            return plugName + " perd " + std::to_string( damageWeapon ) + " points de vie.";
        }

        inline std::string statementCombo(const std::string& nameWeapon )
        {
            return "Combo avec le " + nameWeapon + " !";
        }

        // Name of all weapons
        inline std::string nameNoWeapon = "Pas d'arme";

        inline std::string nameFist = "Poing";
        inline std::string nameDivineStrike = "Frappe Divine";

        inline std::string nameCutter = "Cutter";
        inline std::string nameKnife = "Couteau";
        inline std::string nameHammer = "Marteau";
        inline std::string nameKatana = "Katana";
        inline std::string nameChopper = "Hachoir";
        inline std::string nameHeroine = "Heroine";

        inline std::string nameNinemm = "9mm";
        inline std::string nameAK47 = "AK47"; 
    } // namespace Weapon

} // namespace data

#endif