//
// Created by Jason on 6/4/2024.
//

#include "SFMLGrid.h"

SFMLGrid::SFMLGrid() : rows(1), cols(1) {
    createArray();
    fillArray();
}

void SFMLGrid::createArray() {
    arr = new sf::RectangleShape*[rows];

    for(int i = 0; i < rows; i++){
        arr[i] = new sf::RectangleShape[cols];
    }
}

void SFMLGrid::fillArray() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = sf::RectangleShape();
            (arr[i][j]).setSize(sf::Vector2f(50, 50));
            (arr[i][j]).setFillColor(sf::Color::Blue);
            (arr[i][j]).setPosition(i * ((arr[i][j]).getSize().x * 1.1), j * ((arr[i][j]).getSize().y * 1.1));
        }
    }
}

sf::RectangleShape SFMLGrid::newRectangleShape(float x, float y) {
    sf::RectangleShape rectangle;
    rectangle.setPosition(x, y);
}

void SFMLGrid::deleteArray() {
    for(int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}


////Big Three
SFMLGrid::SFMLGrid(const SFMLGrid& grid) : rows(grid.rows), cols(grid.cols) {
    createArray();
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = grid.arr[i][j];
        }
    }
}

SFMLGrid& SFMLGrid::operator=(const SFMLGrid& grid) {
    deleteArray();
    rows = grid.rows;
    cols = grid.cols;
    createArray();
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = grid.arr[i][j];
        }
    }
    return *this;
}

SFMLGrid::~SFMLGrid() {
  deleteArray();
}

void SFMLGrid::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            window.draw(arr[i][j], states);
        }
    }
}

void SFMLGrid::eventHandler(sf::RenderWindow& window, sf::Event event) {
    if(event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Up) {

            deleteArray();
            rows++;
            cols++;
            createArray();
            fillArray();
        }
        else if(event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Down) {
            if(rows > 1) {
                rows--;
                cols--;

                deleteArray();
                createArray();
                fillArray();
            }
        }
    }
}