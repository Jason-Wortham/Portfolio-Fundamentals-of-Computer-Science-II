//
// Created by Jason on 6/10/2024.
//

#include "DuckLakeDash.h"

DuckLakeDash::DuckLakeDash() : duck("duckSprite1.png", 265.f, 300.f),
                               backgroundLayer1("lake_background2.png"),
                               backgroundLayer2("lake_background3.png"){
    srand(time(NULL));


    backgroundLayer1.setPosition(0.f, -100.f);
    backgroundLayer2.setPosition(0.f, -100.f);


    splashScreen.getMessage().setString("Welcome to Duck Lake Dash!\nJason Wortham\nCS3A\n37045\nSpring 24");
    splashScreen.setFillColor(sf::Color(53, 174, 230, 0));
    splashScreen.setImage("duckSprite3.png", sf::Vector2f(210.f, 97.f));
    splashScreen.getMessage().setCharacterSize(30);
    splashScreen.getMessage().setFillColor(sf::Color::Yellow);

    gameOver.getMessage().setString("Game Over");
    gameOver.setFillColor(sf::Color::Black);
    gameOver.getButton().getText().setString("Play Again");
    gameOver.getMessage().setPosition(170.f, 100.f);
    gameOver.getMessage().setCharacterSize(50);

    beatGame.getMessage().setString("You Won!");
    beatGame.setFillColor(sf::Color::Blue);
    beatGame.getButton().getText().setString("Play Again");
    beatGame.setFillColor(sf::Color(53, 174, 230, 0));
    beatGame.setImage("endOfGame.png", sf::Vector2f(0.f, 0.f));
    beatGame.getMessage().setPosition(195.f, 20.f);
    beatGame.getMessage().setCharacterSize(50);
    beatGame.getMessage().setFillColor(sf::Color::Black);


    sharkTexture.loadFromFile("shark_sprite3.png");
    logTexture.loadFromFile("log3.png");
    netTexture.loadFromFile("net.png");
    dryLandTexture.loadFromFile("dryLand.png");
    boatTexture.loadFromFile("boat.png");

    obstacles.reserve(40);

    eventManager.setCurrentState(EventManager::START_SCREEN);
}

void DuckLakeDash::eventHandler(sf::RenderWindow& window, sf::Event event) {
    if(event.type == sf::Event::Closed) {
        window.close();
    }

    if(eventManager.getCurrentState() == EventManager::START_SCREEN) {
        splashScreen.eventHandler(event, window, eventManager);
        if(eventManager.getCurrentState() == EventManager::IN_GAME) {
            obstacleClock.restart();
        }
    }
    else if(eventManager.getCurrentState() == EventManager::IN_GAME) {
        if(event.type == sf::Event::KeyPressed) {
            duck.updatePosition(event);
        }

        if(obstacles.empty()) {
            for(int i = 0; i < 30; i ++) {
                Obstacle net(netTexture, (rand() % 600) - 100, -((rand() % 4300) + 100.f), sf::Vector2f(0, (rand() % 20) + 30.f), sf::Vector2f(170.f, 10.f), sf::Vector2f(-0.2f, -3.5f));
                obstacles.push_back(net);

                Obstacle log(logTexture, (rand() % 800) - 200, -((rand() % 19000) + 100.f), sf::Vector2f(0, (rand() % 50) + 80.f), sf::Vector2f(430.f, 30.f), sf::Vector2f(-0.02f, -0.6f));
                obstacles.push_back(log);
            }

            for(int i = 0; i < 45; i ++) {
                Obstacle shark(sharkTexture, rand() % 580, -((rand() % 24000) + 100.f), sf::Vector2f(0, (rand() % 150) + 100.f), sf::Vector2f(35.f, 80.f), sf::Vector2f(-1.f, -1.f));
                obstacles.push_back(shark);
            }

            Obstacle boat(boatTexture, 1000 + rand() % 3000, 220, sf::Vector2f(-(rand() % 20) - 30.f, 0), sf::Vector2f(200.f, 100.f), sf::Vector2f(-0.2f, -0.6f));
            obstacles.push_back(boat);

            Obstacle dryLand(dryLandTexture, 0, -5000, sf::Vector2f(0, (rand() % 20) + 30.f), sf::Vector2f(600.f, 300.f), sf::Vector2f(0.f, 0.f));
            obstacles.push_back(dryLand);
        }

    }
    else if(eventManager.getCurrentState() == EventManager::GAME_OVER) {
        duck.getSprite().setPosition(265.f, 300.f);
        obstacles.clear();
        gameOver.eventHandler(event, window, eventManager);
    }
    else if(eventManager.getCurrentState() == EventManager::BEAT_GAME) {
        duck.getSprite().setPosition(265.f, 300.f);
        obstacles.clear();
        beatGame.eventHandler(event, window, eventManager);
    }
}

void DuckLakeDash::run(sf::RenderWindow& window, sf::RenderStates states) {
    timeChange = obstacleClock.restart().asSeconds();
    update();
    draw(window);
}

void DuckLakeDash::update() {

    if(eventManager.getCurrentState() == EventManager::IN_GAME) {
        for(int i = 0; i < obstacles.size(); i++) {
            obstacles[i].move(timeChange);

            if(obstacles[i].checkHit(duck.getSprite()) == true) {
                if(i == obstacles.size() - 1) {
                    eventManager.setCurrentState(EventManager::BEAT_GAME);
                }
                else if(duck.getSprite().getScale().x == 2.f && duck.getUnderWaterStatus() == false && duck.getFlyingStatus() == false) {
                    eventManager.setCurrentState(EventManager::GAME_OVER);
                }
            }
        }

        if(duck.getUnderWaterStatus() == false) {
            duck.updateSprite();
        }
    }
}

void DuckLakeDash::draw(sf::RenderWindow& window) {

    window.clear(sf::Color::Black);
    window.draw(backgroundLayer1);

    if(duck.getUnderWaterStatus() == true) {
        duck.updateSprite();
        duck.draw(window);
    }

    window.draw(backgroundLayer2);

    if(eventManager.getCurrentState() == EventManager::START_SCREEN) {
        splashScreen.show(window);
        splashScreen.drawImage(window);
    }
    else if(eventManager.getCurrentState() == EventManager::IN_GAME) {
        for(int i = 0; i < obstacles.size(); i++) {
            obstacles[i].draw(window);
        }

        if(duck.getUnderWaterStatus() == false) {
            duck.draw(window);
        }
    }
    else if(eventManager.getCurrentState() == EventManager::GAME_OVER) {
        gameOver.show(window);
    }
    else if(eventManager.getCurrentState() == EventManager::BEAT_GAME) {
        beatGame.drawImage(window);
        beatGame.show(window);
    }

    sf::RectangleShape blockerRight;
    sf::RectangleShape blockerBottom;
    blockerRight.setPosition(600.f, 0.f);
    blockerBottom.setPosition(0.f, 500.f);
    blockerRight.setSize(sf::Vector2f(1400.f, 500.f));
    blockerBottom.setSize(sf::Vector2f(2000.f, 600.f));
    blockerRight.setFillColor(sf::Color::Black);
    blockerBottom.setFillColor(sf::Color::Black);
    window.draw(blockerRight);
    window.draw(blockerBottom);

}

std::string DuckLakeDash::getTitle() const {
    return "Duck Lake Dash";
}