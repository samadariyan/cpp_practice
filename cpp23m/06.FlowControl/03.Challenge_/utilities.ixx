module;

#include <SFML/Graphics.hpp> // Global module fragment
#include <iostream>

export module utilities; 

export void app(){

    //Store data in pre-defined variable
    constexpr int width {200};
    constexpr int height {200};
    constexpr float circle_radius {100.f};
    constexpr float clock_period{.02f};
    const std::string title {"SFML works!"};
    sf::Color shape_color{sf::Color::Green};
    sf::Color background_color{sf::Color::Red};


	sf::RenderWindow window(sf::VideoMode(width, height), title);
    sf::CircleShape shape(circle_radius);
    shape.setFillColor(shape_color);

    //Timing: change the color every 5 seconds
    sf::Clock clock; // Timer: time starts ticking.
    unsigned int counter {0};

    while (window.isOpen())
    {

        //Timing
        sf::Time elapsed = clock.getElapsedTime();
        if(elapsed.asSeconds() > clock_period){
            counter++;
            if(counter % 2 == 0){
                shape.setFillColor(sf::Color::Blue);
            }else{
                shape.setFillColor(sf::Color::Yellow);
            }
            clock.restart();
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }

            //Key Events
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    window.close();
                }

                if(event.key.code == sf::Keyboard::A){
                    //std::cout << "Pressed on A\n";
                    shape.setFillColor(sf::Color::Blue);
                }
                if(event.key.code == sf::Keyboard::B){
                    //std::cout << "Pressed on B\n";
                    shape.setFillColor(sf::Color::Yellow);
                }
                
                //C and D will increase and decrease the radius of the circle
                if(event.key.code == sf::Keyboard::C){
                    shape.setRadius(shape.getRadius() + 10.f);
                    std::cout << "Radius: " << shape.getRadius() << "\n";
                }
                if(event.key.code == sf::Keyboard::D){
                    shape.setRadius(shape.getRadius() - 10.f);
                    std::cout << "Radius: " << shape.getRadius() << "\n";
                }
            }

            //Mouse Events
            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    shape.setFillColor(sf::Color::Magenta);
                }
                if(event.mouseButton.button == sf::Mouse::Right){
                    shape.setFillColor(sf::Color::Cyan);
                }
            }
            
        }

        //Conditional rendering: Code that shows up further down overrides the code that shows up further up.
        /*
        if(shape.getRadius() > 150.f){
            shape.setFillColor(sf::Color::Black);
        }else if(shape.getRadius() < 150.f){
          shape.setFillColor(sf::Color::Blue);
        }
        */

        window.clear(background_color);
        window.draw(shape);
        window.display();
    }

}
