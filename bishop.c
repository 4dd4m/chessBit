#include "bishop.h"

U64 bishopAttacks[64];

U64 maskBishopAttacks(int square){
    U64 board = 0ULL;
    U64 attacks = 0ULL;

    //set piece on board
    setBit(board, square);
    int ranks, files;

    int targetRank = square / 8;
    int targetFile = square % 8;

    for (ranks = targetRank + 1, files = targetFile +1; ranks <= 6 && files <= 6; ranks++, files++) {
        attacks |= (1ULL << (ranks * 8 + files));
    }
    for (ranks = targetRank - 1, files = targetFile +1; ranks >= 1 && files <= 6; ranks--, files++) {
        attacks |= (1ULL << (ranks * 8 + files));
    }
    for (ranks = targetRank + 1, files = targetFile - 1; ranks <= 6 && files >= 1; ranks++, files--) {
        attacks |= (1ULL << (ranks * 8 + files));
    }
    for (ranks = targetRank - 1, files = targetFile - 1; ranks >= 1 && files >= 1; ranks--, files--) {
        attacks |= (1ULL << (ranks * 8 + files));
    }
    return attacks;
}

void initBishopAttacks(){
    for (int square = 0; square < 64; square++) {
        bishopAttacks[square] = maskBishopAttacks(square);
    }
}
