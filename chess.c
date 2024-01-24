#include <stdio.h>
#include "myconstants.h"
#include "macros.h"


/**************************
 Attacks
***************************/
// attacks table [side][square]
U64 pawnAttacks[2][64];
U64 knightAttacks[64];
U64 kingAttacks[64];
U64 bishopAttacks[64];
U64 rookAttacks[64];
U64 queenAttacks[64];

U64 maskPawnAttacks(int square, int sideToMove){
    U64 board = 0ULL;
    U64 attacks = 0ULL;

    //set piece on board
    setBit(board, square);

    //white pawns
    if(sideToMove == white){
        if((board >> 7) & not_A_file) attacks |= (board >> 7);
        if((board >> 9) & not_H_file) attacks |= (board >> 9);
    }else{ // black pawns
        if((board << 7) & not_H_file) attacks |= (board << 7);
        if((board << 9) & not_A_file) attacks |= (board << 9);
    }

    return attacks;
};

U64 maskKnightAttacks(int square){
    U64 board = 0ULL;
    U64 attacks = 0ULL;

    //set piece on board
    setBit(board, square);

    if((board << 17) & not_A_file) attacks |= (board << 17);
    if((board << 15) & not_H_file) attacks |= (board << 15);
    if((board << 10) & not_AB_file) attacks |= (board << 10);
    if((board << 6)  & not_GH_file) attacks |= (board << 6);


    if((board >> 6) & not_AB_file) attacks |= (board >> 6);
    if((board >> 10) & not_GH_file) attacks |= (board >> 10);
    if((board >> 15) & not_A_file) attacks |= (board >> 15);
    if((board >> 17) & not_H_file) attacks |= (board >> 17);


    return attacks;
}
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

void initPawnAttacks(){
    for (int square = 0; square < 64; square++) {
        pawnAttacks[white][square] = maskPawnAttacks(square, white);
        pawnAttacks[black][square] = maskPawnAttacks(square, black);
    }
}
void initKnightAttacks(){
    for (int square = 0; square < 64; square++) {
        knightAttacks[square] = maskKnightAttacks(square);
    }
}
void initKingAttacks(){
    for (int square = 0; square < 64; square++) {
        kingAttacks[square] = maskKingAttacks(square);
    }
}
void initBishopAttacks(){
    for (int square = 0; square < 64; square++) {
        bishopAttacks[square] = maskBishopAttacks(square);
    }
}
void initRookAttacks(){
    for (int square = 0; square < 64; square++) {
        rookAttacks[square] = maskRookAttacks(square);
    }
}

void printBitBoard(U64 bitboard) {
    for (int rank = 0; rank < 8; ++rank) {
        for (int file = 0; file < 8; ++file) {
            if (!file) printf("%d | ", 8 - rank);

            int square = (rank * 8) + file;
            printf("%d  ", getBit(bitboard, square) ? 1 : 0);
        }
        printf("\n");
    }
    printf("    a  b  c  d  e  f  g  h\n\n");
    // as unsigned decimal number
    printf("Decimal: %llud\n\n", bitboard);
}

void boardHelper() {
    U64 board = 0ULL;

    printf("Coordinate representation:\n\n");
    for (int rank = 0; rank < 8; ++rank) {
        for (int file = 0; file < 8 ; file++){
            int square = rank * 8 + file;
            if(file > 1){
                setBit(board, square);
            }
        }
    }
    printBitBoard(board);
}

void initializers(){
    initPawnAttacks();
    initKnightAttacks();
    initKingAttacks();
    initBishopAttacks();
    initRookAttacks();
}

int main() {
    initializers();
    // the board
    U64 board = 0ULL;
    board = maskRookAttacks(e4);
    printBitBoard(board);
    //boardHelper();

    return 0;
}

// continue with 8