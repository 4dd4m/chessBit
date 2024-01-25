#ifndef CHESSBIT_BISHOP_H
#define CHESSBIT_BISHOP_H

#include "myconstants.h"
#include "macros.h"

U64 maskBishopAttacks(int square);

// generate bishop attacks in game using some blocking bits
// it stops the ray (including) the first blocking piece
U64 bishopAttacks_in_game(int square, U64 block);
void initBishopAttacks();

#endif //CHESSBIT_BISHOP_H
