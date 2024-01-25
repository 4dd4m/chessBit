#include "rook.h"

U64 rookAttacks[64];

const int rookRelevantBits[64] = {
        12, 11, 11, 11, 11, 11, 11, 12,
        11, 10, 10, 10, 10, 10, 10, 11,
        11, 10, 10, 10, 10, 10, 10, 11,
        11, 10, 10, 10, 10, 10, 10, 11,
        11, 10, 10, 10, 10, 10, 10, 11,
        11, 10, 10, 10, 10, 10, 10, 11,
        11, 10, 10, 10, 10, 10, 10, 11,
        12, 11, 11, 11, 11, 11, 11, 12
};

U64 maskRookAttacks(int square) {
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

    for (files = targetFile + 1; files <= 6; files++) {
        attacks |= (1ULL << (targetRank * 8 + files));
    }

    for (files = targetFile - 1; files >= 1; files--) {
        attacks |= (1ULL << (targetRank * 8 + files));
    }
    return attacks;
}

U64 rookAttacks_in_game(int square, U64 blockingBoard) {
    U64 board = 0ULL;
    U64 attacks = 0ULL;

    //set piece on board
    setBit(board, square);

    int ranks, files;

    int targetRank = square / 8;
    int targetFile = square % 8;

    for (ranks = targetRank + 1; ranks <= 7; ranks++) { // S
        attacks |= (1ULL << (ranks * 8 + targetFile)); // setting every square on fil (S) as attack
        if ((1ULL << (ranks * 8 + targetFile) & blockingBoard)) break; // break (including) on blocking piece
    }
    for (ranks = targetRank - 1; ranks >= 0; ranks--) { // N
        attacks |= (1ULL << (ranks * 8 + targetFile));
        if ((1ULL << (ranks * 8 + targetFile) & blockingBoard)) break;
    }

    for (files = targetFile + 1; files <= 7; files++) { // E
        attacks |= (1ULL << (targetRank * 8 + files));
        if ((1ULL << (targetRank * 8 + files) & blockingBoard)) break;
    }

    for (files = targetFile - 1; files >= 0; files--) { // W
        attacks |= (1ULL << (targetRank * 8 + files));
        if ((1ULL << (targetRank * 8 + files) & blockingBoard)) break;
    }
    return attacks;
}

void initRookAttacks() {
    for (int square = 0; square < 64; square++) {
        rookAttacks[square] = maskRookAttacks(square);
    }
}
