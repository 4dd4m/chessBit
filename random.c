#include "random.h"

unsigned int state = 1804289383;

unsigned int getRandomU32Number() {
    unsigned int number = state;

    // XOR shift alg
    number  ^= number << 13;
    number  ^= number >> 17;
    number  ^= number << 5;

    // update state
    state = number;

    return number;
}

U64 getRandomU64Number() {
    U64 n1, n2, n3, n4;

    // slice 16 bits from most sig bit side
    n1 = (U64)(getRandomU32Number() & 0xFFFF);
    n2 = (U64)(getRandomU32Number() & 0xFFFF);
    n3 = (U64)(getRandomU32Number() & 0xFFFF);
    n4 = (U64)(getRandomU32Number() & 0xFFFF);

    return n1 | (n2 << 16) | (n3 << 32) | (n4 << 48);
}

U64 generateMagicNumber() {
    return getRandomU64Number() & getRandomU64Number() & getRandomU64Number();
}
