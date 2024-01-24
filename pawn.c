#include "pawn.h"

// enum board squares
enum {
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1
};

enum {
    white, black
};

U64 pawnAttacks[2][64];

U64 maskPawnAttacks(int square, int sideToMove) {
    U64 board = 0ULL;
    U64 attacks = 0ULL;

    // set piece on board
    setBit(board, square);

    // white pawns
    if (sideToMove == white) {
        if ((board >> 7) & not_A_file)
            attacks |= (board >> 7);
        if ((board >> 9) & not_H_file)
            attacks |= (board >> 9);
    } else { // black pawns
        if ((board << 7) & not_H_file)
            attacks |= (board << 7);
        if ((board << 9) & not_A_file)
            attacks |= (board << 9);
    }

    return attacks;
}

void initPawnAttacks() {
    for (int square = 0; square < 64; square++) {
        pawnAttacks[white][square] = maskPawnAttacks(square, white);
        pawnAttacks[black][square] = maskPawnAttacks(square, black);
    }
}