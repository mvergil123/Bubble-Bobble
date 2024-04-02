/* CSCI 200: Assignment 4: A4 - Bubble Bobble
 *
 * Author: XXXX (Mike Vergil)
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * XXXXXXXX (MORE_COMPLETE_DESCRIPTION_HERE)
 * This code creates an interactive program which the 
 */


#include "Bubble.h"
#include <SFML/Graphics.hpp> // for SFML
#include <ctime> // for elapsed time
#include <cstdlib> // for rand() and srand()
#include <iostream> // for output
#include <vector> // for vectors

using namespace sf;
using namespace std;

int main() {
    srand(time(0)); // set the random seed

    vector<Bubble> Bubbles; // creating the vector for the bubbles
    int radius, red, green, blue, xPos, yPos;
    double xDirection, yDirection, r;

   for (int i = 0; i < 5; i++) // for loop to add 5 bubbles to the vector
    {
    // generate the random values
    radius = 10 + (rand() % (50 - 10));
    red = (rand() % 260);
    green = (rand() % 260);
    blue = (rand() % 260);
    xPos = 100 + (rand() % (400 - 100));
    yPos = 100 + (rand() % (400 - 100));

    r = (double)rand() / RAND_MAX;
    xDirection = -0.1667 + (0.1667 - (-0.1667)) * r;
    r = (double)rand() / RAND_MAX;
    yDirection = -0.1667 + (0.1667 - (-0.1667)) * r;

    Bubbles.push_back(Bubble(radius, red, green, blue, xDirection, yDirection, xPos, yPos)); // append into the vector
    }



    // Create a window
    RenderWindow window(VideoMode(640, 640), "Bubble Bobble");

    // Variables for elapsed time calculation
    const double INTERVAL = 1.0 / 60.0; // Target interval (1/60th of a second)
    clock_t lastCheck = clock();         // Last time checked

        // Handle events
        Event event;
    // Game loop
    while (window.isOpen()) {

                // Calculate elapsed time
        clock_t currentTime = clock();
        double elapsedTime = double(currentTime - lastCheck) / CLOCKS_PER_SEC;

        // Check if the desired interval has elapsed
        if (elapsedTime >= INTERVAL) {
            // Update bubble position
            for (unsigned int i = 0; i < Bubbles.size(); i++) // iterate through each bubble in the vector
            {
                Bubbles[i].updatePosition(640, 640); // move each bubble
            }

            // Update the last check time
            lastCheck = currentTime;
        }

        // Clear the window
        window.clear();

        for (unsigned int j = 0; j < Bubbles.size(); j++) // iterate through each bubble in the vector
        {
            Bubbles[j].draw(window); // draw each bubble
        }

        // Display the window contents
        window.display();

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                break;
            } else if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    // Left mouse button is pressed
                    // Get the position of the click
                    Vector2i mousePosition = Mouse::getPosition(window);

                        // Creating the bubble objects
                    
                        // generate the random values
                        radius = 10 + (rand() % (50 - 10));
                        red = (rand() % 260);
                        green = (rand() % 260);
                        blue = (rand() % 260);
                        xPos = mousePosition.x;
                        yPos = mousePosition.y;

                        r = (double)rand() / RAND_MAX;
                        xDirection = -0.1667 + (0.1667 - (-0.1667)) * r;
                        r = (double)rand() / RAND_MAX;
                        yDirection = -0.1667 + (0.1667 - (-0.1667)) * r;

                        Bubbles.push_back(Bubble(radius, red, green, blue, xDirection, yDirection, xPos, yPos)); // append into the vector
                }}
                else if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::D && !Bubbles.empty()) {
                            Bubbles.pop_back(); // pops the last created bubble 
                        
                    } 
                }
                else if (event.key.code == Keyboard::Q || event.key.code == Keyboard::Escape) {
                        window.close(); // closes the window
                    }
                    
                }
   

    }

    return 0;
}
