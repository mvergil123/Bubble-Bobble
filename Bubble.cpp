#include "Bubble.h"
#include <SFML/Graphics.hpp> // for SFML
#include <iostream>

using namespace sf;

Bubble::Bubble()
{
    bubble.setFillColor(Color::White);
    bubble.setRadius(10);
    xDir = 1;
    yDir = 0.5;
    bubble.setPosition(0.1,0.1);
}

Bubble::Bubble(const int R, const int RED, const int GREEN, const int BLUE, const double XDIRECTION, const double YDIRECTION, const int XPOS, const int YPOS)
{
    bubble.setRadius(R);
    xDir = XDIRECTION; // random x direction
    yDir = YDIRECTION; // random y direction
    bubble.setFillColor(Color(RED, GREEN, BLUE)); // random color
    bubble.setPosition(XPOS,YPOS); // random start position
}

void Bubble::setDir(double xDir, double yDir)
{
    this->xDir = xDir;
    this->yDir = yDir;
    
}

double Bubble::getxDir() const
{
    return xDir;
}

double Bubble::getyDir() const
{
    return yDir;
}

void Bubble::draw(RenderWindow& window) // draws the circle member of the class
{
    window.draw(bubble);
}


void Bubble::updatePosition(const int WIDTH, const int HEIGHT)// moves the circle
{
    double diameter = 2 * bubble.getRadius(); // store the diameter

    Vector2f position = bubble.getPosition(); // get the current position 
    double x = position.x; // store the x position
    double y = position.y; // store the y position

    // Check if the bubble hits the right wall or needs to reverse x direction
    if ((x + diameter) >= WIDTH && xDir > 0)
    {
        xDir = -xDir; // Reverse x direction
    }

    // Check if the bubble hits the bottom wall or needs to reverse y direction
    if ((y + diameter) >= HEIGHT && yDir > 0)
    {
        yDir = -yDir; // Reverse y direction
    }

    // Check if the bubble hits the left wall or needs to reverse x direction
    if (x <= 0 && xDir < 0)
    {
        xDir = -xDir; // Reverse x direction
    }

    // Check if the bubble hits the top wall or needs to reverse y direction
    if (y <= 0 && yDir < 0)
    {
        yDir = -yDir; // Reverse y direction
    }

    // Move the bubble
    x += xDir; // move in the x direction 
    y += yDir; // move in the y direction


    bubble.setPosition(x, y); // move the bubble to the new position
}
