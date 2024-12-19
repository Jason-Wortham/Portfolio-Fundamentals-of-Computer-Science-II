//
// Created by Jason on 6/10/2024.
//

#ifndef SFML_PROJECT_DUCKLAKEDASH_H
#define SFML_PROJECT_DUCKLAKEDASH_H
#include "Program.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AnimatedSpriteSheetDuck.h"
#include <ctime>
#include <cmath>
#include "SplashScreen.h"
#include "Duck.h"
#include "Obstacle.h"
#include "EventManager.h"

class DuckLakeDash : public Program {
private:
    EventManager eventManager;
    sf::Clock obstacleClock;
    SplashScreen splashScreen;
    SplashScreen gameOver;
    SplashScreen beatGame;
    Duck duck;
    std::vector<Obstacle> obstacles;
    sf::Texture sharkTexture;
    sf::Texture logTexture;
    sf::Texture netTexture;
    sf::Texture dryLandTexture;
    sf::Texture boatTexture;
    AnimatedSpriteSheetDuck backgroundLayer1;
    AnimatedSpriteSheetDuck backgroundLayer2;
    float timeChange;

public:
    DuckLakeDash();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void run(sf::RenderWindow& window, sf::RenderStates states);
    void update();
    std::string getTitle() const;
    void draw(sf::RenderWindow& window);
};


#endif //SFML_PROJECT_DUCKLAKEDASH_H
