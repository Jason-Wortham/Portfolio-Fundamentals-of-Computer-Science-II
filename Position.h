//
// Created by Jason on 5/21/2024.
//

#ifndef SFML_PROJECT_POSITION_H
#define SFML_PROJECT_POSITION_H
#include <SFML/Graphics.hpp>

class Position {
public:
    template<typename T, typename S>
    static void left(const T& constObj, S& obj, float spacing = 0);

    template<typename T, typename S>
    static void right(const T& constObj, S& obj, float spacing = 0);

    template<typename T, typename S>
    static void top(const T& constObj, S& obj, float spacing = 0);

    template<typename T, typename S>
    static void bottom(const T& constObj, S& obj, float spacing = 0);
};

#include "Position.cpp"
#endif //SFML_PROJECT_POSITION_H
