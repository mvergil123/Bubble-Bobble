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



Bubble::Bubble(const int R, const int RED, const int GREEN, const int BLUE, const double XDIRECTION, const double YDIRECTION, const int XPOS, const int YPOS)
{
    bubble.setRadius(R);
    xDir = XDIRECTION; // random x direction
    yDir = YDIRECTION; // random y direction
    bubble.setFillColor(sf::Color(RED, GREEN, BLUE)); // random color
    bubble.setPosition(XPOS,YPOS); // random start position
}

void Bubble::setDir(double xDir, double yDir)
{
    this->xDir = xDir;
    this->yDir = yDir;
    
}

void Bubble::draw(sf::RenderWindow& window) // draws the circle member of the class
{
    window.draw(bubble);
}


void Bubble::updatePosition(const int WIDTH, const int HEIGHT)// moves the circle
{
    double diameter = 2 * bubble.getRadius(); // store the diameter

    sf:: Vector2f position = bubble.getPosition(); // get the current position 
    double x = position.x; // store the x position
    double y = position.y; // store the y position

    // Check if the bubble hits the right wall or needs to reverse x direction
    if ((x + diameter) >= WIDTH )
    {
        xDir = -xDir; // Reverse x direction
    }

    // Check if the bubble hits the bottom wall or needs to reverse y direction
    if ((y + diameter) >= HEIGHT ) 
    {
        yDir = -yDir; // Reverse y direction
    }

    // Check if the bubble hits the left wall or needs to reverse x direction
    if (x <= 0)
    {
        xDir = -xDir; // Reverse x direction
    }

    // Check if the bubble hits the top wall or needs to reverse y direction
    if (y <= 0 ) 
    {
        yDir = -yDir; // Reverse y direction
    }

    // Move the bubble
    x += xDir; // move in the x direction 
    y += yDir; // move in the y direction


    bubble.setPosition(x, y); // move the bubble to the new position
}




