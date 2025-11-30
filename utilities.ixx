module;

#include <SFML/Graphics.hpp>


export module utilities; // Module definition

// Module purview
export void app() {
  auto window =
      sf::RenderWindow(sf::VideoMode({200u, 200u}), "CMake SFML Project");
  window.setFramerateLimit(144);

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear();
    window.draw(sf::CircleShape(100.f));
    window.display();
  }
}
