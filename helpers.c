#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "macros.h"

const char* squareToCoordinates[] = {
        "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",
        "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
        "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
        "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
        "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
        "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
        "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
        "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1"
};

int countBitBoardBits(U64 board) {
    int count = 0;

    while (board) {
        count++;
        board &= board - 1;
    }
    return count;
}

void boardInBinary(U64 board) {
    int size = 64;

    for (int i = size - 1; i >= 0; i--) {
        if ((board & (1ULL << i)) != 0) {
            printf("1");
        } else {
            printf("0");
        }
        if (i % 8 == 0) {
            printf(" ");
        }
    }
}

int leastSignificantBoardIndex(U64 board) {
    if (board == 0LL) return -1;
    // a bit hack
    return countBitBoardBits((board & -board) - 1);
}

U64 setOccupancy(int index, U64 attackMask) {

    U64 board = 0LL;
    int leastSignificantBit;
    int bitsInMask = countBitBoardBits(attackMask);

    //loop over the range of bits within the attack mask
    for (int i = 0; i < bitsInMask; i++) {

        //get LS1B index of attack mask
        leastSignificantBit = leastSignificantBoardIndex(attackMask);

        //pop LS1B in attack map
        popBit(attackMask, leastSignificantBit);

        // occupancy on board
        if(index & (1LL << i)){
            board |= (1ULL << leastSignificantBit);
        }
    }
    return board;
}
