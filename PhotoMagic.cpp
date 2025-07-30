// Copyright 2025 Danny Nguyen
#include "PhotoMagic.hpp"

namespace PhotoMagic {

void transform(sf::Image& image, FibLFSR* lfsr) {
    sf::Vector2u size = image.getSize();
    for (unsigned x = 0; x < size.x; ++x) {
        for (unsigned y = 0; y < size.y; ++y) {
            sf::Color color = image.getPixel(x, y);
            color.r ^= lfsr->generate(8);
            color.g ^= lfsr->generate(8);
            color.b ^= lfsr->generate(8);
            image.setPixel(x, y, color);
        }
    }
}

}  // namespace PhotoMagic

