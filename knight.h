#ifndef CHESSBIT_KNIGHT_H
#define CHESSBIT_KNIGHT_H

#include "myconstants.h"
#include "macros.h"

extern U64 knightAttacks[64];

U64 maskKnightAttacks(int square);
void initKnightAttacks();

#endif //CHESSBIT_KNIGHT_H