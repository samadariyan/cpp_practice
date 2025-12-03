module;

#include <SFML/Graphics.hpp>

export module utilities; // Module definition

// Module purview
export void app() {
  // Store data in pre-defined variable
  int width{200};
  int height{200};
  float circle_radius{100.f};
  std::string title{"SFML works!"};
  sf::Color shape_color{sf::Color::Green};
  sf::Color background_color{sf::Color::Red};

  auto window = sf::RenderWindow(sf::VideoMode({width, height}), title);
  window.setFramerateLimit(144);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear(background_color);
    window.draw(sf::CircleShape(circle_radius));
    shape.setFillColor(shape_color);
    window.display();
  }
}
