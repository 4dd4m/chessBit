#ifndef CHESSBIT_HELPERS_H
#define CHESSBIT_HELPERS_H
#include "myconstants.h"

int countBitBoardBits(U64 board);
void boardInBinary(U64 board);

int leastSignificantBoardIndex(U64 board);

U64 setOccupancy(int index, U64 attackMask);

#endif //CHESSBIT_HELPERS_H
