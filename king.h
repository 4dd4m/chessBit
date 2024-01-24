#ifndef CHESSBIT_KING_H
#define CHESSBIT_KING_H

#include "myconstants.h"
#include "macros.h"

extern U64 kingAttacks[64];

U64 maskKingAttacks(int square);
void initKingAttacks();


#endif //CHESSBIT_KING_H
