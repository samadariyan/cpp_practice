module;

#include <SFML/Graphics.hpp>
#include <array>
#include <fmt/format.h>
#include <iostream>
#include <random>
#include <vector>

export module secuences_challenge;
/*

  . GUI Challenge: SFML
        . Five challenges to flex your muscles.
              1. Store Multiple Shapes Using Containers
                . Task: Modify the code so that it stores multiple
  sf::CircleShape objects in an std::vector. The program should initialize the
  shapes with different radii and positions, and cycle through their colors. .
  Hint: Use std::vector<sf::CircleShape> to store the shapes. .  Objective:
  Students should get used to working with dynamic containers like std::vector.

              2. Track Key Press History with a Fixed-Size Container
                . Task: Track the last 5 keys pressed by the user and display
  the history in the console. Use std::array<char, 5> to store the key history.
                . Hint: Use an index to cycle through the array and update it
  with the new key presses. . Objective: Practice with std::array for fixed-size
  containers and updating data circularly.

              3. Store Color Changes in a Static Array
                . Task: Store a predefined sequence of colors in a built-in
  array, and cycle through them each time a specific key (e.g., space bar) is
  pressed to change the shape's fill color. . Hint: Use a built-in array like
  sf::Color colors[4] to store the color sequence and manage the index. .
  Objective: Get familiar with accessing data in built-in arrays and
  manipulating the shape’s color.

              4. Animate Multiple Shapes with Timers
                . Task: Create multiple shapes (using std::vector or std::array)
  and move them both horizontally and vertically across the window .

              5. Draw shapes at the position where the mouse is clicked in the
  window . Task: Draw the shapes in a way that the colors are random, and the
  radii are random . Hint: Dynamically adjust the size of the container using
  std::vector and add/remove shapes as needed. . Objective: Work with dynamic
  container resizing, and understand how to manage adding and removing elements
  in std::vector.

*/
/*
    1. Store Multiple Shapes Using Containers
        . Task: Modify the code so that it stores multiple sf::CircleShape
   objects in an std::vector. The program should initialize the shapes with
   different radii and positions, and cycle through their colors. .  Hint: Use
   std::vector<sf::CircleShape> to store the shapes. .  Objective: Students
   should get used to working with dynamic containers like std::vector.
*/
namespace it_1 {
export void app() {

  // Store data in pre-defined variable
  constexpr int width{200};
  constexpr int height{200};
  constexpr float circle_radius{10.f};
  constexpr float clock_period{.02f};
  const std::string title{"SFML works!"};
  sf::Color shape_color{sf::Color::Green};
  sf::Color background_color{sf::Color::Red};

  sf::RenderWindow window(sf::VideoMode({width, height}), title);

  std::vector<sf::CircleShape> shapes;

  for (size_t i{0}; i < 5; ++i) {
    sf::CircleShape shape(circle_radius +
                          i * 10); // Vary radius slightly for each shape
    shape.setFillColor(shape_color);
    shape.setPosition({i * 20.f, 50.f}); // Set the position of each shape.
    shapes.push_back(shape);
  }

  while (window.isOpen()) {
    // Process events
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }

      // Key Events
      if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
          window.close();

        if (keyPressed->scancode == sf::Keyboard::Scancode::B) {
          for (auto &shape : shapes) {
            shape.setFillColor(sf::Color::Blue);
          }
        }
        if (keyPressed->scancode == sf::Keyboard::Scancode::Y) {
          for (auto &shape : shapes) {
            shape.setFillColor(sf::Color::Yellow);
          }
        }

        // C and D will increase and decrease the radius of the circle
        if (keyPressed->scancode == sf::Keyboard::Scancode::I) {
          for (auto &shape : shapes) {
            shape.setRadius(shape.getRadius() + 10.f);
          }
        }
        if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
          for (auto &shape : shapes) {
            // Protect against negative radius
            if (shape.getRadius() > 10.f) {
              shape.setRadius(shape.getRadius() - 10.f);
            }
          }
        }
      }
      // Mouse Events
    }

    window.clear(background_color);
    // window.draw(shape);
    for (size_t i{0}; i < 5; ++i) {
      window.draw(shapes[i]);
    }
    window.display();
  }
}
} // namespace it_1

/*

    2. Track Key Press History with a Fixed-Size Container
        . Task: Track the last 5 keys pressed by the user and display the
   history in the console. Use std::array<char, 5> to store the key history. .
   Hint: Use an index to cycle through the array and update it with the new key
   presses. . Objective: Practice with std::array for fixed-size containers and
   updating data circularly.

*/
namespace it_2 {

export void app() {
  // Store data in pre-defined variable
  constexpr int width{200};
  constexpr int height{200};
  constexpr float circle_radius{10.f};
  constexpr float clock_period{.02f};
  const std::string title{"SFML works!"};
  sf::Color shape_color{sf::Color::Green};
  sf::Color background_color{sf::Color::Red};

  sf::RenderWindow window(sf::VideoMode({width, height}), title);

  std::vector<sf::CircleShape> shapes;

  // Array to store the last 5 keys pressed
  std::array<char, 5> key_history{' ', ' ', ' ', ' ', ' '};
  size_t key_index{0};

  for (size_t i{0}; i < 5; ++i) {
    sf::CircleShape shape(circle_radius +
                          i * 10); // Vary radius slightly for each shape
    shape.setFillColor(shape_color);
    shape.setPosition({i * 20.f, 50.f}); // Set the position of each shape.
    shapes.push_back(shape);
  }

  while (window.isOpen()) {
    // Process events
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }

      // Key Events
      if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
          window.close();
        }

