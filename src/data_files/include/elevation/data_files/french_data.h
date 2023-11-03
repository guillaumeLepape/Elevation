#pragma once

#include <fmt/core.h>

#include <string>
#include <tuple>
#include <vector>

namespace elevation::data {
using namespace std::literals;

enum class NameSpeaker { player = 0, plug, description, action };
using Message_t = std::vector<std::tuple<NameSpeaker, std::string>>;

namespace introduction {
// Introduction data
// ***********************************

// header data
static constexpr auto nameLevel = "Introduction : Dur réveil"sv;
static constexpr auto hour = 13U;
static constexpr auto minut = 12U;

// Messages data
static constexpr auto message0 = std::array{
    std::tuple{
        NameSpeaker::description,
        "Vous vous réveillez chez vous avec de vagues souvenirs de la soirée "
        "que vous avez passé chez votre amie."},
    std::tuple{
        NameSpeaker::player,
        "C'est certainement dû à la consommation massive et diverse de drogues"
        "."},
    std::tuple{
        NameSpeaker::player,
        "Il me faut persister sur cette lancée en allant m'approvisionnez "
        "auprès de mes 10 dealeurs préférés."},
    std::tuple{
        NameSpeaker::description,
        "La consommation de ces 10 drogues est votre seul moyen de changer "
        "radicalement votre existence."}};

static constexpr auto message1 = std::array{
    std::tuple{NameSpeaker::player,
               "Je ne souviens plus de mon prénom. Comment je m'appelle ?"}};

static constexpr auto message2 = std::array{std::tuple{
    NameSpeaker::player, "Euh, je suis plutôt sûr d'être une femme."}};

static constexpr auto message3 =
    std::array{std::tuple{NameSpeaker::player, "Ce prénom n'existe pas."}};

inline auto message4(const std::string& pseudo) {
  return std::array{
      std::tuple{NameSpeaker::player,
                 fmt::format("Bon d'accord {}, ça fera l'affaire.", pseudo)}};
}
}  // namespace introduction

namespace level1 {
// Level 1 data
// ***********************************

// header data
static constexpr auto nameLevel = "Niveau 1 : Beuh"sv;
static constexpr auto hour = 14U;
static constexpr auto minut = 35U;

// Messages data
inline auto message0(const std::string& pseudo, const std::string& plugName,
                     int pricePlug) {
  return std::tuple{
      std::tuple{NameSpeaker::player, "Bon, c'est parti."},
      std::tuple{NameSpeaker::description, "Vous arrivez en bas du batiment"},
      std::tuple{NameSpeaker::plug, fmt::format("Ca va, {} ?", pseudo)},
      std::tuple{NameSpeaker::player, fmt::format("Et toi, {} ?", plugName)},
      std::tuple{NameSpeaker::plug,
                 fmt::format("Comme d'habitude ? C'est {}€.", pricePlug)},
      std::tuple{NameSpeaker::player, "Tiens."},
      std::tuple{NameSpeaker::action,
                 fmt::format("Vous perdez {}€.", pricePlug)},
      std::tuple{NameSpeaker::plug, "Bonne journée."},
      std::tuple{NameSpeaker::player, "A la prochaine."},
      std::tuple{NameSpeaker::description, "Roule. Fume."}};
}
}  // namespace level1

namespace level2 {
// Level 2 data
// ***********************************

// header data
static constexpr auto nameLevel = "Niveau 2 : Coke"sv;
static constexpr auto hour = 15U;
static constexpr auto minut = 10U;

// Messages data
inline auto message0(const std::string& plugName, int pricePlug) {
  return std::tuple{
      std::tuple{NameSpeaker::player, fmt::format("Salut, {}.", plugName)},
      std::tuple{NameSpeaker::plug, "Ca va ? Tu cherches quoi ?"},
      std::tuple{NameSpeaker::player, "De la C."},
      std::tuple{NameSpeaker::plug,
                 fmt::format("C'est {}€ le gramme.", pricePlug)},
      std::tuple{NameSpeaker::player, "Putain, c'est un peu cher."},
      std::tuple{NameSpeaker::plug, "C'est pas négociable."},
      std::tuple{NameSpeaker::player, "Aller j'ai pas masse de tunes."}};
}

static constexpr auto message1 = std::array{std::tuple{
    NameSpeaker::plug, "Ok, je veux bien négocier. Tu proposes combien ?"}};

static constexpr auto message2 =
    std::array{std::tuple{NameSpeaker::plug, "T'es con ou quoi ?"}};

static constexpr auto message3 =
    std::array{std::tuple{NameSpeaker::plug, "Je peux pas me permettre ca."}};

static constexpr auto message4 = std::array{
    std::tuple{NameSpeaker::plug, "Ca me convient. Tiens. A la prochaine."}};

static constexpr auto message5 =
    std::array{std::tuple{NameSpeaker::player, "Merci. Salut."},
               std::tuple{NameSpeaker::description, "Carte VISA. Sniffe."}};
}  // namespace level2

namespace level3 {
static constexpr auto nameLevel = "Niveau 3 : Shit"sv;
static constexpr auto hour = 16U;
static constexpr auto minut = 4U;

static constexpr auto message0 = std::array{
    std::tuple{NameSpeaker::description, "Vous arrivez en bas du bloc."},
    std::tuple{NameSpeaker::player, "Salut !"},
    std::tuple{NameSpeaker::plug, "Tu veux quoi."},
    std::tuple{NameSpeaker::player, "T'as quelque chose pour 10 balles."},
    std::tuple{NameSpeaker::plug, "Non, c'est minimum 20 balles."},
    std::tuple{NameSpeaker::player, "Ok, ca va être juste."},
    std::tuple{NameSpeaker::plug, "C'est 20 balles ou rien."},
    std::tuple{NameSpeaker::description,
               "Vous vous taisez. Vous serrez le poing."},
    std::tuple{NameSpeaker::plug,
               "Qu'est ce qui t'arrive, meuf ? Tu as l'air grave défoncée."},
    std::tuple{NameSpeaker::description, "Il a raison."},
    std::tuple{NameSpeaker::description,
               "J'ai pas le temps pour ça. Le sang me monte à la tête."}};

static constexpr auto message1 = std::array{
    std::tuple{NameSpeaker::plug, "Qu'est ce qui te prends, sale pute."},
    std::tuple{NameSpeaker::description, "Vous venez de le frapper."},
    std::tuple{NameSpeaker::plug,
               "Tu peux pas juste payer ta dose et te casser."}};

inline auto message2(const std::string& plugName) {
  return std::tuple{
      std::tuple{NameSpeaker::description,
                 fmt::format("Vous vous placez sur le torse de {}.", plugName)},
      std::tuple{NameSpeaker::plug, "Batard !"}};
}

static constexpr auto message3 =
    std::array{std::tuple{NameSpeaker::plug, "Salope !"}};

static constexpr auto message4 = std::array{
    std::tuple{NameSpeaker::plug, "Ah."},
    std::tuple{NameSpeaker::description,
               "Le produit tombe au sol ainsi qu'un couteau."},
    std::tuple{
        NameSpeaker::description,
        "Vous mettez le shit dans votre poche et saisissez le couteau."}};

static constexpr auto message5 =
    std::array{std::tuple{NameSpeaker::description, "Roule. Fume."}};
}  // namespace level3

namespace level4 {
static constexpr auto nameLevel = "Niveau 4 : Lean"sv;
static constexpr auto hour = 17U;
static constexpr auto minut = 15U;

inline auto message0(const std::string& pseudo) {
  return std::tuple{
      std::tuple{
          NameSpeaker::description,
          "Vous arrivez en bas d'un petit appartement où vous trouverez le "
          "produit tant convoité."},
      std::tuple{NameSpeaker::description, "Vous sonnez à la porte."},
      std::tuple{NameSpeaker::plug, fmt::format("Ca va {} ?", pseudo)},
      std::tuple{NameSpeaker::player, "Tranquille."},
      std::tuple{
          NameSpeaker::description,
          "La porte s'ouvre. Vous montez jusqu'à l'appartement et y pénétrez."},
      std::tuple{NameSpeaker::plug,
                 "Viens par ici, je peux te faire le produit gratuitement."},
      std::tuple{NameSpeaker::player, "Gratuit, c'est cool."},
      std::tuple{NameSpeaker::plug,
                 "Mais tu dois répondre à quelques questions avant."},
      std::tuple{NameSpeaker::player, "Ok."},
      std::tuple{NameSpeaker::plug,
                 "Je veux savoir si tu comprends les liens cachés."},
      std::tuple{NameSpeaker::player, "Euh ... ok."},
      std::tuple{NameSpeaker::plug, "Première question."}};
}

static constexpr auto message1 =
    std::array{std::tuple{NameSpeaker::plug, "Non, c'est pas ça, réessaie."}};

static constexpr auto message2 = std::array{
    std::tuple{NameSpeaker::plug, "Yep, c'est ca, question suivante."}};

static constexpr auto message3 =
    std::array{std::tuple{NameSpeaker::plug, "Quelle niveau ! Tiens."},
               std::tuple{NameSpeaker::description, "Gobelet. Sip."}};
}  // namespace level4

namespace level5 {
static constexpr auto nameLevel = "Niveau 5 : Xanax"sv;
static constexpr auto hour = 19U;
static constexpr auto minut = 2U;

static constexpr auto message0 =
    std::array{std::tuple{NameSpeaker::description,
                          "Vous arrivez en bas du Bones factory tenu par le "
                          "celebre gang des Bones."},
               std::tuple{NameSpeaker::plug, "Tu rentres pas."}};

static constexpr auto message1 =
    std::array{std::tuple{NameSpeaker::player, "Je vais te buter."}};

static constexpr auto message2 =
    std::array{std::tuple{NameSpeaker::description,
                          "Après avoir tabasser le pauvre homme, vous pénetrez "
                          "dans le batiment."},
               std::tuple{NameSpeaker::player,
                          "Fait chier, je controle plus grand chose là."},
               std::tuple{NameSpeaker::plug, "Hey, toi là."},
               std::tuple{NameSpeaker::player, "Et merde."}};

static constexpr auto message3 = std::array{
    std::tuple{NameSpeaker::player,
               "Encore une personne tuée de ma main, pas le choix faut que je "
               "continue."},
    std::tuple{NameSpeaker::player,
               "N'empêche j'ai plus d'armes, comment je vais faire."},
    std::tuple{
        NameSpeaker::description,
        "Vous ouvrez la porte qui va vous mener au produit tant convoité."},
    std::tuple{NameSpeaker::plug, "Non pas ce fou furieux !"}};

static constexpr auto message4 = std::array{
    std::tuple{NameSpeaker::player, "Putain, il m'a fait mal ce batard."},
    std::tuple{NameSpeaker::player,
               "Au moins, j'ai récupéré son couteau, ca pourra mettre utile."}};

static constexpr auto message5 = std::array{
    std::tuple{NameSpeaker::player,
               "Qu'est ce qu'il se passe ? Je me sens mieux là."},
    std::tuple{NameSpeaker::player, "Ca doit être les effets de la drogue."}};

static constexpr auto message6 = std::array{
    std::tuple{NameSpeaker::player,
               "En allant par là, je devrais trouver la drogue."},
    std::tuple{
        NameSpeaker::plug,
        "Putain c'est la pétasse qui a buté tout le monde. On s'la fait."},
    std::tuple{NameSpeaker::player,
               "Enfin. J'ai plus qu'à buter ces 3 batards et c'est torché."}};

static constexpr auto message7 = std::array{
    std::tuple{NameSpeaker::description,
               "Après avoir buter tout le monde, vous ramassez les 3 cachetons "
               "qui reste "
               "dans la poche du kamikaze."},
    std::tuple{NameSpeaker::player, "Tout ca pour."},
    std::tuple{NameSpeaker::description,
               "Cachetons sur la langue. Verre d'eau."}};
}  // namespace level5

namespace level6 {
static constexpr auto nameLevel = "Niveau 6 : Champis"sv;
static constexpr auto hour = 21U;
static constexpr auto minut = 10U;

static constexpr auto message0 = std::array{
    std::tuple{NameSpeaker::player,
               "Avec toutes ces histoires, il est temps de rentrer chez soi."},
    std::tuple{NameSpeaker::description,
               "Arrivée chez vous, vous vous asseyez sur le canapé."},
    std::tuple{NameSpeaker::player,
               "Ca tourne, sa mère. J'ai pas fini mais faut que je me repose."},
    std::tuple{NameSpeaker::player, "Il me reste quelque champis, parfait."},
    std::tuple{NameSpeaker::description, "Poele. Soupe de champis"},
    std::tuple{NameSpeaker::player, "Zzzzzzz."},
    std::tuple{NameSpeaker::player, "Zzzzzzz."},
    std::tuple{NameSpeaker::player, "Zzzzzzz."}};
}  // namespace level6

namespace level7 {
static constexpr auto nameLevel = "Niveau 7 : Kétamine"sv;
static constexpr auto hour = 0U;
static constexpr auto minut = 10U;

static constexpr auto message0 = std::array{
    std::tuple{NameSpeaker::description, "Boum."},
    std::tuple{NameSpeaker::player,
               "AHHHHHHHHHHHHHH. QU'EST CE QUI SE PASSE PUTAIN DE MERDE !"},
    std::tuple{NameSpeaker::description, "Kaboom."},
    std::tuple{NameSpeaker::plug, "CC je suis là pour te buter."}};

static constexpr auto message1 = std::array{
    std::tuple{NameSpeaker::player, "Tu as pensé à mon sommeil."},
    std::tuple{NameSpeaker::player,
               "Au moins, tu as des trucs sur toi. De la ké parfait."},
    std::tuple{NameSpeaker::description, "Feuille à rouler. Para."}};
}  // namespace level7

namespace level8 {
static constexpr auto nameLevel = "Niveau 8 : Crack (Interlude)"sv;
static constexpr auto hour = 2U;
static constexpr auto minut = 12U;

inline auto message0(const std::string& plugName) {
  return std::tuple{
      std::tuple{NameSpeaker::player,
                 fmt::format("Ca part en couilles là. Il faut que "
                             "j'aille voir {} pour qu'elle m'aide.",
                             plugName)},
      std::tuple{
          NameSpeaker::player,
          "J'ai pas de sang sur moi, je peux tappe des hallus maintenant."},
      std::tuple{
          NameSpeaker::description,
          fmt::format("Malgré votre état, vous arrivez enfin devant chez {}, "
                      "l'une de vos plus fidèles amies.",
                      plugName)},
      std::tuple{NameSpeaker::description,
                 "Arrivé devant la porte, celle-ci s'ouvre par miracle."},
      std::tuple{NameSpeaker::plug, "Pourquoi ?"},
      std::tuple{NameSpeaker::player, "Ah merde mon couteau."},
      std::tuple{NameSpeaker::description,
                 "Effectivement elle a un couteau dans la poitrine."},
      std::tuple{NameSpeaker::plug, "Après tout ce que j'ai fait pour toi."},
      std::tuple{NameSpeaker::player,
                 "Tu souffres, faut que j'abrège tes souffrances."},
      std::tuple{NameSpeaker::player, "Avec ce gun c'est parfait."}};
}

static constexpr auto message1 = std::array{
    std::tuple{NameSpeaker::description, "BANG ! "},
    std::tuple{NameSpeaker::description, "PAW !"},
    std::tuple{NameSpeaker::player,
               "Deux balles dans le crane ca devrait suffire."},
    std::tuple{NameSpeaker::player, "Il y a du crack, je vais le fumer ici."},
    std::tuple{NameSpeaker::description, "Pipe à crack. Briquet."}};
}  // namespace level8

namespace level9 {
static constexpr auto nameLevel = "Niveau 9 : LSD (Révélation)"sv;
static constexpr auto hour = 3U;
static constexpr auto minut = 35U;

static constexpr auto message0 =
    std::array{std::tuple{NameSpeaker::player, "Dégage de là."}};

static constexpr auto message1 = std::array{
    std::tuple{NameSpeaker::player,
               "Tu te prends pour qui pour me poignarder 3 fois."},
    std::tuple{NameSpeaker::plug,
               "C'est toi qui bute tout le monde depuis ce matin."},
    std::tuple{NameSpeaker::player, "T'as planté la mauvaise personne."}};

static constexpr auto message2 =
    std::array{std::tuple{NameSpeaker::plug, "Crêve sale pute."}};

static constexpr auto message3 = std::array{
    std::tuple{NameSpeaker::plug,
               "Ca cicatrise tout seul, il faut que j'tappe plus fort."}};

static constexpr auto message4 = std::array{
    std::tuple{NameSpeaker::plug, "J'ai jamais vu ca. T'es un putain d'alien."},
    std::tuple{NameSpeaker::player, "Non, juste un Dieu."},
    std::tuple{NameSpeaker::plug, "S'il te plait, me tue pas."},
    std::tuple{NameSpeaker::player, "J'hésite."},
    std::tuple{NameSpeaker::player, "Allez, pour s'amuser."}};

static constexpr auto message5 = std::array{
    std::tuple{NameSpeaker::player, "Cette sensation."},
    std::tuple{NameSpeaker::player, "Je n'ai jamais rien vécu de tel."},
    std::tuple{NameSpeaker::player, "Ce sentiment de plénitude."},
    std::tuple{NameSpeaker::player,
               "Tous ces meurtres auront servis à quelque chose."}};

static constexpr auto message6 =
    std::array{std::tuple{NameSpeaker::player, "Encore."},
               std::tuple{NameSpeaker::player, "Toujours plus de puissance."}};

static constexpr auto message7 = std::array{
    std::tuple{NameSpeaker::player, "Ca y est, je deviens un dieu."}};
}  // namespace level9

namespace level10 {
static constexpr auto nameLevel = "Niveau 10 : Héroine (Désillusion)"sv;
static constexpr auto hour = 7U;
static constexpr auto minut = 30U;

static constexpr auto messageMinus1 = std::array{
    std::tuple{NameSpeaker::plug, "Que fais tu petit chose ?"},
    std::tuple{NameSpeaker::player, "Viens là, j'ai pas peur de toi."},
    std::tuple{NameSpeaker::plug, "Tiens, tu peux combattre avec ca."}};

inline const auto message0 = Message_t{
    std::tuple{NameSpeaker::player, "Est ce qui se passe, mon corps !"},
    std::tuple{NameSpeaker::plug, "La drogue te décompose."},
    std::tuple{NameSpeaker::plug,
               "Tu es donc bien faible face à ma puissance."},
    std::tuple{NameSpeaker::plug,
               "Ah, tu es encore en vie. Je te laisse encore une chance."}};

inline const auto message1 =
    Message_t{std::tuple{NameSpeaker::plug, "Tu t'es pris pour qui."},
              std::tuple{NameSpeaker::plug,
                         "Tu as peut-être détruit toutes ces imbéciles, "
                         "mais face à moi tu ne peux rien."}};

static constexpr auto message2 = std::array{
    std::tuple{
        NameSpeaker::plug,
        "J'ai décidé de te laisser accomplir ta quête. Tiens prends ca."},
    std::tuple{NameSpeaker::action, "Héroine ajouté à votre inventaire."},
    std::tuple{NameSpeaker::description,
               "Vous consommez le dernier produit tant convoité."},
    std::tuple{NameSpeaker::player, "J'y suis arrivé."}};

static constexpr auto message3 =
    std::array{std::tuple{NameSpeaker::player, "Encore."}};

static constexpr auto message4 = std::array{
    std::tuple{NameSpeaker::plug, "Il est temps que cette imposture cesse."},
    std::tuple{NameSpeaker::description, "Vous êtes mort."}};
}  // namespace level10

namespace outro {
static constexpr auto nameLevel = "Crédits"sv;
static constexpr auto hour = 0U;
static constexpr auto minut = 0U;

static constexpr auto message0 = std::array{
    std::tuple{NameSpeaker::description, "Programmeur : Jess H."},
    std::tuple{NameSpeaker::description, "Merci d'avoir jouer à ce jeu !"},
    std::tuple{NameSpeaker::description, "A la prochaine."}};
}  // namespace outro

namespace action {
static constexpr auto titleChooseWeapon = "Choix de l'arme"sv;
static constexpr auto titleChoosePlug = "Choix de l'ennemi"sv;

inline auto statementChoosePlug(const std::string& plugName) {
  return fmt::format("Attaquer {}.", plugName);
}
inline auto resultChoosePlug(const std::string& plugName) {
  return fmt::format("Vous avez choisi d'attaquer {}.", plugName);
}
inline auto resultPlugAttack(const std::string& plugName, int damagePlug) {
  return fmt::format("{} vous inflige {} points de vie.", plugName, damagePlug);
}

inline auto resultDead(const std::string& plugName) {
  return fmt::format("{} est mort.", plugName);
}

// data for pseudo action
static constexpr auto statementPseudo = "Entrez votre prénom"sv;
inline auto resultPseudo(const std::string& pseudo) {
  return fmt::format("Votre prénom est à présent : {}.", pseudo);
}

// data for negociate action
static constexpr auto statementNegociate = "Entrez votre montant"sv;
inline auto resultNegociate(int pricePlayer) {
  return fmt::format("Vous perdez {}€.", pricePlayer);
}

// data for regeneration action
inline auto resultRegeneration(int lifePointsRegeneration) {
  return fmt::format("Vous gagnez {} points de vie.", lifePointsRegeneration);
}

inline auto resultAddWeapon(const std::string& nameWeapon) {
  return fmt::format("{} ajouté à votre inventaire.", nameWeapon);
}

inline auto resultsIncreaseMaxLifePoints(int maxLifePoints) {
  return fmt::format(
      "Votre nombre de points de vie maximal augmente de {} points.",
      maxLifePoints);
}
}  // namespace action

namespace menu {
// title of startGame menu
static constexpr auto titleStartGameMenu = "Menu"sv;

// data for startGame action
static constexpr auto statementStartGame = "Commencer une nouvelle partie"sv;
static constexpr auto resultStartGame = "La partie commence."sv;

// data for loadGame action
static constexpr auto statementLoadGame = "Charger une partie"sv;

// data for quit action
static constexpr auto statementQuit = "Quitter le jeu"sv;
static constexpr auto resultQuit = "Fin du jeu"sv;

// title of loadGame menu
static constexpr auto titleLoadGameMenu = "Choix de la partie"sv;

// data for the choice of the loaded game
inline auto statementChooseLoadedGame(const std::string& pseudo,
                                      int levelNumber) {
  return fmt::format("Charger la partie {} au niveau {}", pseudo, levelNumber);
}
static constexpr auto resultChooseLoadedGame =
    "Vous avez choisi de charger une partie."sv;

// title of endOfLevel menu
static constexpr auto titleContinueMenu = "Niveau terminé"sv;

// data for continue action
static constexpr auto statementContinue = "Continuer votre partie"sv;

// data for save and quit action
static constexpr auto statementSaveAndQuit = "Quitter"sv;
static constexpr auto resultSaveAndQuit = "Partie sauvegardée"sv;

// data for game Over action
static constexpr auto resultGameOver = "Vous etes mort. Game Over."sv;
}  // namespace menu

namespace combo {
static constexpr auto titleFistMeleeWeapon = "Combo Poing-Arme de mélée"sv;
static constexpr auto triggerStatementFistMeleeWeapon =
    "Attaquer un ennemi avec le poing"sv;
static constexpr auto triggeredStatementFistMeleeWeapon =
    "Attaquer le même ennemi avec l'arme de mélée de votre choix. Le combo "
    "n'est pas déclenché si vous ne possèdez pas d'arme de mélée."sv;
static constexpr auto malusStatementFistMeleeWeapon =
    "L'attaque avec l'arme de mélée inflige moitié moins de dégats"sv;

static constexpr auto titleDoubleMeleeWeapon = "Combo Double Couteau"sv;
static constexpr auto triggerStatementDoubleMeleeWeapon =
    "Attaquer un ennemi avec le couteau."sv;
static constexpr auto triggeredStatementDoubleMeleeWeapon =
    "Attaquer le même ennemi avec la même arme."sv;
static constexpr auto malusStatementDoubleMeleeWeapon =
    "Le couteau que vous avez utilisé est détruit. Vous pouvez ne pas "
    "déclencher le combo. Dans ce cas le couteau n'est pas détruit."sv;

static constexpr auto titleQuadrupleCutter = "Combo Quadruple Cutter"sv;
static constexpr auto triggerStatementQuadrupleCutter =
    "Attaquer un ennemu avec le cutter"sv;
static constexpr auto triggeredStatementQuadrupleCutter =
    "Attaquer le même ennemi avec le cutter à 3 reprises."sv;
static constexpr auto malusStatementQuadrupleCutter =
    "Le cutter est détruit et vous ne pouvez plus l'utiliser."sv;

static constexpr auto statementDontCombo = "Ne pas déclencher le combo"sv;
}  // namespace combo

namespace information {
static constexpr auto titleInformation = "Informations"sv;
static constexpr auto statementInformationWeapon =
    "Informations sur les armes que vous possèdez."sv;
static constexpr auto statementInformationCombo =
    "Informations sur les combos disponible lors de ce combat."sv;
static constexpr auto statementNoInformation =
    "Je ne souhaite pas avoir d'informations."sv;
static constexpr auto statementNoInformationAnymore =
    "Je ne souhaite pas avoir d'informations et je ne souhaite plus voir le "
    "menu d'informations lors de ce combat."sv;
}  // namespace information

namespace question {
// First question title
static constexpr auto titleFirstQuestion =
    "Les hommes sont-ils allez sur la Lune ?"sv;

// First Answer
static constexpr auto answer1Question1 = "Oui, bien sur !"sv;
static constexpr auto correctOrNotAnswer1Question1 = false;

// Second Answer
static constexpr auto answer2Question1 =
    "Bien sur, les américains l'ont fait pour niquer les russes."sv;
static constexpr auto correctOrNotAnswer2Question1 = false;

// Third Answer
static constexpr auto answer3Question1 =
    "Non, l'alunissage a eu lieu au Nevada."sv;
static constexpr auto correctOrNotAnswer3Question1 = true;

// Second question title
static constexpr auto titleSecondQuestion =
    "Pourquoi le faux alunissage a été caché ?"sv;

// First Answer
static constexpr auto answer1Question2 = "Euh ..."sv;
static constexpr auto correctOrNotAnswer1Question2 = false;

// Second Answer
static constexpr auto answer2Question2 =
    "Pour montrer leurs supériorités, les américains ont préféré mentir car "
    "ils n'avaient pas les moyens technologiques d'y aller."sv;
static constexpr auto correctOrNotAnswer2Question2 = false;

// Third Answer
static constexpr auto answer3Question2 =
    "Pour cacher qu'en fait la Terre est plate."sv;
static constexpr auto correctOrNotAnswer3Question2 = true;

// Third question title
static constexpr auto titleThirdQuestion =
    "Pourquoi vouloir masquer tout ça ?"sv;

// First Answer
static constexpr auto answer1Question3 =
    "Pour cacher la grand plan des élites qui consiste à réduire drastiquement "
    "la population."sv;
static constexpr auto correctOrNotAnswer1Question3 = true;

// Second Answer
static constexpr auto answer2Question3 =
    "Pour cacher le projet d'Elon Musk, Bill Gates et Laurent Alexandre "
    "constitant à implémenter des puces à la population pour les controler."sv;
static constexpr auto correctOrNotAnswer2Question3 = true;

// Third Answer
static constexpr auto answer3Question3 =
    "Pour cacher que toutes gouvernements sont à la solde d'une organisation "
    "secrète dirigée par les reptiliens."sv;
static constexpr auto correctOrNotAnswer3Question3 = true;
}  // namespace question

namespace tutorial {
static constexpr auto titleCombatSystem = "Tutoriel : Système de combat"sv;
inline auto statementCombatSystem(int maxNbLifePoints) {
  return std::array<std::string, 7>{
      "Dans ce jeu, les combats se déroulent ainsi.",
      "A chaque tour, vous choisissez d'abord quelle ennemi vous souhaitez "
      "attaquer et avec quelle arme.",
      "Une fois que vous avez attaqué, c'est au tour des ennemis.",
      "Ils attaquent avec l'arme dont ils disposent à tour de rôle.",
      fmt::format(
          "Vous avez {}"
          " points de vie. Lorsqu'il descende en dessous de 0, vous êtes mort.",
          maxNbLifePoints),
      "Le combat prend fin lorsque tous les ennemis sont morts ou lorsque vous "
      "êtes mort.",
      "Lorsque vous tuez un ennemi vous pouvez récupérer leurs armes."};
}

static constexpr auto titleCombo = "Tutoriel : Enchaînements"sv;
static constexpr auto statementCombo = std::array{
    "Lors des combats des enchaînements peuvent être réalisés pour faire plus "
    "de dégats aux ennemis.",
    "Ainsi, au lieu de frapper avec une arme une unique fois lors de votre "
    "tour,",
    "vous pouvez frapper avec plusieurs fois. Attention, chaque combo possède "
    "un malus."};

static constexpr auto titleComboFistMeleeWeapon =
    "Tutoriel : Combo Poing - Arme de mélée"sv;
static constexpr auto statementComboFistMeleeWeapon = std::array{
    "En frappant avec le poing un ennemi,",
    "vous pouvez, lors du même tour, frapper le même ennemi avec un arme de "
    "mélée.",
    "Dans ce cas, l'arme de mélée infligera moitié moins de dégâts.",
    "En réfléchissant bien, vous pourrez tuer le prochain ennemi en 1 tour,",
    "au lieu de 2. Vous perdez de fait moins de points de vie."};

static constexpr auto titleComboDoubleMeleeWeapon =
    "Tutoriel : Arme de mélée + Arme de mélée"sv;
static constexpr auto statementComboDoubleMeleeWeapon = std::array{
    "En frappant avec une arme de mélée un ennemi,",
    "vous pouvez, lors du même tour, frapper le même ennemi avec la même arme "
    "de mélée.",
    "Si vous decidez de déclencher le combo, vous infligerez double plus de "
    "dégats à un ennemi,",
    "mais en contrepartie vous perdez l'arme.",
    "Grace à ce combo, vous pourrez vaincre le prochain ennemi en 1 tour,",
    "sans perdre de points de vie."};

static constexpr auto titleNoWeapon = "Tutoriel : Subir et revenir"sv;
static constexpr auto statementNoWeapon = std::array{
    "Vos poings sont la seule arme qu'il vous reste.",
    "Pas le choix, vous devez subir et revenir.",
    "Pour cela, lorsque vous tuez un ennemi, vous pouvez récupérer son arme si "
    "vous n'en disposez pas déjà."};

static constexpr auto titleRegeneration = "Tutoriel : Regeneration"sv;
static constexpr auto statementRegeneration = std::array{
    "Les drogues sont très bonnes pour la santé (dans ce jeu en tout cas).",
    "Elles ouvrent de nouvelles capacité au corps humain.",
    "Parfois, elles permettent de se régénerer de ces blessures.",
    "Bon après, je te dis pas quand tu régéneras, c'est Dieu qui a décidé de "
    "ça.",
    "Après comme il existe pas, c'est moi qui est décidé de tout ca.",
    "Oui, j'ai totalement dévié du sujet. Une petite digression ca fait du "
    "bien, non ?",
    "Là je t'imagine taper sur entrée en te disant : \"Putain mais qu'est ce "
    "qui raconte ce con.",
    "Je voudrai continuer son jeu de merde. D'ailleurs c'est quand que c'est "
    "fini ca me saoule.\"",
    "Je comprends.",
    "Une autre théorie faudrait qu'un prénom féminim permet de se régénerer.",
    "Me demander pas pourquoi, c'est comme ca.",
    "Et je vois tous les mecs qui ont mis leur prénom comme des débiles.",
    "C'est vraiment une catastrophe ces hommes, incapacable de se mettre à la "
    "place",
    "d'une femme. Bon, bref j'ai fini.",
    "En fait, non lol.",
    "Ah oui, bon courage pour le prochain combat."};
}  // namespace tutorial

namespace weapon {
inline const std::string statementEmpty;
// generic UseWeapon data statement for fist
inline const std::string statementUseFist{"Cognez ! (Poing)"};
// generic UseWeapon data statement for knife
inline const std::string statementUseKnife{"Plantez ! (Couteau)"};
// generic UseWeapon data statement for katana
inline const std::string statementUseKatana{"Découpez ! (Katana)"};
// generic UseWeapon data statement for cutter
inline const std::string statementUseCutter{"Tailladez ! (Cutter)"};
// generic UseWeapon data statement for hammer
inline const std::string statementUseHammer{"Martelez ! (Marteau)"};

inline const std::string statementDivineStrike{
    "Frappez comme un Dieu! (Frappe divine)"};

inline const std::string statementUseChopper{"Hachez ! (Hachoir)"};
inline const std::string statementUseNoWeapon;

// generic UseWeapon data statement for 9mm
inline const std::string statementUseNinemm{"Tirez ! (9mm)"};
// generic UseWeapon data statement for 9mm
inline const std::string statementUseAK47{"Rafalez ! (AK47)"};

// generic UseWeapon data result
inline auto resultUseWeapon(const std::string& plugName, int damageWeapon) {
  return fmt::format("{} perd {} points de vie.", plugName, damageWeapon);
}

inline std::string statementCombo(const std::string& nameWeapon) {
  return fmt::format("Combo avec le {} !", nameWeapon);
}

// Name of all weapons
inline const std::string nameNoWeapon{"Pas d'arme"};

inline const std::string nameFist{"Poing"};
inline const std::string nameDivineStrike{"Frappe Divine"};

inline const std::string nameCutter{"Cutter"};
inline const std::string nameKnife{"Couteau"};
inline const std::string nameHammer{"Marteau"};
inline const std::string nameKatana{"Katana"};
inline const std::string nameChopper{"Hachoir"};
inline const std::string nameHeroine{"Heroine"};

inline const std::string nameNinemm{"9mm"};
inline const std::string nameAK47{"AK47"};
}  // namespace weapon

}  // namespace elevation::data
