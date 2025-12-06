module;

#include <SFML/Graphics.hpp>
#include <fmt/format.h>

export module utilities;

export void app() {

  unsigned int width{200};
  unsigned int height{200};
  float circle_radius{float(width) / 2};
  float clock_period{.02f};
  const std::string title{"SFML works!"};
  sf::Color shape_color{sf::Color::Green};
  sf::Color background_color{sf::Color::Red};

  sf::RenderWindow window(sf::VideoMode({width, height}), title);
  sf::CircleShape shape(circle_radius);
  shape.setFillColor(shape_color);

  // Timing: change the color every 5 seconds
  sf::Clock clock; // Timer: time starts ticking.
  unsigned int counter{0};

  while (window.isOpen()) {

    // Timing
    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds() > clock_period) {
      counter++;
      if (counter % 2 == 0) {
        shape.setFillColor(sf::Color::Blue);
      } else {
        shape.setFillColor(sf::Color::Yellow);
      }
      clock.restart();
    }

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
        if (keyPressed->scancode == sf::Keyboard::Scancode::I) {
          window.close();
          window.create(sf::VideoMode({width, height}), title);
          shape.setRadius(float(width) / 2);
          width += 10;
          height += 10;
        }

        if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
          window.close();
          window.create(sf::VideoMode({width, height}), title);
          shape.setRadius(float(width) / 2);
          width -= 10;
          height -= 10;
        }
      }

      // Mouse Events
      if (const auto *mouseButtonPressed =
              event->getIf<sf::Event::MouseButtonPressed>()) {
        if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
          // Do somting
          shape.setFillColor(sf::Color::Magenta);
        }
        if (mouseButtonPressed->button == sf::Mouse::Button::Right) {
          // Do somting
          shape.setFillColor(sf::Color::Cyan);
        }
      }

      // Conditional rendering: Code that shows up further down overrides the
      // code that shows up further up.
      // if(shape.getRadius() > 150.f){
      //     shape.setFillColor(sf::Color::Black);
      // }else if(shape.getRadius() < 150.f){
      //   shape.setFillColor(sf::Color::Blue);
      // }

      window.clear(background_color);
      window.draw(shape);
      window.display();
    }
  }
}