        // Store latest key pressed
        char pressed_key{' '};

        if (keyPressed->scancode == sf::Keyboard::Scancode::B) {
          pressed_key = 'B';
          for (auto &shape : shapes) {
            shape.setFillColor(sf::Color::Blue);
          }
        }
        if (keyPressed->scancode == sf::Keyboard::Scancode::Y) {
          pressed_key = 'Y';
          for (auto &shape : shapes) {
            shape.setFillColor(sf::Color::Yellow);
          }
        }

        // C and D will increase and decrease the radius of the circle
        if (keyPressed->scancode == sf::Keyboard::Scancode::I) {
          for (auto &shape : shapes) {
            shape.setRadius(shape.getRadius() + 10.f);
          }
          pressed_key = 'I';
        }
        if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
          for (auto &shape : shapes) {
            // Protect against negative radius
            if (shape.getRadius() > 10.f) {
              shape.setRadius(shape.getRadius() - 10.f);
            }
          }
          pressed_key = 'D';
        }
        // Store the current key and print history
        if (pressed_key != ' ') {
          /*
          //This places the most recent key at the most current circular index.
          Not ideal key_history[key_index] = pressed_key; key_index = (key_index
          + 1) % key_history.size(); // Update the index circularly
          */

          // We want the most recent key to be at index 0
          //  Shift all the elements to the right
          for (size_t i = key_history.size() - 1; i > 0; --i) {
            key_history[i] = key_history[i - 1];
          }

          // Store the most recent key at index 0
          key_history[0] = pressed_key;

          // Print the last keys pressed
          std::cout << "Key history: ";
          if (key_history[0] != ' ') {
            std::cout << key_history[0];
          }
          for (size_t i = 1; i < key_history.size(); ++i) {
            if (key_history[i] != ' ') {
              std::cout << ' ' << '-' << '>' << ' ' << key_history[i];
            }
          }
          std::cout << "\n";
        }
      }

      // Mouse Events
    }

    window.clear(background_color);
    // window.draw(shape);
    for (size_t i{0}; i < 5; ++i) {
      window.draw(shapes[i]);
    }
    window.display();
  }
}

} // namespace it_2

/*
 3. Store Color Changes in a Static Array
                . Task: Store a predefined sequence of colors in a built-in
 array, and cycle through them each time a specific key (e.g., space bar) is
 pressed to change the shape's fill color. . Hint: Use a built-in array like
 sf::Color colors[4] to store the color sequence and manage the index. .
 Objective: Get familiar with accessing data in built-in arrays and manipulating
 the shape’s color.
*/

namespace it_3 {

export void app() {
  // Store data in pre-defined variable
  constexpr int width{200};
  constexpr int height{200};
  constexpr float circle_radius{10.f};
  constexpr float clock_period{.02f};
  const std::string title{"SFML works!"};
  sf::Color shape_color{sf::Color::Green};
  sf::Color background_color{sf::Color::Red};

  sf::RenderWindow window(sf::VideoMode({width, height}), title);

  std::vector<sf::CircleShape> shapes;

  // Built-in array to store predefined colors
  sf::Color colors[4]{
      sf::Color::Cyan,  //
      sf::Color::Green, //
      sf::Color::Blue,  //
      sf::Color::Yellow //
  };

  // Index to keep track of the current color
  int color_index{0};

  for (size_t i{0}; i < 5; ++i) {
    sf::CircleShape shape(circle_radius +
                          i * 10); // Vary radius slightly for each shape
    shape.setFillColor(colors[color_index]);
    shape.setPosition({i * 20.f, 50.f}); // Set the position of each shape.
    shapes.push_back(shape);
  }

  while (window.isOpen()) {

    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }

      // Key Events
      if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
          window.close();
        }

        if (keyPressed->scancode == sf::Keyboard::Scancode::Space) {
          std::cout << "Space was pressed" << std::endl;
          color_index = (color_index + 1) % std::size(colors);
          for (auto &shape : shapes) {
            shape.setFillColor(colors[color_index]);
            std::cout << "current index: " << color_index << "\n";
          }
        }
      }
    }

    window.clear(background_color);
    // window.draw(shape);
    for (size_t i{0}; i < 5; ++i) {
      window.draw(shapes[i]);
    }
    window.display();
  }
}
} // namespace it_3

