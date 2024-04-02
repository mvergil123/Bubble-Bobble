#ifndef BUBBLE_H
#define BUBBLE_H

#include <SFML/Graphics.hpp>

class Bubble
{
public:
    Bubble(); // constructor 
    Bubble(const int, const int, const int, const int,  const double, const double, const int, const int); // other constructor
    void setDir(double, double);
    void draw(sf::RenderWindow&);
    void updatePosition(const int, const int);



private:
    sf::CircleShape bubble; // will create the bubbles
    double xDir, yDir; 
};


#endif