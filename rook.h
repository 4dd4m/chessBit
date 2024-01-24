#ifndef CHESSBIT_ROOK_H
#define CHESSBIT_ROOK_H

#include "myconstants.h"
#include "macros.h"

extern U64 rookAttacks[64];

U64 maskRookAttacks(int square);
void initRookAttacks();

#endif //CHESSBIT_ROOK_H
