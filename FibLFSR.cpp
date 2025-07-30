// Copyright 2025 Danny Nguyen

#include "FibLFSR.hpp"
#include <bitset>
#include <stdexcept>

namespace PhotoMagic {

FibLFSR::FibLFSR(const std::string& seed) {
    if (seed.size() != 16) {
        throw std::invalid_argument("Seed must be a 16-bit binary string");
    }

    state = 0;
    for (char c : seed) {
        if (c != '0' && c != '1') {
            throw std::invalid_argument("Seed must contain only '0' or '1'");
        }
        state = (state << 1) | (c - '0');
    }
}

int FibLFSR::step() {
    // Tap positions: 13, 12, 10, plus leftmost (bit 15)
    int bit15 = (state >> 15) & 1;
    int bit13 = (state >> (15 - 2)) & 1;
    int bit12 = (state >> (15 - 3)) & 1;
    int bit10 = (state >> (15 - 5)) & 1;

    // XOR all taps together to get new bit
    int newBit = bit15 ^ bit13 ^ bit12 ^ bit10;

    // Shift left and insert new bit at LSB
    state = ((state << 1) & 0xFFFF) | newBit;

    return newBit;
}

int FibLFSR::generate(int k) {
    if (k <= 0 || k > 32) {
        throw std::invalid_argument("generate(k): k must be between 1 and 32");
    }

    int result = 0;
    for (int i = 0; i < k; ++i) {
        result = (result << 1) | step();
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const FibLFSR& lfsr) {
    std::bitset<16> bits(lfsr.state);
    os << bits;
    return os;
}

}  // namespace PhotoMagic

