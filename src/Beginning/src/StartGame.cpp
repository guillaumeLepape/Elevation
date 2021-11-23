/*!
 * \file StartGame.cpp
 */

#include "StartGame.h"

#include "Introduction.h"
#include "Level1.h"
#include "Level10.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Level5.h"
#include "Level6.h"
#include "Level7.h"
#include "Level8.h"
#include "Level9.h"
#include "Outro.h"

#include "Options.h"
#include "Player.h"

StartGame::StartGame(const Statement& statement, const Options& options)
    : statement_(statement),
      options_(options),
      indexResultData_(0),
      resultsData_(ResultsData(Player("Joueur", Id::generate(), 0))),
      player_(resultsData_.results()[indexResultData_]) {}

StartGame::StartGame(const Statement& statement, const Options& options,
                     int indexResultData, ResultsData&& resultsData)
    : statement_(statement),
      options_(options),
      indexResultData_(indexResultData),
      resultsData_(std::move(resultsData)),
      player_(resultsData_.results()[indexResultData_]) {}

void StartGame::triggerAction() {
  {
    Introduction introduction(player_, resultsData_, options_);
    introduction.startLevel();
  }
  {
    Level1 level1(player_, resultsData_, options_);
    level1.startLevel();
  }
  {
    Level2 level2(player_, resultsData_, options_);
    level2.startLevel();
  }
  {
    Level3 level3(player_, resultsData_, options_);
    level3.startLevel();
  }
  {
    Level4 level4(player_, resultsData_, options_);
    level4.startLevel();
  }
  {
    Level5 level5(player_, resultsData_, options_);
    level5.startLevel();
  }
  {
    Level6 level6(player_, resultsData_, options_);
    level6.startLevel();
  }
  {
    Level7 level7(player_, resultsData_, options_);
    level7.startLevel();
  }
  {
    Level8 level8(player_, resultsData_, options_);
    level8.startLevel();
  }
  {
    Level9 level9(player_, resultsData_, options_);
    level9.startLevel();
  }
  {
    Level10 level10(player_, resultsData_, options_);
    level10.startLevel();
  }
  {
    Outro outro(player_, resultsData_, options_);
    outro.startLevel();
  }
}
