module;
#include <SFML/Graphics.hpp>
#include <fmt/format.h>

export module utilities;

export void app() {

  constexpr int width{200};
  constexpr int height{200};
  constexpr float circle_radius{100.f};
  const std::string title{"SFML works!"};
  sf::Color shape_color{sf::Color::Green};
  sf::Color background_color{sf::Color::Red};

  sf::RenderWindow window(sf::VideoMode({width, height}), title);
  sf::CircleShape shape(circle_radius);
  shape.setFillColor(shape_color);

  while (window.isOpen()) {
    // Process events
    while (const std::optional event = window.pollEvent()) {
      // Close window: exit
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
      if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
          window.close();
        if (keyPressed->scancode == sf::Keyboard::Scancode::Y)
          shape.setFillColor(sf::Color::Yellow);
        if (keyPressed->scancode == sf::Keyboard::Scancode::B)
          shape.setFillColor(sf::Color::Blue);
      }
    }

    window.clear(background_color);
    window.draw(shape);
    window.display();
  }
}
