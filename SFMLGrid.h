//
// Created by Jason on 6/4/2024.
//

#ifndef SFML_PROJECT_SFMLGRID_H
#define SFML_PROJECT_SFMLGRID_H
#include <SFML\Graphics.hpp>

class SFMLGrid : public sf::Drawable {
private:
    sf::RectangleShape** arr;
    int rows, cols;

    //dynamically create an array of current row and col size
    void createArray();

    //fills the array with sf::RectangleShapes
    void fillArray();

    //returns a rectangle shape that is positioned at x and y
    sf::RectangleShape newRectangleShape(float x, float y);

    //deletes the arr
    void deleteArray();
public:
    SFMLGrid();

    ////Big Three Goes here
    SFMLGrid(const SFMLGrid& grid);

    SFMLGrid& operator=(const SFMLGrid& grid);

    ~SFMLGrid();

    //loop through 2D array and draw each rectangle
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

    //increases the array size when right arrow is pressed, decreases when left is pressed
    void eventHandler(sf::RenderWindow& window, sf::Event event);

};

#endif //SFML_PROJECT_SFMLGRID_H
