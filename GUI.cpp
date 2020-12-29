//
// Created by jdinh on 12/28/2020.
//

#include "GUI.h"


GUI::GUI() : window(sf::VideoMode{650, 150, 32}, "GPA Calculator")
{

}


void GUI::setupText()
{
    if (!font.loadFromFile("segoeprb.ttf"))
    {
        exit(1);
    }
    displayText.setFont(font);
    displayInputText.setFont(font);

    displayText.setString("Enter total number of academic quarters/semesters: ");
    displayInputText.setString("N/A");

    displayText.setCharacterSize(20);
    displayInputText.setCharacterSize(20);

    displayText.setFillColor(sf::Color::White);
    displayInputText.setFillColor(sf::Color::White);

    displayText.setPosition(5, 0);
    displayInputText.setPosition(displayText.getGlobalBounds().width + 10, 0);
}


void GUI::specificKeyboardActions(int asciiValue)
{
    if (asciiValue == 8)  //backspace
    {
        if (!inputText.empty())
        {
            inputText.erase(inputText.size() - 1);
            displayInputText.setString(inputText);
        }
    }
    else if (asciiValue == 9)  //horizontal tab
    {
        inputText.push_back('\t');
        displayInputText.setString(inputText);
    }
    else if (asciiValue == 13)  //return key
    {
        cout << inputText << endl;
        inputText.clear();
        //inputText.push_back('\n');
        displayInputText.setString(inputText);
    }
    else if (asciiValue == 27)  //escape key
    {
        cout << "Thanks for typing! ";
        exit(0);
    }
}


void GUI::runGUI()
{
    setupText();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::TextEntered)
            {
                specificKeyboardActions(event.text.unicode);
                if (event.text.unicode >= 32 && event.text.unicode <= 127)
                {
                    inputText += static_cast<char>(event.text.unicode);
                    displayInputText.setString(inputText);
                }
            }
        }
        window.clear();
        window.draw(displayText);
        window.draw(displayInputText);
        window.display();
    }
}
