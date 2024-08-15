#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    // 1. Set up
    const int wWidth = 1280;
    const int wHeight = 800;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Assignment 1");
    window .setFramerateLimit(60);

    // Shapes
    int r = 255;
    int g = 0;
    int b = 255;

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color(r, g, b));
    circle.setPosition(300.f, 300.f);
    float circleMoveSpeed = 0.5f;

    float rx = 300;
    float ry = 200;
    sf::Vector2f rSize(rx, ry);
    sf::RectangleShape rect(rSize);
    rect.setPosition(100, 5);
    rect.setFillColor(sf::Color(255,255,0));
    rect.setOutlineColor(sf::Color::Cyan);
    rect.setOutlineThickness(5);

    // Font Set Up
    sf::Font myFont;
    if (!myFont.loadFromFile("E:/CPPStuff/COMP4300-Game-Programming/fonts/fira.ttf"))
    {
        std::cerr << "Could not load font! /n";
        exit(-1);
    }

    sf::Text myText("Simple Text", myFont, 24);
    myText.setPosition(0, wHeight - (float)myText.getCharacterSize());

    // 2. Core Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        // Updates
        float sx = 0.5f;
        float sy = 0.5f;
        circle.setPosition(circle.getPosition().x - sx, circle.getPosition().y - sy);

        rect.rotate(0.5f);
        rect.setPosition(rect.getPosition().x - sx, rect.getPosition().y - sy);

        // Display Render
        window.clear();
        window.draw(myText);
        window.draw(circle);
        window.draw(rect);
        window.display();
    }

    return 0;
}
