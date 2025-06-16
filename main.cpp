// Copyright[2023]<William King>
#include "FibLFSR.hpp"
int main() {
    FibLFSR flfsr("1011011000110110");
    for (int i = 0; i < 10; i++)
        flfsr.step();
    for (int i = 0; i < 7; i++)
        flfsr.generate(5);
    return 0;
}
