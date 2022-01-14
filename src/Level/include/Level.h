#ifndef LEVEL_FACTORY_H
#define LEVEL_FACTORY_H

/*!
 * \file Level.h
 */

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

using Level = std::variant<Introduction, Level1, Level2, Level3, Level4, Level5,
                           Level6, Level7, Level8, Level9, Level10, Outro>;
inline constexpr std::size_t NB_LEVEL = std::variant_size_v<Level>;

#endif