#include "rook.h"

U64 rookAttacks[64];

U64 maskRookAttacks(int square){
    U64 board = 0ULL;
    U64 attacks = 0ULL;

    //set piece on board
    setBit(board, square);

    int ranks, files;

    int targetRank = square / 8;
    int targetFile = square % 8;

    for (ranks = targetRank + 1; ranks <= 6; ranks++) {
        attacks |= (1ULL << (ranks * 8 + targetFile));
    }
    for (ranks = targetRank - 1; ranks >= 1; ranks--) {
        attacks |= (1ULL << (ranks * 8 + targetFile));
    }

    for (files = targetRank + 1; files <= 6; files++) {
        attacks |= (1ULL << (targetRank * 8 + files));
    }

    for (files = targetRank - 1; files >= 1; files--) {
        attacks |= (1ULL << (targetRank * 8 + files));
    }
    return attacks;
}

void initRookAttacks(){
    for (int square = 0; square < 64; square++) {
        rookAttacks[square] = maskRookAttacks(square);
    }
}
