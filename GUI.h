//
// Created by jdinh on 12/28/2020.
//

#ifndef COLLEGE_GPA_CALCULATOR_GUI_H
#define COLLEGE_GPA_CALCULATOR_GUI_H

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;


class GUI
{
private:
    sf::RenderWindow window;
    sf::Text displayText, displayInputText;
    sf::Font font;
    string text, inputText;

public:
    GUI();

    void setupText();
    void specificKeyboardActions(int asciiValue);
    void runGUI();
};


#endif //COLLEGE_GPA_CALCULATOR_GUI_H
