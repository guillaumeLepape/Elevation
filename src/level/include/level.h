#ifndef LEVEL_FACTORY_H
#define LEVEL_FACTORY_H

#include "introduction.h"
#include "level1.h"
#include "level10.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
#include "level6.h"
#include "level7.h"
#include "level8.h"
#include "level9.h"
#include "outro.h"

using Level = std::variant<Introduction, Level1, Level2, Level3, Level4, Level5,
                           Level6, Level7, Level8, Level9, Level10, Outro>;
inline constexpr std::size_t NB_LEVEL = std::variant_size_v<Level>;

#endif