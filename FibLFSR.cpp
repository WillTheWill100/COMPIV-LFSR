// Copyright[2023]<William King>
#include "FibLFSR.hpp"
// Constructor to create LFSR with the given initial seed
FibLFSR::FibLFSR(std::string seed) :
seed(seed), tap13(13), tap12(12), tap10(10) {}
FibLFSR::~FibLFSR() {}

// Simulate one step and return the new bit as 0 or 1
int FibLFSR::step() {
    int newBit = (seed[0] - '0') ^ (seed[15 - tap13] - '0');
    newBit ^= (seed[15 - tap12] - '0');
    newBit ^= (seed[15 - tap10] - '0');
    std::cout << seed.substr(1);
    std::cout << std::to_string(newBit) << " " << newBit << std::endl;
    seed = seed.substr(1) + std::to_string(newBit);
    seed[15] = newBit + '0';
    return newBit;
}

// Simulate k steps and return a k-bit integer
int FibLFSR::generate(int k) {
    int extraction = 0;
    for (int i = 0; i < k; i++) {
        int new_bit = step();
        extraction = (extraction << 1) + new_bit;
    }
    return extraction;
}

// For boost test
bool FibLFSR::operator == (const std::string& other)const {
    return seed == other;
}

// Make ostream a friend function
std::ostream& operator<<(std::ostream& os, const FibLFSR& lfsr) {
    os << lfsr.seed;
    return os;
}
