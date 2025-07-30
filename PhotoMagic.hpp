// Copyright 2025 Danny Nguyen
#pragma once

#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"

namespace PhotoMagic {
  void transform(sf::Image& image, FibLFSR* lfsr);
}
