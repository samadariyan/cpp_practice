/*
    . GUI Challenge: SFML
        . Practice control flow: 

            0. Understanding the while loop in the application

            1. Add more key events: 
                C-> Increase the circle size: radius += 10.f;
                D-> Decrease the circle size: radius -= 10.f;

            2. Add mouse events: 
                Left-> color = sf::Color::Magenta;
                Right-> color = sf::Color::Cyan;

            3. Conditional rendering: 
                . If radius> 150.f -> color = sf::Color::Gray;
                . If radius< 150.f -> color = sf::Color::Black;

            4: Add a timer: 
                . Change the color every 5 seconds.
                . This also shows how we can setup a counter.
                . classes: 
                    . sf::Clock
                    . sf::Time
*/

// One line comment


import utilities;

int main() {

    app();

    return 0;

}