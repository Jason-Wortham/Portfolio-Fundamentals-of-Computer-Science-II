cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME sfml_project)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp
        Program.cpp
        Program.h
        GreenCircleProgram.cpp
        GreenCircleProgram.h
        PokerProgram.cpp
        PokerProgram.h
        MouseEvents.cpp
        Fonts.cpp
        Button.cpp
        Portfolio.cpp
        Portfolio.h
        cardHandScorer.cpp
        cardHandScorer.cpp
        AnimatedSpriteSheet.cpp
        card.cpp
        cardHand.cpp
        PokerScoreCard.cpp
        deck.cpp
        BouncingObjects.cpp
        BouncingObjects.h
        ball.cpp
        ArrayProgram.cpp
        ArrayProgram.h
        SFMLGrid.cpp
        AnimatedSprite.cpp
        AnimatedSprite.h
        DuckLakeDash.cpp
        DuckLakeDash.h
        AnimatedSpriteSheetDuck.cpp
        SplashScreen.cpp
        ButtonDuck.cpp
        EventManager.cpp
        Duck.cpp
        Obstacle.cpp
        CalculatorProgram.cpp
        CalculatorProgram.h
        CalculatorProgram.cpp
        Calculator.cpp
        Display.cpp
        CircleButton.cpp
        NegativeNumberException.cpp
        InvalidPostfixException.cpp
        DivideByZeroException.cpp
        NotANumberException.cpp
        Term.cpp
        RPN.cpp
        Postfix.cpp)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES}
            cardHandScorer.cpp
            cardHandScorer.cpp
            AnimatedSpriteSheet.cpp
            card.cpp
            cardHand.cpp
            PokerScoreCard.cpp
            deck.cpp
            ball.cpp
            AnimatedSpriteSheetDuck.cpp
            SplashScreen.cpp
            ButtonDuck.cpp
            EventManager.cpp
            Duck.cpp
            Obstacle.cpp
            CalculatorProgram.cpp
            Calculator.cpp
            Display.cpp
            CircleButton.cpp
            NegativeNumberException.cpp
            InvalidPostfixException.cpp
            DivideByZeroException.cpp
            NotANumberException.cpp
            Term.cpp
            RPN.cpp
            Postfix.cpp)
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES}
            cardHandScorer.cpp
            cardHandScorer.cpp
            AnimatedSpriteSheet.cpp
            card.cpp
            cardHand.cpp
            PokerScoreCard.cpp
            deck.cpp
            ball.cpp
            AnimatedSpriteSheetDuck.cpp
            SplashScreen.cpp
            ButtonDuck.cpp
            EventManager.cpp
            Duck.cpp
            Obstacle.cpp
            CalculatorProgram.cpp
            Calculator.cpp
            Display.cpp
            CircleButton.cpp
            NegativeNumberException.cpp
            InvalidPostfixException.cpp
            DivideByZeroException.cpp
            NotANumberException.cpp
            Term.cpp
            RPN.cpp
            Postfix.cpp)
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()