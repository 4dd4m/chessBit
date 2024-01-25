#include "bishop.h"

#define CURRENT_SQUARE (ranks * 8 + files)

U64 bishopAttacks[64];

// relevant occupancy for every square
const int bishopRelevantBits[64] = {
        6, 5, 5, 5, 5, 5, 5, 6,
        5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 7, 7, 7, 7, 5, 5,
        5, 5, 7, 9, 9, 7, 5, 5,
        5, 5, 7, 9, 9, 7, 5, 5,
        5, 5, 7, 7, 7, 7, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5,
        6, 5, 5, 5, 5, 5, 5, 6,
};

U64 maskBishopAttacks(int square){
    U64 board = 0ULL;
    U64 attacks = 0ULL;

    //set piece on board
    setBit(board, square);
    int ranks, files;

    int targetRank = square / 8;
    int targetFile = square % 8;

    for (ranks = targetRank + 1, files = targetFile +1; ranks <= 6 && files <= 6; ranks++, files++) {
        attacks |= (1ULL << CURRENT_SQUARE);
    }
    for (ranks = targetRank - 1, files = targetFile +1; ranks >= 1 && files <= 6; ranks--, files++) {
        attacks |= (1ULL << CURRENT_SQUARE);
    }
    for (ranks = targetRank + 1, files = targetFile - 1; ranks <= 6 && files >= 1; ranks++, files--) {
        attacks |= (1ULL << CURRENT_SQUARE);
    }
    for (ranks = targetRank - 1, files = targetFile - 1; ranks >= 1 && files >= 1; ranks--, files--) {
        attacks |= (1ULL << CURRENT_SQUARE);
    }
    return attacks;
}

U64 bishopAttacks_in_game(int square, U64 blockingBoard){
    U64 board = 0ULL;
    U64 attacks = 0ULL;

    //set piece on board
    setBit(board, square);
    int ranks, files;

    int targetRank = square / 8;
    int targetFile = square % 8;

    for (ranks = targetRank + 1, files = targetFile +1; ranks <= 7 && files <= 7; ranks++, files++) { // diagonal ray no 1.
        attacks |= (1ULL << CURRENT_SQUARE); // sets up the current square as attack
        if(((1ULL << CURRENT_SQUARE) & blockingBoard)) break; // if there is a blocking piece, stop the ray
    }
    for (ranks = targetRank - 1, files = targetFile +1; ranks >= 0 && files <= 7; ranks--, files++) {
        attacks |= (1ULL << CURRENT_SQUARE);
        if(((1ULL << CURRENT_SQUARE) & blockingBoard)) break;
    }
    for (ranks = targetRank + 1, files = targetFile - 1; ranks <= 7 && files >= 0; ranks++, files--) {
        attacks |= (1ULL << CURRENT_SQUARE);
        if(((1ULL << CURRENT_SQUARE) & blockingBoard)) break;
    }
    for (ranks = targetRank - 1, files = targetFile - 1; ranks >= 0 && files >= 0; ranks--, files--) {
        attacks |= (1ULL << (CURRENT_SQUARE));
        if(((1ULL << (CURRENT_SQUARE)) & blockingBoard)) break;
    }
    return attacks;
}

void initBishopAttacks(){
    for (int square = 0; square < 64; square++) {
        bishopAttacks[square] = maskBishopAttacks(square);
    }
}
