module;

#include <SFML/Graphics.hpp>
#include <fmt/format.h>
#include <string>

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
      //   shape.setFillColor(sf::Color::Black);
      // }else if(shape.getRadius() < 150.f){
      //   shape.setFillColor(sf::Color::Blue);
      // }

      window.clear(background_color);
      window.draw(shape);
      window.display();
    }
  }
}

export void declare_and_initialize() {
  // Basic Declaration and Initialization
  // Declaring a std::string and initializing it with a literal
  std::string str1 = "Hello, World!";
  fmt::println("str1: {}", str1);
}

export void construction() {
  // Using Constructors
  //  Creating a std::string using various constructors
  std::string str1{"Hello world"};
  std::string str2(str1); // Copy constructor
  std::string str3(str1, 7,
                   5); // Substring constructor: start at index 7, length 5
  std::string str4(10, 'A'); // Fill constructor: 10 characters of 'A'
  fmt::println("str2: {}", str2);
  fmt::println("str3: {}", str3);
  fmt::println("str4: {}", str4);
}

export void access_and_modify() {
  // Accessing Characters
  //  Accessing individual characters using the [] operator and at() method
  std::string str1{"Hello world!"};
  fmt::println("First character of str1: {}", str1[0]);
  fmt::println("Second character of str1 using at(): {}", str1.at(1));

  // Modifying Strings
  //  Modifying characters in the string
  str1[0] = 'h';
  str1.at(7) = 'w';
  fmt::println("Modified str1: {}", str1);
}

export void appending_and_concatenation() {
  // Appending and Concatenation
  // Appending to a string using operator+= and append()
  std::string str1{"Hello world!"};
  std::string str2{"Dog"};
  str1 += " How are you?";
  str2.append(" Goodbye!");
  fmt::println("Appended str1: {}", str1);
  fmt::println("Appended str2: {}", str2);

  // Concatenating strings using operator+
  std::string str3{"How are you."};
  std::string str5 = str3 + " Everyone!";
  fmt::println("Concatenated str5: {}", str5);
}

export void substrings_and_finding() {
  // Substrings
  //  Extracting a substring using substr()
  std::string str1{"Hello world"};
  std::string subStr = str1.substr(7, 5); // Start at index 7, length 5
  fmt::println("Substring of str1: {}", subStr);

  // Finding Substrings
  //  Finding a substring within a string using find()
  size_t pos = str1.find("World");
  if (pos != std::string::npos) {
    fmt::println("'World' found at position: {}", pos);
  } else {
    fmt::println("'World' not found");
  }
}

export void comparison() {
  // Comparison
  // Comparing strings using compare()
  std::string str1{"Hello"};
  std::string str2{"World"};
  if (str1.compare(str2) == 0) {
    fmt::println("str1 is equal to str2");
  } else {
    fmt::println("str1 is not equal to str2");
  }

  if (str1.compare(str2) > 0) {
    fmt::println("str1 is greater");
  } else {
    fmt::println("str2 is greater");
  }
}

export void inserting_and_erasing() {
  // Inserting and Erasing
  // Inserting a substring into a string
  std::string str1{"Hello world"};
  str1.insert(5, ", Beautiful");
  fmt::println("After insertion: {}", str1);

  // Erasing a part of the string
  str1.erase(5, 11); // Erase 11 characters starting from index 5
  fmt::println("After erasing: {}", str1);
}

export void length_capacity_clear() {
  // Length and Capacity
  //  Getting the length and capacity of a string
  std::string str1{"Hello world!"};
  fmt::println("Length of str1: {}", str1.length());
  fmt::println("Capacity of str1: {}", str1.capacity());

  // Iterating over a string
  // Using range-based for loop to iterate over a string
  fmt::print("Characters in str1: ");
  for (const auto &ch : str1) {
    fmt::print("{} ", ch);
  }
  fmt::print("\n");

  // Clearing a string
  // Clearing the contents of a string
  str1.clear();
  fmt::println("Cleared str1, new length: {}", str1.length());
}

