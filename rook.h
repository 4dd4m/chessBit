#ifndef CHESSBIT_ROOK_H
#define CHESSBIT_ROOK_H

#include "myconstants.h"
#include "macros.h"

U64 maskRookAttacks(int square);

// calculating rook attacks in game with a blocking board
U64 rookAttacks_in_game(int square, U64 blockingBoard);

void initRookAttacks();

#endif //CHESSBIT_ROOK_H