/*
    4. Animate Multiple Shapes with Timers
        . Task: Create multiple shapes (using std::vector or std::array) and
   move them both horizontally and vertically across the window .

*/
namespace it_4 {
export void app() {
  // Store data in pre-defined variable
  constexpr int width{600};
  constexpr int height{600};
  constexpr float circle_radius{40.f};
  constexpr float clock_period{.02f};
  const std::string title{"SFML Shape Animator"};
  sf::Color shape_color{sf::Color::Green};
  sf::Color background_color{sf::Color::Black};

  sf::RenderWindow window(sf::VideoMode({width, height}), title);

  // Vector to store multiple shpes
  std::vector<sf::CircleShape> shapes;

  // Vector to store the movement direction for each shape
  std::vector<sf::Vector2f> directions;

  // Set up the shapes
  for (size_t i{0}; i < 5; ++i) {
    sf::CircleShape shape(circle_radius);
    shape.setPosition({100.f * (i + 1), 100.f});
    shape.setFillColor(sf::Color(50 * i, 100 + (30 * i), 200 - (40 * i)));
    shapes.push_back(shape);

    // Initial direction for each shape (moving diagonally)
    directions.push_back(sf::Vector2f(1.f, 1.f));
  }

  // Timer setup
  sf::Clock clock;
  constexpr float move_interval{0.004f}; // Move shapes every 50 milliseconds

  while (window.isOpen()) {

    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }

      // Key Events
      if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
          window.close();
        }
      }
    }

    // Timer based movement
    if (clock.getElapsedTime().asSeconds() > move_interval) {
      for (size_t i{0}; i < shapes.size(); ++i) {
        auto &shape = shapes[i];
        auto &direction = directions[i];

        // Get the current position of the shape
        sf::Vector2f position = shape.getPosition();

        // Check for collisions with window edges and reverse direction
        if (position.x <= 0.f || position.x + circle_radius * 2 >= width) {
          direction.x = -direction.x; // Reverse horizontal direction
        }
        if (position.y <= 0.f || position.y + circle_radius * 2 >= height) {
          direction.y = -direction.y; // Reverse vertical direction
        }

        // Move the shapes in the current direction
        shape.move(direction);
      }
      clock.restart();
    }

    window.clear(background_color);
    for (size_t i{0}; i < shapes.size(); ++i) {
      window.draw(shapes[i]);
    }
    window.display();
  }
}
} // namespace it_4

/*
    5. Draw shapes at the position where the mouse is clicked in the window
        . Task: Draw the shapes in a way that the colors are random, and the
   radii are random . Hint: Dynamically adjust the size of the container using
   std::vector and add/remove shapes as needed. . Objective: Work with dynamic
   container resizing, and understand how to manage adding and removing elements
   in std::vector.

*/
namespace it_5 {

export void app() {
  // Store data in pre-defined variable
  constexpr int width{600};
  constexpr int height{600};
  constexpr float circle_radius{40.f};
  constexpr float clock_period{.02f};
  const std::string title{"SFML Shape Resizer"};
  sf::Color shape_color{sf::Color::Green};
  sf::Color background_color{sf::Color::Black};

  sf::RenderWindow window(sf::VideoMode({width, height}), title);

  // Vector to store multiple shpes
  std::vector<sf::CircleShape> shapes;

  // Random number generation setup
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> radius_distr(
      10.f, 50.f); // Circle sizes between 10 and 50
  std::uniform_int_distribution<int> color_distr(
      0, 255); // Colors in the RGB range

  while (window.isOpen()) {

    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }

      // Key Events
      if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
          window.close();
        }

        if (keyPressed->scancode == sf::Keyboard::Scancode::Backspace) {
          // Remove the last shape
          if (shapes.empty()) {
            window.close();
          }

          if (!shapes.empty()) {
            shapes.pop_back();
          }
        }
      }

      // Mouse events
      if (const auto *mouseButtonPressed =
              event->getIf<sf::Event::MouseButtonPressed>()) {
        // If the left button is pressed
        if (mouseButtonPressed->button == sf::Mouse::Button::Left) {

          // Add shape at the position of the cursor

          // Grab the mouse position
          sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
          float mouse_x = static_cast<float>(mouse_pos.x);
          float mouse_y = static_cast<float>(mouse_pos.y);

          // Generate the random radius
          float random_radius = radius_distr(gen);

          // Adjust position to keep the shape fully within bounds
          if (mouse_x + random_radius > width)
            mouse_x = width - random_radius;
          if (mouse_x - random_radius < 0)
            mouse_x = random_radius;
          if (mouse_y + random_radius > height)
            mouse_y = height - random_radius;
          if (mouse_y - random_radius < 0)
            mouse_y = random_radius;

          // Generate the random color
          sf::Color random_color(color_distr(gen), color_distr(gen),
                                 color_distr(gen));

          // Create the shape and add it to the vector
          sf::CircleShape new_shape(random_radius);
          new_shape.setFillColor(random_color);
          new_shape.setPosition({mouse_x - random_radius,
                                 mouse_y - random_radius}); // Center the shape
          shapes.push_back(new_shape);
        }
      }
    }

    window.clear(background_color);
    for (size_t i{0}; i < shapes.size(); ++i) {
      window.draw(shapes[i]);
    }
    window.display();
  }
}
} // namespace it_5
