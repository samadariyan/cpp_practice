module;

#include <fmt/format.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <memory>

export module utilities; 

//Storing our data in an std::vector: The best way to go
namespace dm_1
{
       export void app(){

        //Store data in pre-defined variable
        constexpr int width {600};
        constexpr int height {600};
        constexpr float circle_radius {40.f};
        constexpr float clock_period{.02f};
        const std::string title {"SFML Shape Animator"};
        sf::Color shape_color{sf::Color::Green};
        sf::Color background_color{sf::Color::Black};

        sf::RenderWindow window(sf::VideoMode(width, height), title);

        //Vector to store multiple shpes
        std::vector < sf::CircleShape> shapes;

        //Vector to store the movement direction for each shape
        std::vector<sf::Vector2f> directions;

        //Set up the shapes
        for(size_t i{0}; i < 5; ++i){
            sf::CircleShape shape(circle_radius);
            shape.setPosition(100.f * (i +1), 100.f);
            shape.setFillColor(sf::Color(50 * i, 100 + (30 * i), 200 - (40 * i)));
            shapes.push_back(shape);

            //Initial direction for each shape (moving diagonally)
            directions.push_back(sf::Vector2f(20.f, 20.f));
        }

        //Timer setup
        sf::Clock clock;
        constexpr float move_interval {0.05f}; // Move shapes every 50 milliseconds

        while (window.isOpen())
        {
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
                }
            }

            //Timer based movement
            if(clock.getElapsedTime().asSeconds() > move_interval){
                for(size_t i{0}; i< shapes.size(); ++i){
                    auto& shape = shapes[i];
                    auto& direction = directions[i];

                    // Get the current position of the shape
                    sf::Vector2f position = shape.getPosition();

                    // Check for collisions with window edges and reverse direction
                    if (position.x <= 0.f || position.x + circle_radius * 2 >= width) {
                        direction.x = -direction.x; // Reverse horizontal direction
                    }
                    if (position.y <= 0.f || position.y + circle_radius * 2 >= height) {
                        direction.y = -direction.y; // Reverse vertical direction
                    }

                    //Move the shapes in the current direction
                    shape.move(direction);
                }
                clock.restart();
            }

            window.clear(background_color);
            for(size_t i{0}; i < shapes.size(); ++i){
                window.draw(shapes[i]);
            }
            window.display();
        }
    }
    
} // namespace dm_1

//Storing shapes on the heap and managing memory manually through new and delete: The worst way
namespace dm_2
{
    export void app(){
        //Store data in pre-defined variable
        constexpr int width {600};
        constexpr int height {600};
        constexpr float circle_radius {40.f};
        constexpr float clock_period{.02f};
        constexpr size_t shape_count{5};
        const std::string title {"SFML Shape Animator"};
        sf::Color shape_color{sf::Color::Green};
        sf::Color background_color{sf::Color::Black};
        

        sf::RenderWindow window(sf::VideoMode(width, height), title);

        // Dynamically allocated arrays for shapes and directions
        sf::CircleShape* shapes = new sf::CircleShape[shape_count];
        sf::Vector2f* directions = new sf::Vector2f[shape_count];

        // Set up the shapes
        for (size_t i {0}; i < shape_count; ++i) {
            shapes[i] = sf::CircleShape(circle_radius);
            shapes[i].setPosition(100.f * (i + 1), 100.f);
            shapes[i].setFillColor(sf::Color(50 * i, 100 + (30 * i), 200 - (40 * i)));

            // Initial direction for each shape (moving diagonally)
            directions[i] = sf::Vector2f(20.f, 20.f);
        }

        //Timer setup
        sf::Clock clock;
        constexpr float move_interval {0.05f}; // Move shapes every 50 milliseconds

        while (window.isOpen())
        {
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
                }
            }

            //Timer based movement
            if(clock.getElapsedTime().asSeconds() > move_interval){
                for(size_t i{0}; i< shape_count; ++i){
                    auto& shape = shapes[i];
                    auto& direction = directions[i];

                    // Get the current position of the shape
                    sf::Vector2f position = shape.getPosition();

                    // Check for collisions with window edges and reverse direction
                    if (position.x <= 0.f || position.x + circle_radius * 2 >= width) {
                        direction.x = -direction.x; // Reverse horizontal direction
                    }
                    if (position.y <= 0.f || position.y + circle_radius * 2 >= height) {
                        direction.y = -direction.y; // Reverse vertical direction
                    }

                    //Move the shapes in the current direction
                    shape.move(direction);
                }
                clock.restart();
            }

            window.clear(background_color);
            for(size_t i{0}; i < shape_count; ++i){
                window.draw(shapes[i]);
            }
            window.display();
        }

        //Release the memory
        delete[] shapes;
        delete[] directions;

    }
    
} // namespace dm_2


//Use smart pointers to do better than raw pointers
namespace dm_3
{
   export void app(){
        //Store data in pre-defined variable
        constexpr int width {600};
        constexpr int height {600};
        constexpr float circle_radius {40.f};
        constexpr float clock_period{.02f};
        constexpr size_t shape_count{5};
        const std::string title {"SFML Shape Animator"};
        sf::Color shape_color{sf::Color::Green};
        sf::Color background_color{sf::Color::Black};
        

        sf::RenderWindow window(sf::VideoMode(width, height), title);

       // Dynamically allocated arrays for shapes and directions using smart pointers
       auto shapes = std::make_unique<sf::CircleShape[]>(shape_count);
       auto directions = std::make_unique<sf::Vector2f[]>(shape_count);

        //Use smart pointers

        // Set up the shapes
        for (size_t i {0}; i < shape_count; ++i) {
            shapes[i] = sf::CircleShape(circle_radius);
            shapes[i].setPosition(100.f * (i + 1), 100.f);
            shapes[i].setFillColor(sf::Color(50 * i, 100 + (30 * i), 200 - (40 * i)));

            // Initial direction for each shape (moving diagonally)
            directions[i] = sf::Vector2f(20.f, 20.f);
        }

        //Timer setup
        sf::Clock clock;
        constexpr float move_interval {0.05f}; // Move shapes every 50 milliseconds

        while (window.isOpen())
        {
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
                }
            }

            //Timer based movement
            if(clock.getElapsedTime().asSeconds() > move_interval){
                for(size_t i{0}; i< shape_count; ++i){
                    auto& shape = shapes[i];
                    auto& direction = directions[i];

                    // Get the current position of the shape
                    sf::Vector2f position = shape.getPosition();

                    // Check for collisions with window edges and reverse direction
                    if (position.x <= 0.f || position.x + circle_radius * 2 >= width) {
                        direction.x = -direction.x; // Reverse horizontal direction
                    }
                    if (position.y <= 0.f || position.y + circle_radius * 2 >= height) {
                        direction.y = -direction.y; // Reverse vertical direction
                    }

                    //Move the shapes in the current direction
                    shape.move(direction);
                }
                clock.restart();
            }

            window.clear(background_color);
            for(size_t i{0}; i < shape_count; ++i){
                window.draw(shapes[i]);
            }
            window.display();
        }
    }
       
} // namespace dm_3

