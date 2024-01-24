#include "knight.h"

U64 knightAttacks[64];

U64 maskKnightAttacks(int square) {
    U64 board = 0ULL;
    U64 attacks = 0ULL;

    //set piece on board
    setBit(board, square);

    if ((board << 17) & not_A_file) attacks |= (board << 17);
    if ((board << 15) & not_H_file) attacks |= (board << 15);
    if ((board << 10) & not_AB_file) attacks |= (board << 10);
    if ((board << 6) & not_GH_file) attacks |= (board << 6);

    if ((board >> 6) & not_AB_file) attacks |= (board >> 6);
    if ((board >> 10) & not_GH_file) attacks |= (board >> 10);
    if ((board >> 15) & not_A_file) attacks |= (board >> 15);
    if ((board >> 17) & not_H_file) attacks |= (board >> 17);

    return attacks;
}

void initKnightAttacks(){
    for (int square = 0; square < 64; square++) {
        knightAttacks[square] = maskKnightAttacks(square);
    }
}