#ifndef FRENCH_DATA_H
#define FRENCH_DATA_H

#include <string>
#include <vector>

namespace data
{
    namespace Introduction
    {
        // Introduction data
        // ***********************************

        // Header data
        static std::string nameLevel = "Introduction : Dur réveil";
        static int hour = 13;
        static int minut = 12;

        // Messages data
        static std::vector<std::vector<std::tuple<std::string, bool, std::string>>> messages = {
            {
                {"description", false, ""},
                {"description", false, ""},
                {"description", false, ""},
                {"description", false, ""},
            },
            {{"player", false, ""}},
            {{"player", false, ""}},
            {{"player", false, ""}},
            {{"player", true, ""}}};
    } // namespace Introduction

    namespace Level1
    {
        // Level 1 data
        // ***********************************

        // Header data
        static std::string nameLevel = "Niveau 1 : Beuh";
        static int hour = 14;
        static int minut = 35;
    } // namespace Level1

    namespace Level2
    {
        static std::string nameLevel = "Niveau 2 : Coke";
        static int hour = 15;
        static int minut = 10;
    } // namespace Level2

    namespace Level3
    {
        static std::string nameLevel = "Niveau 3 : Shit";
        static int hour = 16;
        static int minut = 4;
    } // namespace Level3

    namespace Level4
    {
        static std::string nameLevel = "Niveau 4 : Lean";
        static int hour = 17;
        static int minut = 15;
    } // namespace Level4

    namespace Level5
    {
        static std::string nameLevel = "Niveau 5 : Xanax";
        static int hour = 19;
        static int minut = 2;
    } // namespace Level5
} // namespace data

#endif