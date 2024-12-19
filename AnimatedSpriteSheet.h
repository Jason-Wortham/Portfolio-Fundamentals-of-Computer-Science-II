//
// Created by Jason on 4/11/2024.
//

#ifndef SFML_PROJECT_ANIMATEDSPRITESHEETDUCK_H
#define SFML_PROJECT_ANIMATEDSPRITESHEETDUCK_H
#include <string>
#include <SFML/Graphics.hpp>

class AnimatedSpriteSheet : public sf::Sprite {
private:
    sf::IntRect intRect;
    sf::Texture texture;
    sf::Clock clock;
    void init(const std::string& filepath, int rows, int cols);
public:
    AnimatedSpriteSheet(const std::string& filepath, int rows, int cols);
    AnimatedSpriteSheet();
    void setRowAndCol(int row, int col);
    void animate();
};


#endif //SFML_PROJECT_ANIMATEDSPRITESHEETDUCK_H
