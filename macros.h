#ifndef BITBOARDCHESS_MACROS_H
#define BITBOARDCHESS_MACROS_H

#define setBit(board, square) (board |= (1ULL << square))
#define getBit(board, square) (board & (1ULL << square))
#define popBit(board, square) (getBit(board, square) ? board ^= (1ULL << square) : 0)

#endif //BITBOARDCHESS_MACROS_H
