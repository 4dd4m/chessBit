#ifndef CHESSBIT_PAWN_H
#define CHESSBIT_PAWN_H
#include "myconstants.h"
#include "macros.h"

U64 maskPawnAttacks(int square, int sideToMove);
void initPawnAttacks();

#endif //CHESSBIT_PAWN_H