export void declaration_and_initialization() {
  // Declare and initialize an array
  // constexpr size_t array_size {5};

  // Declare the array
  // int scores [array_size]; // Junk data because the array is not initialized.

  // Read data
  /*
  fmt::println( "scores [0]: {}", scores[0] );
  fmt::println( "scores [1]: {}", scores[1] );

  // Read with a loop
  for( size_t i {0} ; i < array_size ; ++i){
      fmt::println("scores [{}]: {}", i, scores[i] );
  }

  //Writing data back into the array
  scores[0] = 20;
  scores[1] = 21;
  scores[2] = 22;

  //Print the data out
  fmt::println("Printing after changing the data: ");
  for( size_t i {0} ; i < array_size ; ++i){
      fmt::println("scores [{}] : {}", i, scores[i] );
  }
  */

  // Write data in a loop
  /*
  fmt::println("Changing the data in a loop");
  for(size_t i{0}; i < array_size ; ++i){
      scores[i] = i * 10;
  }

  //Print the data out
  for( size_t i {0} ; i < array_size ; ++i){
      fmt::println("scores [{}] : {}", i, scores[i] );
  }
  */

  // Declare and initialize at the same time
  /*
  double salaries[5] {12.7, 7.5, 13.2, 8.1, 9.3};
  for(size_t i{0}; i < 5; ++i){
      fmt::println("salaries [{}]: {}", i, salaries[i] );
  }

  // If you don't initialize all the elements, those you leave out
  // are initialized to 0
  int families[5] {12, 7, 5};
      for(size_t i{0}; i < 5; ++i){
      fmt::println("families [{}]: {}", i, families[i] );
  }
  */

  // Omit the size of the array at declaration
  int class_sizes[]{10, 12, 15, 11, 18, 17, 23, 56};
  // Will print this with a range based for loop

  for (auto value : class_sizes) {
    fmt::println("value: {}", value);
  }

  // Read only arrays
  const int birds[]{10, 12, 15, 11, 18, 17, 23, 56};
  // birds[0] = 11;

  // Sum up scores array, store result in sum
  int scores[]{2, 5, 8, 2, 5, 6, 9};
  int sum{0};

  for (int element : scores) {
    sum += element;
  }
  fmt::println("Score sum: {}", sum);
}

export void size_of_an_array() {
  // Size of an array
  int scores[]{1, 2, 5};
  // int count{ std::size(scores) };// std::size( C++17)

  fmt::println("sizeof(scores) : {}", sizeof(scores));       // 12
  fmt::println("sizeof(scores[0]) : {}", sizeof(scores[0])); // 4
  // fmt::println("count : {}", count);  //3

  int count{sizeof(scores) / sizeof(scores[0])};

  // Loop through the elements of the array
  for (size_t i{}; i < count; ++i) {
    fmt::println("scores[{}]: {}", i, scores[i]);
  }
}

export void arrays_of_characters() {
  // Arrays of characters
  // char message[5] {'H', 'e', 'l', 'l', 'o'}; // No space for null terminator.
  // BAD. May crash your program
  char message[6]{'H', 'e', 'l',
                  'l', 'o', '\0'}; // The null terminator is there. GOOD
  // char message [] { 'H', 'e', 'l', 'l', 'o', '\0' }; // Good. Null terminator
  // included char message[] { 'H', 'e', 'l', 'l', 'o' }; // Deduced size 5. No
  // space for null terminator. BAD. char message[6]{ 'H', 'e', 'l', 'l', 'o' };
  // // Good. Null terminator is auto filled in. I wouldn't rely on this though.

  // fmt::println("Message: {}", message);

  int data[5]{1, 2, 3, 4, 5};
  // fmt::println("Data: {}", data); // fmt knows how to print arrays of
  // characters.

  // Print out the array through looping
  fmt::println("message : ");
  for (auto c : message) {
    fmt::println("{}", c);
  }

  // Change characters in our array
  message[1] = 'a';

  // Print out the array through looping
  fmt::println("message : ");
  for (auto c : message) {
    fmt::println("{}", c);
  }

  // If a character array is null terminated, it's called as C-String
  char message1[]{'H', 'e', 'l', 'l', 'o', '\0'};
  fmt::println("message1 : {}", message1);
  fmt::println("sizeof(message1) : {}", sizeof(message1)); // 6

  // String literal
  char message4[]{"Hello"}; // The null terminator is auto filled in.
  fmt::println("message4 : {}", message4);
  fmt::println("sizeof(message4) : {}", sizeof(message4)); // 6
}

export void array_bounds() {
  // Array bounds
  int numbers[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // Read beyond bounds : May read garbage or crash your program
  fmt::println("numbers[12] : {}", numbers[12]);

  // Write beyond bounds. The compiler allows it. But you don't own
  // the memory at index 12, so other programs may modify it and your
  // program may read bogus data at a later time. Or you can even
  // corrupt data used by other parts of your ptogram

  numbers[129] = 1000;
  fmt::println("numbers[129]: {}", numbers[129]);

  fmt::println("Program ending....");
}
