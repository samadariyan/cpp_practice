module;

#include <SFML/Graphics.hpp>

export module utilities;

namespace it_1
{

    export void app(){

        //Initialization
        sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        while (window.isOpen())
        {
            //Event processing
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            //Rendering
            window.clear();
            window.draw(shape);
            window.display();
        }

    }
    
} // namespace it_1


namespace it_2
{
    //Initialization
    void init(sf::RenderWindow& window, sf::CircleShape& circle){

        // Configure the window
        window.create(sf::VideoMode(800, 600), "Sfml at work!");

        //Configure the circle
        circle.setRadius(100.f);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(300.f, 200.f);
    }

    //Event processing
    void process_events(sf::RenderWindow& window) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    //Rendering
    void render(sf::RenderWindow& window, const sf::CircleShape& shape) {
        window.clear(sf::Color::Black); // Black background
        window.draw(shape);
        window.display();
    }

    //App
    export void app(){
        sf::RenderWindow window;
        sf::CircleShape shape;

        //Initialize the window and  circle
        init(window,shape);

        //Event loop
        while(window.isOpen()){
            process_events(window);
            render(window,shape);
        }
    }
    
} // namespace it_2


