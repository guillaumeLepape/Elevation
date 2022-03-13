#ifndef FRENCH_DATA_H
#define FRENCH_DATA_H

#include <fmt/core.h>

#include <string>
#include <tuple>
#include <vector>

namespace data {
using namespace std::literals;

enum class NameSpeaker { player = 0, plug, description, action };
using Message_t = std::vector<std::tuple<NameSpeaker, std::string>>;

namespace Introduction {
// Introduction data
// ***********************************

// Header data
static constexpr auto nameLevel = "Introduction : Dur réveil"sv;
static constexpr auto hour = unsigned{13};
static constexpr auto minut = unsigned{12};

// Messages data
inline Message_t message0 = {
    {NameSpeaker::description,
     "Vous vous réveillez chez vous avec de vagues souvenirs de la soirée que "
     "vous avez passé chez votre amie."},
    {NameSpeaker::player,
     "C'est certainement dû à la consommation massive et diverse de drogues."},
    {NameSpeaker::player,
     "Il me faut persister sur cette lancée en allant m'approvisionnez auprès "
     "de mes 10 dealeurs préférés."},
    {NameSpeaker::description,
     "La consommation de ces 10 drogues est votre seul moyen de changer "
     "radicalement votre existence."}};

inline Message_t message1 = {
    {NameSpeaker::player,
     "Je ne souviens plus de mon prénom. Comment je m'appelle ?"}};

inline Message_t message2 = {
    {NameSpeaker::player, "Euh, je suis plutôt sûr d'être une femme."}};

inline Message_t message3 = {{NameSpeaker::player, "Ce prénom n'existe pas."}};

inline Message_t message4(const std::string& pseudo) {
  return {{NameSpeaker::player,
           fmt::format("Bon d'accord {}, ça fera l'affaire.", pseudo)}};
}
}  // namespace Introduction

namespace Level1 {
// Level 1 data
// ***********************************

// Header data
static constexpr auto nameLevel = "Niveau 1 : Beuh"sv;
static constexpr auto hour = unsigned{14};
static constexpr auto minut = unsigned{35};

// Messages data
inline Message_t message0(const std::string& pseudo,
                          const std::string& plugName, int pricePlug) {
  return {{NameSpeaker::player, "Bon, c'est parti."},
          {NameSpeaker::description, "Vous arrivez en bas du batiment"},
          {NameSpeaker::plug, fmt::format("Ca va, {} ?", pseudo)},
          {NameSpeaker::player, fmt::format("Et toi, {} ?", plugName)},
          {NameSpeaker::plug,
           fmt::format("Comme d'habitude ? C'est {}€.", pricePlug)},
          {NameSpeaker::player, "Tiens."},
          {NameSpeaker::action, fmt::format("Vous perdez {}€.", pricePlug)},
          {NameSpeaker::plug, "Bonne journée."},
          {NameSpeaker::player, "A la prochaine."},
          {NameSpeaker::description, "Roule. Fume."}};
}
}  // namespace Level1

namespace Level2 {
// Level 2 data
// ***********************************

// Header data
static constexpr auto nameLevel = "Niveau 2 : Coke"sv;
static constexpr auto hour = unsigned{15};
static constexpr auto minut = unsigned{10};

// Messages data
inline Message_t message0(const std::string& plugName, int pricePlug) {
  return {{NameSpeaker::player, fmt::format("Salut, {}.", plugName)},
          {NameSpeaker::plug, "Ca va ? Tu cherches quoi ?"},
          {NameSpeaker::player, "De la C."},
          {NameSpeaker::plug, fmt::format("C'est {}€ le gramme.", pricePlug)},
          {NameSpeaker::player, "Putain, c'est un peu cher."},
          {NameSpeaker::plug, "C'est pas négociable."},
          {NameSpeaker::player, "Aller j'ai pas masse de tunes."}};
}

inline Message_t message1 = {
    {NameSpeaker::plug, "Ok, je veux bien négocier. Tu proposes combien ?"}};

inline Message_t message2 = {{NameSpeaker::plug, "T'es con ou quoi ?"}};

inline Message_t message3 = {
    {NameSpeaker::plug, "Je peux pas me permettre ca."}};

inline Message_t message4 = {
    {NameSpeaker::plug, "Ca me convient. Tiens. A la prochaine."}};

inline Message_t message5 = {{NameSpeaker::player, "Merci. Salut."},
                             {NameSpeaker::description, "Carte VISA. Sniffe."}};
}  // namespace Level2

namespace Level3 {
static constexpr auto nameLevel = "Niveau 3 : Shit"sv;
static constexpr auto hour = unsigned{16};
static constexpr auto minut = unsigned{4};

inline Message_t message0 = {
    {NameSpeaker::description, "Vous arrivez en bas du bloc."},
    {NameSpeaker::player, "Salut !"},
    {NameSpeaker::plug, "Tu veux quoi."},
    {NameSpeaker::player, "T'as quelque chose pour 10 balles."},
    {NameSpeaker::plug, "Non, c'est minimum 20 balles."},
    {NameSpeaker::player, "Ok, ca va être juste."},
    {NameSpeaker::plug, "C'est 20 balles ou rien."},
    {NameSpeaker::description, "Vous vous taisez. Vous serrez le poing."},
    {NameSpeaker::plug,
     "Qu'est ce qui t'arrive, meuf ? Tu as l'air grave défoncée."},
    {NameSpeaker::description, "Il a raison."},
    {NameSpeaker::description,
     "J'ai pas le temps pour ça. Le sang me monte à la tête."}};

inline Message_t message1 = {
    {NameSpeaker::plug, "Qu'est ce qui te prends, sale pute."},
    {NameSpeaker::description, "Vous venez de le frapper."},
    {NameSpeaker::plug, "Tu peux pas juste payer ta dose et te casser."}};

inline Message_t message2(const std::string& plugName) {
  return {{NameSpeaker::description,
           fmt::format("Vous vous placez sur le torse de {}.", plugName)},
          {NameSpeaker::plug, "Batard !"}};
}

inline Message_t message3 = {{NameSpeaker::plug, "Salope !"}};

inline Message_t message4 = {
    {NameSpeaker::plug, "Ah."},
    {NameSpeaker::description, "Le produit tombe au sol ainsi qu'un couteau."},
    {NameSpeaker::description,
     "Vous mettez le shit dans votre poche et saisissez le couteau."}};

inline Message_t message5 = {{NameSpeaker::description, "Roule. Fume."}};
}  // namespace Level3

namespace Level4 {
static constexpr auto nameLevel = "Niveau 4 : Lean"sv;
static constexpr auto hour = unsigned{17};
static constexpr auto minut = unsigned{15};

inline Message_t message0(const std::string& pseudo) {
  return {
      {NameSpeaker::description,
       "Vous arrivez en bas d'un petit appartement où vous trouverez le "
       "produit tant convoité."},
      {NameSpeaker::description, "Vous sonnez à la porte."},
      {NameSpeaker::plug, fmt::format("Ca va {} ?", pseudo)},
      {NameSpeaker::player, "Tranquille."},
      {NameSpeaker::description,
       "La porte s'ouvre. Vous montez jusqu'à l'appartement et y pénétrez."},
      {NameSpeaker::plug,
       "Viens par ici, je peux te faire le produit gratuitement."},
      {NameSpeaker::player, "Gratuit, c'est cool."},
      {NameSpeaker::plug, "Mais tu dois répondre à quelques questions avant."},
      {NameSpeaker::player, "Ok."},
      {NameSpeaker::plug, "Je veux savoir si tu comprends les liens cachés."},
      {NameSpeaker::player, "Euh ... ok."},
      {NameSpeaker::plug, "Première question."}};
}

inline Message_t message1 = {
    {NameSpeaker::plug, "Non, c'est pas ça, réessaie."}};

inline Message_t message2 = {
    {NameSpeaker::plug, "Yep, c'est ca, question suivante."}};

inline Message_t message3 = {{NameSpeaker::plug, "Quelle niveau ! Tiens."},
                             {NameSpeaker::description, "Gobelet. Sip."}};
}  // namespace Level4

namespace Level5 {
static constexpr auto nameLevel = "Niveau 5 : Xanax"sv;
static constexpr auto hour = unsigned{19};
static constexpr auto minut = unsigned{2};

inline Message_t message0 = {
    {NameSpeaker::description,
     "Vous arrivez en bas du Bones factory tenu par le "
     "celebre gang des Bones."},
    {NameSpeaker::plug, "Tu rentres pas."}};

inline Message_t message1 = {{NameSpeaker::player, "Je vais te buter."}};

inline Message_t message2 = {
    {NameSpeaker::description,
     "Après avoir tabasser le pauvre homme, vous pénetrez dans le batiment."},
    {NameSpeaker::player, "Fait chier, je controle plus grand chose là."},
    {NameSpeaker::plug, "Hey, toi là."},
    {NameSpeaker::player, "Et merde."}};

inline Message_t message3 = {
    {NameSpeaker::player,
     "Encore une personne tuée de ma main, pas le choix faut que je continue."},
    {NameSpeaker::player,
     "N'empêche j'ai plus d'armes, comment je vais faire."},
    {NameSpeaker::description,
     "Vous ouvrez la porte qui va vous mener au produit tant convoité."},
    {NameSpeaker::plug, "Non pas ce fou furieux !"}};

inline Message_t message4 = {
    {NameSpeaker::player, "Putain, il m'a fait mal ce batard."},
    {NameSpeaker::player,
     "Au moins, j'ai récupéré son couteau, ca pourra mettre utile."}};

inline Message_t message5 = {
    {NameSpeaker::player, "Qu'est ce qu'il se passe ? Je me sens mieux là."},
    {NameSpeaker::player, "Ca doit être les effets de la drogue."}};

inline Message_t message6 = {
    {NameSpeaker::player, "En allant par là, je devrais trouver la drogue."},
    {NameSpeaker::plug,
     "Putain c'est la pétasse qui a buté tout le monde. On s'la fait."},
    {NameSpeaker::player,
     "Enfin. J'ai plus qu'à buter ces 3 batards et c'est torché."}};

inline Message_t message7 = {
    {NameSpeaker::description,
     "Après avoir buter tout le monde, vous ramassez les 3 cachetons qui reste "
     "dans la poche du kamikaze."},
    {NameSpeaker::player, "Tout ca pour."},
    {NameSpeaker::description, "Cachetons sur la langue. Verre d'eau."}};
}  // namespace Level5

namespace Level6 {
static constexpr auto nameLevel = "Niveau 6 : Champis"sv;
static constexpr auto hour = unsigned{21};
static constexpr auto minut = unsigned{10};

inline Message_t message0 = {
    {NameSpeaker::player,
     "Avec toutes ces histoires, il est temps de rentrer chez soi."},
    {NameSpeaker::description,
     "Arrivée chez vous, vous vous asseyez sur le canapé."},
    {NameSpeaker::player,
     "Ca tourne, sa mère. J'ai pas fini mais faut que je me repose."},
    {NameSpeaker::player, "Il me reste quelque champis, parfait."},
    {NameSpeaker::description, "Poele. Soupe de champis"},
    {NameSpeaker::player, "Zzzzzzz."},
    {NameSpeaker::player, "Zzzzzzz."},
    {NameSpeaker::player, "Zzzzzzz."}};
}  // namespace Level6

namespace Level7 {
static constexpr auto nameLevel = "Niveau 7 : Kétamine"sv;
static constexpr auto hour = unsigned{0};
static constexpr auto minut = unsigned{10};

inline Message_t message0 = {
    {NameSpeaker::description, "Boum."},
    {NameSpeaker::player,
     "AHHHHHHHHHHHHHH. QU'EST CE QUI SE PASSE PUTAIN DE MERDE !"},
    {NameSpeaker::description, "Kaboom."},
    {NameSpeaker::plug, "CC je suis là pour te buter."}};

inline Message_t message1 = {
    {NameSpeaker::player, "Tu as pensé à mon sommeil."},
    {NameSpeaker::player,
     "Au moins, tu as des trucs sur toi. De la ké parfait."},
    {NameSpeaker::description, "Feuille à rouler. Para."}};
}  // namespace Level7

namespace Level8 {
static constexpr auto nameLevel = "Niveau 8 : Crack (Interlude)"sv;
static constexpr auto hour = unsigned{2};
static constexpr auto minut = unsigned{12};

inline Message_t message0(const std::string& plugName) {
  return {
      {NameSpeaker::player, fmt::format("Ca part en couilles là. Il faut que "
                                        "j'aille voir {} pour qu'elle m'aide.",
                                        plugName)},
      {NameSpeaker::player,
       "J'ai pas de sang sur moi, je peux tappe des hallus maintenant."},
      {NameSpeaker::description,
       fmt::format("Malgré votre état, vous arrivez enfin devant chez {}, "
                   "l'une de vos plus fidèles amies.",
                   plugName)},
      {NameSpeaker::description,
       "Arrivé devant la porte, celle-ci s'ouvre par miracle."},
      {NameSpeaker::plug, "Pourquoi ?"},
      {NameSpeaker::player, "Ah merde mon couteau."},
      {NameSpeaker::description,
       "Effectivement elle a un couteau dans la poitrine."},
      {NameSpeaker::plug, "Après tout ce que j'ai fait pour toi."},
      {NameSpeaker::player, "Tu souffres, faut que j'abrège tes souffrances."},
      {NameSpeaker::player, "Avec ce gun c'est parfait."}};
}

inline Message_t message1 = {
    {NameSpeaker::description, "BANG ! "},
    {NameSpeaker::description, "PAW !"},
    {NameSpeaker::player, "Deux balles dans le crane ca devrait suffire."},
    {NameSpeaker::player, "Il y a du crack, je vais le fumer ici."},
    {NameSpeaker::description, "Pipe à crack. Briquet."}};
}  // namespace Level8

namespace Level9 {
static constexpr auto nameLevel = "Niveau 9 : LSD (Révélation)"sv;
static constexpr auto hour = unsigned{3};
static constexpr auto minut = unsigned{35};

inline Message_t message0 = {{NameSpeaker::player, "Dégage de là."}};

inline Message_t message1 = {
    {NameSpeaker::player, "Tu te prends pour qui pour me poignarder 3 fois."},
    {NameSpeaker::plug, "C'est toi qui bute tout le monde depuis ce matin."},
    {NameSpeaker::player, "T'as planté la mauvaise personne."}};

inline Message_t message2 = {{NameSpeaker::plug, "Crêve sale pute."}};

inline Message_t message3 = {
    {NameSpeaker::plug,
     "Ca cicatrise tout seul, il faut que j'tappe plus fort."}};

inline Message_t message4 = {
    {NameSpeaker::plug, "J'ai jamais vu ca. T'es un putain d'alien."},
    {NameSpeaker::player, "Non, juste un Dieu."},
    {NameSpeaker::plug, "S'il te plait, me tue pas."},
    {NameSpeaker::player, "J'hésite."},
    {NameSpeaker::player, "Allez, pour s'amuser."}};

inline Message_t message5 = {
    {NameSpeaker::player, "Cette sensation."},
    {NameSpeaker::player, "Je n'ai jamais rien vécu de tel."},
    {NameSpeaker::player, "Ce sentiment de plénitude."},
    {NameSpeaker::player, "Tous ces meurtres auront servis à quelque chose."}};

inline Message_t message6 = {
    {NameSpeaker::player, "Encore."},
    {NameSpeaker::player, "Toujours plus de puissance."}};

inline Message_t message7 = {
    {NameSpeaker::player, "Ca y est, je deviens un dieu."}};
}  // namespace Level9

namespace Level10 {
static constexpr auto nameLevel = "Niveau 10 : Héroine (Désillusion)"sv;
static constexpr auto hour = unsigned{7};
static constexpr auto minut = unsigned{30};

inline Message_t messageMinus1 = {
    {NameSpeaker::plug, "Que fais tu petit chose ?"},
    {NameSpeaker::player, "Viens là, j'ai pas peur de toi."},
    {NameSpeaker::plug, "Tiens, tu peux combattre avec ca."}};

inline Message_t message0 = {
    {NameSpeaker::player, "Est ce qui se passe, mon corps !"},
    {NameSpeaker::plug, "La drogue te décompose."},
    {NameSpeaker::plug, "Tu es donc bien faible face à ma puissance."},
    {NameSpeaker::plug,
     "Ah, tu es encore en vie. Je te laisse encore une chance."}};

inline Message_t message1 = {{NameSpeaker::plug, "Tu t'es pris pour qui."},
                             {NameSpeaker::plug,
                              "Tu as peut-être détruit toutes ces imbéciles, "
                              "mais face à moi tu ne peux rien."}};

inline Message_t message2 = {
    {NameSpeaker::plug,
     "J'ai décidé de te laisser accomplir ta quête. Tiens prends ca."},
    {NameSpeaker::action, "Héroine ajouté à votre inventaire."},
    {NameSpeaker::description,
     "Vous consommez le dernier produit tant convoité."},
    {NameSpeaker::player, "J'y suis arrivé."}};

inline Message_t message3 = {{NameSpeaker::player, "Encore."}};

inline Message_t message4 = {
    {NameSpeaker::plug, "Il est temps que cette imposture cesse."},
    {NameSpeaker::description, "Vous êtes mort."}};
}  // namespace Level10

namespace Outro {
static constexpr auto nameLevel = "Crédits"sv;
static constexpr auto hour = unsigned{0};
static constexpr auto minut = unsigned{0};

inline Message_t message0 = {
    {NameSpeaker::description, "Programmeur : Jess H."},
    {NameSpeaker::description, "Merci d'avoir jouer à ce jeu !"},
    {NameSpeaker::description, "A la prochaine."}};
}  // namespace Outro

namespace Action {
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
}  // namespace Action

namespace Menu {
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
}  // namespace Menu

namespace Combo {
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
}  // namespace Combo

namespace Information {
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
}  // namespace Information

namespace Question {
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
}  // namespace Question

namespace Tutorial {
static constexpr auto titleCombatSystem = "Tutoriel : Système de combat"sv;
inline std::vector<std::string> statementCombatSystem(int maxNbLifePoints) {
  return {
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
inline std::vector<std::string> statementCombo{
    "Lors des combats des enchaînements peuvent être réalisés pour faire plus "
    "de dégats aux ennemis.",
    "Ainsi, au lieu de frapper avec une arme une unique fois lors de votre "
    "tour,",
    "vous pouvez frapper avec plusieurs fois. Attention, chaque combo possède "
    "un malus."};

static constexpr auto titleComboFistMeleeWeapon =
    "Tutoriel : Combo Poing - Arme de mélée"sv;
inline std::vector<std::string> statementComboFistMeleeWeapon{
    "En frappant avec le poing un ennemi,",
    "vous pouvez, lors du même tour, frapper le même ennemi avec un arme de "
    "mélée.",
    "Dans ce cas, l'arme de mélée infligera moitié moins de dégâts.",
    "En réfléchissant bien, vous pourrez tuer le prochain ennemi en 1 tour,",
    "au lieu de 2. Vous perdez de fait moins de points de vie."};

static constexpr auto titleComboDoubleMeleeWeapon =
    "Tutoriel : Arme de mélée + Arme de mélée"sv;
inline std::vector<std::string> statementComboDoubleMeleeWeapon{
    "En frappant avec une arme de mélée un ennemi,",
    "vous pouvez, lors du même tour, frapper le même ennemi avec la même arme "
    "de mélée.",
    "Si vous decidez de déclencher le combo, vous infligerez double plus de "
    "dégats à un ennemi,",
    "mais en contrepartie vous perdez l'arme.",
    "Grace à ce combo, vous pourrez vaincre le prochain ennemi en 1 tour,",
    "sans perdre de points de vie."};

static constexpr auto titleNoWeapon = "Tutoriel : Subir et revenir"sv;
inline std::vector<std::string> statementNoWeapon{
    "Vos poings sont la seule arme qu'il vous reste.",
    "Pas le choix, vous devez subir et revenir.",
    "Pour cela, lorsque vous tuez un ennemi, vous pouvez récupérer son arme si "
    "vous n'en disposez pas déjà."};

static constexpr auto titleRegeneration = "Tutoriel : Regeneration"sv;
inline std::vector<std::string> statementRegeneration{
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
}  // namespace Tutorial

namespace Weapon {
inline std::string statementEmpty{""};
// generic UseWeapon data statement for fist
inline std::string statementUseFist{"Cognez ! (Poing)"};
// generic UseWeapon data statement for knife
inline std::string statementUseKnife{"Plantez ! (Couteau)"};
// generic UseWeapon data statement for katana
inline std::string statementUseKatana{"Découpez ! (Katana)"};
// generic UseWeapon data statement for cutter
inline std::string statementUseCutter{"Tailladez ! (Cutter)"};
// generic UseWeapon data statement for hammer
inline std::string statementUseHammer{"Martelez ! (Marteau)"};

inline std::string statementDivineStrike{
    "Frappez comme un Dieu! (Frappe divine)"};

inline std::string statementUseChopper{"Hachez ! (Hachoir)"};
inline std::string statementUseNoWeapon{""};

// generic UseWeapon data statement for 9mm
inline std::string statementUseNinemm{"Tirez ! (9mm)"};
// generic UseWeapon data statement for 9mm
inline std::string statementUseAK47{"Rafalez ! (AK47)"};

// generic UseWeapon data result
inline auto resultUseWeapon(const std::string& plugName, int damageWeapon) {
  return fmt::format("{} perd {} points de vie.", plugName, damageWeapon);
}

inline std::string statementCombo(const std::string& nameWeapon) {
  return fmt::format("Combo avec le {} !", nameWeapon);
}

// Name of all weapons
inline std::string nameNoWeapon{"Pas d'arme"};

inline std::string nameFist{"Poing"};
inline std::string nameDivineStrike{"Frappe Divine"};

inline std::string nameCutter{"Cutter"};
inline std::string nameKnife{"Couteau"};
inline std::string nameHammer{"Marteau"};
inline std::string nameKatana{"Katana"};
inline std::string nameChopper{"Hachoir"};
inline std::string nameHeroine{"Heroine"};

inline std::string nameNinemm{"9mm"};
inline std::string nameAK47{"AK47"};
}  // namespace Weapon

}  // namespace data

#endif