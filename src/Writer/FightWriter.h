#ifndef FIGHT_WRITER_H
#define FIGHT_WRITER_H

/*!
    * \file FightWriter.h
*/

#include "Player.h"
#include "Plug.h"

class FightWriter
{
    private:
        const Player* const player_;
        const std::vector<Plug>& plugs_;

        static int numberCharactersString( const std::string& str ); 
        
    public:
        FightWriter( const Player* const player, const std::vector<Plug>& plugs );

        void writeHeader( const int& nbTurns ) const;
        void writeGameBoard() const;
};

#endif