#ifndef CHESSBIT_BISHOP_H
#define CHESSBIT_BISHOP_H

#include "myconstants.h"
#include "macros.h"

extern U64 bishopAttacks[64];

U64 maskBishopAttacks(int square);
void initBishopAttacks();

#endif //CHESSBIT_BISHOP_H
