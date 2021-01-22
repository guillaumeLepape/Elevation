#ifndef FRENCH_DATA_H
#define FRENCH_DATA_H

#include <string>
#include <vector>
#include <memory>

enum class NameSpeaker
{
    player = 0,
    plug,
    description,
    action
};

typedef std::vector<std::tuple<NameSpeaker, std::string>> Message;

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
            {NameSpeaker::description, "Vous vous réveillez chez vous avec de vagues souvenirs de la soirée que vous avez passé chez votre ami."},
            {NameSpeaker::description, "C'est certainement dû à la consommation massive et diverse de drogues."},
            {NameSpeaker::description, "Il vous faudra donc persister sur cette lancée en allant vous approvisionnez auprès de vos 9 dealeurs préférés."},
            {NameSpeaker::description, "La consommation de ces 9 drogues est votre seul moyen de changer radicalement votre existence."}
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
            {NameSpeaker::plug, "Qu'est ce qui t'arrive, frère ? Tu as l'air grave défoncé."},
            {NameSpeaker::description, "Il a raison."},
            {NameSpeaker::description, "J'ai pas le temps pour ça. Le sang me monte à la tête."}
        };

        inline Message message1 = {
            {NameSpeaker::plug, "Qu'est ce qui te prends, fils de pute."},
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
            {NameSpeaker::plug, "Fils de pute !"}
        };

        inline Message message4 = {
            {NameSpeaker::plug, "Ah."},
            {NameSpeaker::description, "Le produit tombe au sol ainsi qu'un couteau."},
            {NameSpeaker::description, "Vous mettez le shit dans votre poche et saisissez le couteau."},
            {NameSpeaker::action, "Vous êtes maintenant équipé d'un couteau."}
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
            {NameSpeaker::description, "Vous ramassez un marteau tombé au sol lors du combat."},
            {NameSpeaker::action, "Un marteau vient être ajouté à votre collection d'armes."}
        };
    } // namespace Level5

    namespace Action
    {
        // generic UseWeapon data statement for fist
        inline std::tuple<bool, std::string> statementUseFist(false, "Cognez ! (Poing)");
        // generic UseWeapon data statement for knife
        inline std::tuple<bool, std::string> statementUseKnife(false, "Plantez ! (Couteau)");
        inline std::tuple<bool, std::string> statementUseKnifeFistCombo(false, "Combo avec le couteau !");
        // generic UseWeapon data statement for katana
        inline std::tuple<bool, std::string> statementUseKatana(false, "Découpez ! (Katana)");
        inline std::tuple<bool, std::string> statementUseKatanaFistCombo(false, "Combo avec le katana !");

        // generic UseWeapon data result
        inline std::tuple<bool, std::string> resultUseWeapon(true, "-*-plugName-*- perd -*-damage-*- points de vie.");

        inline std::string titleChooseWeapon = "Choix de l'arme";
        inline std::string titleChoosePlug = "Choix de l'ennemi";

        inline std::unique_ptr<std::tuple<bool, std::string>> newStatementUseWeapon(const std::string &nameWeapon)
        {
            if (nameWeapon == "Poing")
            {
                return std::make_unique<std::tuple<bool, std::string>>(statementUseFist);
            }
            if (nameWeapon == "Couteau")
            {
                return std::make_unique<std::tuple<bool, std::string>>(statementUseKnife);
            }
            if (nameWeapon == "Katana")
            {
                return std::make_unique<std::tuple<bool, std::string>>(statementUseKatana);
            }
            if (nameWeapon == "CouteauFistCombo")
            {
                return std::make_unique<std::tuple<bool, std::string>>(statementUseKnifeFistCombo);
            }
            if (nameWeapon == "KatanaFistCombo")
            {
                return std::make_unique<std::tuple<bool, std::string>>(statementUseKatanaFistCombo);
            }
            assert(false);
        }

        inline std::tuple<bool, std::string> statementChoosePlug( true, "Attaquer -*-plugName-*-." );
        inline std::tuple<bool, std::string> resultChoosePlug( true, "Vous avez choisi d'attaquer -*-plugName-*-." );

        inline std::tuple<bool, std::string> resultPlugAttack( true, "-*-plugName-*- vous inflige -*-damagePlug-*- points de vie." );

        inline std::tuple<bool, std::string> resultDead( true, "-*-plugName-*- est mort." );

        // data for pseudo action
        inline std::tuple<bool, std::string> statementPseudo( false, "Entrez votre prénom" );
        inline std::tuple<bool, std::string> resultPseudo( true, "Votre prénom est à présent : -*-pseudo-*-." );
    
        // data for negociate action
        inline std::tuple<bool, std::string> statementNegociate( false, "Entrez votre montant" );
        inline std::tuple<bool, std::string> resultNegociate( true, "Vous perdez -*-pricePlayer-*-€." );    
    } // namespace Action

    namespace Menu 
    {
        // title of startGame menu 
        inline std::string titleStartGameMenu = "Menu";

        // data for startGame action
        inline std::tuple<bool, std::string> statementStartGame( false, "Commencer une nouvelle partie" );
        inline std::tuple<bool, std::string> resultStartGame( false, "La partie commence." );

        // data for loadGame action
        inline std::tuple<bool, std::string> statementLoadGame( false, "Charger une partie" );
        inline std::tuple<bool, std::string> resultLoadGame( false, "Vous avez choisi de charger une partie." );
    
        // data for quit action 
        inline std::tuple<bool, std::string> statementQuit( false, "Quitter le jeu" );
        inline std::tuple<bool, std::string> resultQuit( false, "Fin du jeu" );

        // title of loadGame menu
        inline std::string titleLoadGameMenu = "Choix de la partie";

        // data for the choice of the loaded game 
        inline std::tuple<bool, std::string> statementChooseLoadedGame( true, "Charger la partie -*-pseudo-*-." );
        inline std::tuple<bool, std::string> resultChooseLoadedGame( false, "Vous avez chois charger une partie." );

        // title of endOfLevel menu
        inline std::string titleContinueMenu = "Niveau terminé";

        // data for continue action 
        inline std::tuple<bool, std::string> statementContinue( false, "Continuer votre partie" );
    
        // data for save and quit action
        inline std::tuple<bool, std::string> statementSaveAndQuit( false, "Quitter" );
        inline std::tuple<bool, std::string> resultSaveAndQuit( false, "Partie sauvegardée" );
    
        // data for game Over action
        inline std::tuple<bool, std::string> resultGameOver( false, "Vous etes mort. Game Over." );
    } // namespace Menu

    namespace Combo
    {
        inline std::string comboFistMeleeWeaponComboTitle = "Combo Poing-Arme de mếlée";
        inline std::string comboDoubleMeleeTitle = "Combo Double arme de melée";
        inline std::tuple<bool, std::string> statementDontCombo(false, "Ne pas déclencher le combo");
    } // namespace Combo

    namespace Question 
    {
        // First question title
        inline std::string titleFirstQuestion = "Les hommes sont-ils allez sur la Lune ?";
        
        // First Answer
        inline std::tuple<bool, std::string> answer1Question1( false, "Oui, bien sur !" );
        inline bool correctOrNotAnswer1Question1 = false;

        // Second Answer
        inline std::tuple<bool, std::string> answer2Question1( false, "Bien sur, les américains l'ont fait pour niquer les russes." );
        inline bool correctOrNotAnswer2Question1 = false;

        // Third Answer
        inline std::tuple<bool, std::string> answer3Question1( false, "Non, l'alunissage a eu lieu au Nevada." );
        inline bool correctOrNotAnswer3Question1 = true;


        // Second question title
        inline std::string titleSecondQuestion = "Pourquoi le faux alunissage a été caché ?";
        
        // First Answer
        inline std::tuple<bool, std::string> answer1Question2( false, "Euh ..." );
        inline bool correctOrNotAnswer1Question2 = false;

        // Second Answer
        inline std::tuple<bool, std::string> answer2Question2( false, "Pour montrer leurs supériorités, les américains ont préféré mentir car ils n'avaient pas les moyens technologiques d'y aller." );
        inline bool correctOrNotAnswer2Question2 = false;

        // Third Answer 
        inline std::tuple<bool, std::string> answer3Question2( false, "Pour cacher qu'en fait la Terre est plate." );
        inline bool correctOrNotAnswer3Question2 = true;


        // Third question title        
        inline std::string titleThirdQuestion = "Pourquoi vouloir masquer tout ça ?";

        // First Answer
        inline std::tuple<bool, std::string> answer1Question3( false,
            "Pour cacher la grand plan des élites qui consiste à réduire drastiquement la population." );
        inline bool correctOrNotAnswer1Question3 = true;

        // Second Answer
        inline std::tuple<bool, std::string> answer2Question3( false,
            "Pour cacher le projet d'Elon Musk, Bill Gates et Laurent Alexandre constitant à implémenter des puces à la population pour les controler." );
        inline bool correctOrNotAnswer2Question3 = true;

        // Third Answer 
        inline std::tuple<bool, std::string> answer3Question3( false,
            "Pour cacher que toutes gouvernements sont à la solde d'un organisation secrète dirigé par les reptiliens." );
        inline bool correctOrNotAnswer3Question3 = true;
    } // namespace Question

    namespace Tutorial 
    {
        inline std::string title1 = "Tutoriel : Système de combat";
        inline std::vector<std::string> statement1 = {
            "Dans ce jeu, les combats se déroulent ainsi.",
            "A chaque tour, vous choisissez d'abord quelle ennemi vous souhaitez attaquer et avec quelle arme.",
            "Une fois que vous avez attaqué, c'est au tour des ennemis.",
            "Ils attaquent avec l'arme dont ils disposent à tour de rôle.",
            "Le combat prend fin lorsque tous les ennemis sont morts ou lorsque vous êtes mort.",
            "Lorsque vous tuez un ennemi vous pouvez récupérer leurs armes."
        };

        inline std::string title2 = "Tutoriel : Enchaînements";
        inline std::vector<std::string> statement2 = {
            "Lors des combats des enchaînements peuvent être réalisés pour faire plus de dégats aux ennemis.",
            "Par exemple, en frappant avec le poing un ennemi,",
            "vous pouvez, lors du même tour, frapper le même ennemi avec un arme de mélée.",
            "Dans ce cas, l'arme de mélée infligera moitié moins de dégâts."
        };
    } // namespace Tutorial

} // namespace data

#endif