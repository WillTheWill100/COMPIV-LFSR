// Copyright[2023]<William King>
#pragma once
#ifndef FibLFSR_H
#define FibLFSR_H
#include <iostream>
#include <string>

class FibLFSR {
 public:
    // Constructor to create LFSR with the given initial seed
    explicit FibLFSR(std::string seed);
    ~FibLFSR();
    // Simulate one step and return the new bit as 0 or 1
    int step();
    // Simulate k steps and return a k-bit integer
    int generate(int k);
    // Make ostream a friend function
    friend std::ostream& operator<<(std::ostream&, const FibLFSR& lfsr);
    // For boost test
    bool operator==(const std::string& other)const;
 private:
    // Any fields that you need
    std::string seed;
    int tap13, tap12, tap10;
};
std::ostream& operator<<(std::ostream& os, const FibLFSR& lfsr);
#endif
