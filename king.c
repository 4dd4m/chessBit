#include "king.h"

U64 kingAttacks[64];

U64 maskKingAttacks(int square){
    U64 board = 0ULL;
    U64 attacks = 0ULL;

    //set piece on board
    setBit(board, square);

    if(board >> 8) attacks |= (board >> 8);
    if((board >> 9) & not_H_file) attacks |= (board >> 9);
    if((board >> 7) & not_A_file) attacks |= (board >> 7);
    if((board >> 1) & not_H_file) attacks |= (board >> 1);

    if(board << 8) attacks |= (board << 8);
    if((board << 9) & not_A_file) attacks |= (board << 9);
    if((board << 7) & not_H_file) attacks |= (board << 7);
    if((board << 1) & not_A_file) attacks |= (board << 1);

    return attacks;
}

void initKingAttacks(){
    for (int square = 0; square < 64; square++) {
        kingAttacks[square] = maskKingAttacks(square);
    }
}