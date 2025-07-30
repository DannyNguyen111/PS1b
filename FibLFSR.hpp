// Copyright 2025 Danny Nguyen
#pragma once

#include <iostream>
#include <string>

namespace PhotoMagic {
class FibLFSR {
 public:
    explicit FibLFSR(const std::string& seed);
    //  explicit FibLFSR(unsigned int seed); Optional

    //  static FibLFSR fromPassword(const std::string& password); Optional

    int step();
    int generate(int k);
    friend std::ostream& operator<<(std::ostream&, const FibLFSR&);
 private:
    uint16_t state;
};
}  // namespace PhotoMagic
