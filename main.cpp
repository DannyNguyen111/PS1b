// Copyright 2025 Danny Nguyen


#include <iostream>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

using PhotoMagic::transform;
using PhotoMagic::FibLFSR;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input-image> <output-image> <LFSR-seed>\n";
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::string seed = argv[3];

    sf::Image image;
    if (!image.loadFromFile(inputFile)) {
        std::cerr << "Error loading input image.\n";
        return 1;
    }

    FibLFSR lfsr(seed);
    transform(image, &lfsr);

    if (!image.saveToFile(outputFile)) {
        std::cerr << "Error saving output image.\n";
        return 1;
    }

    sf::Texture texture1, texture2;
    texture1.loadFromFile(inputFile);
    texture2.loadFromFile(outputFile);
    sf::Sprite sprite1(texture1), sprite2(texture2);
    sf::RenderWindow window1(sf::VideoMode(texture1.getSize().x,
    texture1.getSize().y), "Original Image");
    sf::RenderWindow window2(sf::VideoMode(texture2.getSize().x,
    texture2.getSize().y), "Transformed Image");

    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window2.close();
        }
        window1.clear();
        window1.draw(sprite1);
        window1.display();
        window2.clear();
        window2.draw(sprite2);
        window2.display();
    }

    return 0;
}
