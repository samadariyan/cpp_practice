module;

#include <SFML/Graphics.hpp> // Global module fragment

export module utilities;

export void app() {
  // Store data in pre-defined variable
  int width{200};
  int height{200};
  float circle_radius{100.f};
  std::string title{"SFML works!"};
  sf::Color shape_color{sf::Color::Green};
  sf::Color background_color{sf::Color::Red};

  sf::RenderWindow window(sf::VideoMode({200, 200}), title);
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen()) {
    // Process events
    while (const std::optional event = window.pollEvent()) {
      // Close window: exit
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    window.clear(background_color);
    window.draw(shape);
    window.display();
  }
}

/*

  // Load a sprite to display
  const sf::Texture texture("cute_image.jpg");
  sf::Sprite sprite(texture);

  // Create a graphical text to display
  const sf::Font font("arial.ttf");
  sf::Text text(font, "Hello SFML", 50);

  // Load a music to play
  sf::Music music("nice_music.ogg");

  // Play the music
  music.play();

  // Start the game loop

    // Clear screen
    window.clear();

    // Draw the sprite
    window.draw(sprite);

    // Draw the string
    window.draw(text);

    // Update the window
    window.display();
  }
*/

/*
module;

#include <fmt/format.h>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

export module utilities;

export unsigned char mask_bit_1{0b00000001}; // Bit0
export unsigned char mask_bit_2{0b00000010}; // Bit1
export unsigned char mask_bit_3{0b00000100}; // Bit2
export unsigned char mask_bit_4{0b00001000}; // Bit3
export unsigned char mask_bit_5{0b00010000}; // Bit4
export unsigned char mask_bit_6{0b00100000}; // Bit5
export unsigned char mask_bit_7{0b01000000}; // Bit6
export unsigned char mask_bit_8{0b10000000}; // Bit7

export void use_options_v0(bool flag0, bool flag1, bool flag2, bool flag3,
                           bool flag4, bool flag5, bool flag6, bool flag7) {
  std::println("Flag0 is : {}, do something with it.", flag0);
  std::println("Flag1 is : {}, do something with it.", flag1);
  std::println("Flag2 is : {}, do something with it.", flag2);
  std::println("Flag3 is : {}, do something with it.", flag3);
  std::println("Flag4 is : {}, do something with it.", flag4);
  std::println("Flag5 is : {}, do something with it.", flag5);
  std::println("Flag6 is : {}, do something with it.", flag6);
  std::println("Flag7 is : {}, do something with it.", flag7);
}

export void use_options_v1(unsigned char flags) {
  std::println("bit0 is : {}, do something with it!",
               ((flags & mask_bit_1) >> 0));
  std::println("bit1 is: {}, do something with it! ",
               ((flags & mask_bit_2) >> 1));
  std::println("bit2 is: {}, do something with it! ",
               ((flags & mask_bit_3) >> 2));
  std::println("bit3 is: {}, do something with it! ",
               ((flags & mask_bit_4) >> 3));
  std::println("bit4 is: {}, do something with it! ",
               ((flags & mask_bit_5) >> 4));
  std::println("bit5 is: {}, do something with it! ",
               ((flags & mask_bit_6) >> 5));
  std::println("bit6 is: {}, do something with it! ",
               ((flags & mask_bit_7) >> 6));
  std::println("bit7 is: {}, do something with it! ",
               ((flags & mask_bit_8) >> 7));
}

export void pack_color_information() {
  unsigned int red_mask{0xFF000000};
  unsigned int green_mask{0x00FF0000};
  unsigned int blue_mask{0x0000FF00};
  unsigned int alpha_mask{0x000000FF}; // Transparency information

  unsigned int my_color{0xAABCDE00};

  // We shift to make sure the color byte of interest is in the
  //  lower index byte position so that we can interpret that as an integer,
  //  which will be between 0 and 255.
  std::println("Red is: {0:d}", ((my_color & red_mask) >> 24));
  std::println("Green is: {0:d}", ((my_color & green_mask) >> 16));
  std::println("Blue is: {0:d}", ((my_color & blue_mask) >> 8));
  std::println("Alpha is: {0:d}", ((my_color & alpha_mask) >> 0));
}
export void input_output_iostream() {
  // Data output
  std::cout << "Hello modern C++" << std::endl;
  std::cout << "How are you?" << std::endl;
  std::cout << "I am fine";

  // Data input
  unsigned age1{};
  std::string name{};
  std::cout << "Please state your name and age:" << std::endl;
  // std::cin >> name;
  // std::cin >> age1;
  // std::cin >> name >> age1;
  std::getline(std::cin, name);
  std::cin >> age1;
  std::cout << "Hello " << name << ". You are " << age1 << " years old!"
            << std::endl;

  // Data formating with std::endl and "\n"
  // Output formatting
  //  std::endl : places a new line character on the output stream.
  //         This is identical to placing '\n' on the output stream.
  std::cout << "Hello";
  std::cout << "World";

  std::cout << std::endl;

  std::cout << "-------------" << std::endl;

  std::cout << "Hello" << std::endl;
  std::cout << "World" << std::endl;

  std::cout << std::endl;

  std::cout << "Hello\n";
  std::cout << "World\n";
}

export void output_formatting() {
  // std::setw() : Adjusts the field with for the item about to be printed.
  // The setw() manipulator only affects the next value to be printed.
  /*
      std::cout << "Unformatted table : " << std::endl;
      std::cout << "Daniel" << " " << "Gray" << " 25" << std::endl;
      std::cout << "Stanley" << " " << "Woods" << " 33" << std::endl;
      std::cout << "Jordan" << " " << "Parker" << " 45" << std::endl;
      std::cout << "Joe" << " " << "Ball" << " 21" << std::endl;
      std::cout << "Josh" << " " << "Carr" << " 27" << std::endl;
      std::cout << "Izaiah" << " " << "Robinson" << " 29" << std::endl;


  std::cout << std::endl;
      std::cout << "Formatted table : " << std::endl;
      std::cout << std::setw(10) << "Lastname" << std::setw(10) << "Firstname"
  << std::setw(5) << "Age" << std::endl; std::cout << std::setw(10) << "Daniel"
  << std::setw(10) << "Gray" << std::setw(5) << "25" << std::endl; std::cout <<
  std::setw(10) << "Stanley" << std::setw(10) << "Woods" << std::setw(5) << "33"
  << std::endl; std::cout << std::setw(10) << "Jordan" << std::setw(10) <<
  "Parker" << std::setw(5) << "45" << std::endl; std::cout << std::setw(10) <<
  "Joe" << std::setw(10) << "Ball" << std::setw(5) << "21" << std::endl;
      std::cout << std::setw(10) << "Josh" << std::setw(10) << "Carr" <<
  std::setw(5) << "27" << std::endl; std::cout << std::setw(10) << "Izaiah" <<
  std::setw(10) << "Robinson" << std::setw(5) << "29" << std::endl;
  */

/**
     std::cout << "Formatted table with variables: " << std::endl;
     int col_width{ 14 };

     std::cout << std::setw(col_width) << "Lastname" << std::setw(col_width)
   << "Firstname" << std::setw(col_width / 2)
             << "Age" << std::endl;
     std::cout << std::setw(col_width) << "Daniel" << std::setw(col_width) <<
   "Gray" << std::setw(col_width / 2) << "25"
             << std::endl;
     std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width) <<
   "Woods" << std::setw(col_width / 2) << "33"
             << std::endl;
     std::cout << std::setw(col_width) << "Jordan" << std::setw(col_width) <<
   "Parker" << std::setw(col_width / 2) << "45"
             << std::endl;
     std::cout << std::setw(col_width) << "Joe" << std::setw(col_width) <<
   "Ball" << std::setw(col_width / 2) << "21"
             << std::endl;
     std::cout << std::setw(col_width) << "Josh" << std::setw(col_width) <<
   "Carr" << std::setw(col_width / 2) << "27"
             << std::endl;
     std::cout << std::setw(col_width) << "Izaiah" << std::setw(col_width) <<
   "Robinson" << std::setw(col_width / 2)
             << "29" << std::endl;
 */

//===================================================================

// Justify : Values can be justified in their fields. There are three
// manipulators
//           for adjusting the justification: left, right, and internal.

// right justified
/*
    std::cout << std::endl;
    std::cout << "Right justified table (default) :  " << std::endl;
    int col_width = 20;
    std::cout << std::right; // Right justify
    std::cout << std::setw(col_width) << "Lastname" <<
                            std::setw(col_width) << "Firstname" <<
                            std::setw(col_width / 2) << "Age" << std::endl;
    std::cout << std::setw(col_width) << "Daniel" <<
                            std::setw(col_width) << "Gray" <<
                            std::setw(col_width / 2) << "25" << std::endl;
    std::cout << std::setw(col_width) << "Stanley" <<
                            std::setw(col_width) << "Woods" <<
                            std::setw(col_width / 2) << "33" << std::endl;
    std::cout << std::setw(col_width) << "Jordan" <<
                            std::setw(col_width) << "Parker" <<
                            std::setw(col_width / 2) << "45" << std::endl;
    std::cout << std::setw(col_width) << "Joe" <<
                            std::setw(col_width) << "Ball" <<
                            std::setw(col_width / 2) << "21" << std::endl;
    std::cout << std::setw(col_width) << "Josh" <<
                            std::setw(col_width) << "Carr" <<
                            std::setw(col_width / 2) << "27" << std::endl;
    std::cout << std::setw(col_width) << "Izaiah" <<
                            std::setw(col_width) << "Robinson" <<
                            std::setw(col_width / 2) << "29" << std::endl;

// Left justified
    std::cout << std::endl;
    std::cout << "Left justified table :  " << std::endl;

    col_width = 20;

    std::cout << std::left;
    std::cout << std::setw(col_width) << "Lastname" <<
                            std::setw(col_width) << "Firstname" <<
                            std::setw(col_width / 2)<< "Age" << std::endl;
    std::cout << std::setw(col_width) << "Daniel" <<
                            std::setw(col_width) << "Gray" <<
                            std::setw(col_width / 2) << "25"<< std::endl;
    std::cout << std::setw(col_width) << "Stanley" <<
                            std::setw(col_width) << "Woods" <<
                            std::setw(col_width / 2) << "33" << std::endl;
    std::cout << std::setw(col_width) << "Jordan" <<
                            std::setw(col_width) << "Parker" <<
                            std::setw(col_width / 2) << "45" << std::endl;
    std::cout << std::setw(col_width) << "Joe" <<
                            std::setw(col_width) << "Ball" <<
                            std::setw(col_width / 2) << "21"<< std::endl;
    std::cout << std::setw(col_width) << "Josh" <<
                            std::setw(col_width) << "Carr" <<
                            std::setw(col_width / 2) << "27"<< std::endl;
    std::cout << std::setw(col_width) << "Izaiah" <<
                            std::setw(col_width) << "Robinson" <<
                            std::setw(col_width / 2)<< "29" << std::endl;


// Internal justified : sign is left justified , data is right justified
    std::cout << std::endl;
    std::cout << "Internal justified : " << std::endl;
    std::cout << std::right;
    std::cout << std::setw(10) << -123.45 << std::endl;
    std::cout << std::internal;
    std::cout << std::setw(10) << -123.45 << std::endl;
*/

//===================================================================
// Fill characters: std::setfill
/*

    std::cout << std::endl;
    std::cout << "Table with fill characters :  " << std::endl;

    unsigned col_width = 20;

std::cout << std::left;
std::cout << std::setfill('*'); // Fill character

// First row (headers)
std::cout << std::setw(col_width) << "Lastname"
          << std::setw(col_width) << "Firstname"
          << std::setw(col_width / 2) << "Age"
          << std::endl;

// Data rows
std::cout << std::setw(col_width) << "Daniel"
          << std::setw(col_width) << "Gray"
          << std::setw(col_width / 2) << "25"
          << std::endl;

std::cout << std::setw(col_width) << "Stanley"
          << std::setw(col_width) << "Woods"
          << std::setw(col_width / 2) << "33"
          << std::endl;

std::cout << std::setw(col_width) << "Jordan"
          << std::setw(col_width) << "Parker"
          << std::setw(col_width / 2) << "45"
          << std::endl;

std::cout << std::setw(col_width) << "Joe"
          << std::setw(col_width) << "Ball"
          << std::setw(col_width / 2) << "21"
          << std::endl;

std::cout << std::setw(col_width) << "Josh"
          << std::setw(col_width) << "Carr"
          << std::setw(col_width / 2) << "27"
          << std::endl;

std::cout << std::setw(col_width) << "Izaiah"
          << std::setw(col_width) << "Robinson"
          << std::setw(col_width / 2) << "29"
          << std::endl;
*/

//===================================================================
// boolalpha and noboolapha : control bool output format : 1/0 or true/false
/*
    bool condition{ true };
    bool other_condition{ false };

    std::cout << "condition : " << condition << std::endl;
    std::cout << "other_condition : " << other_condition << std::endl;

    std::cout << std::endl;
    std::cout << std::boolalpha;
    std::cout << "condition : " << condition << std::endl;
    std::cout << "other_condition : " << other_condition << std::endl;

    std::cout << std::endl;
    std::cout << std::noboolalpha;
    std::cout << "condition : " << condition << std::endl;
    std::cout << "other_condition : " << other_condition << std::endl;
*/

//===================================================================

// showpos and noshowpos : show or hide the +  sign for positive numbers
/*
    int pos_num{ 34 };
    int neg_num{ -45 };

    std::cout << "pos_num : " << pos_num << std::endl;
    std::cout << "neg_num : " << neg_num << std::endl;

    std::cout << std::endl;
    std::cout << std::showpos;
    std::cout << "pos_num : " << pos_num << std::endl;
    std::cout << "neg_num : " << neg_num << std::endl;

    std::cout << std::endl;
    std::cout << std::noshowpos;
    std::cout << "pos_num : " << pos_num << std::endl;
    std::cout << "neg_num : " << neg_num << std::endl;
*/

//===================================================================

// uppercase and nouppercase
/*
    int pos_int = 717171;

    std::cout << "pos_int (nouppercase : default) : " << std::endl;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
    std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
    std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;

    std::cout << std::endl;
    std::cout << "pos_int (uppercase) : " << std::endl;
    std::cout << std::uppercase;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
    std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
    std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;
*/
//===================================================================

// fixed and scientific : for floating point values
/*
    double a{ 3.1415926535897932384626433832795 };
    double b{ 2006.0 };
    double c{ 1.34e-10 };

    std::cout << std::endl;
    std::cout << "double values (default : use scientific where necessary) : "
   << std::endl; std::cout << "a : " << a << std::endl; std::cout << "b : " <<
   b << std::endl; std::cout << "c : " << c << std::endl;

    std::cout << std::endl;
    std::cout << "double values (fixed) : " << std::endl;
    std::cout << std::fixed;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;

    std::cout << std::endl;
    std::cout << "double values (scientific) : " << std::endl;
    std::cout << std::scientific;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;

    std::cout << std::endl;
    std::cout << "double values (back to defaults) : " << std::endl;
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);// Hack
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;


//===================================================================

// std::setprecision() : the number of digits printed for a floating point
// number. Default is 6
//
double a {3.1415926535897932384626433832795};

std::cout << "\n";
std::cout << "a (default precision: 6): " << a << "\n";
std::cout << std::setprecision(10);
std::cout << "a (precision: 10): " << a << "\n";
std::cout << std::setprecision(20);
std::cout << "a (precision: 20): " << a << "\n";



//===================================================================

// showpoint and noshowpoint : show trailing zeros if necessary
// Force output of the decimal point

double d{34.1};
double e{101.99};
double f{12.0};
int g{45};

std::cout << std::endl;
std::cout << "noshowpoint (default) : " << std::endl;
std::cout << "d : " << d << std::endl;
std::cout << "e : " << e << std::endl;
std::cout << "f : " << f << std::endl; // 12
std::cout << "g : " << g << std::endl;

std::cout << std::endl;
std::cout << "showpoint: " << std::endl;
std::cout << std::showpoint;
std::cout << "d : " << d << std::endl;
std::cout << "e : " << e << std::endl;
std::cout << "f : " << f << std::endl; // 12.0
std::cout << "g : " << g << std::endl;
}

export void external_format_facilities() {
  // Using the external format library
  auto value = std::format("Hello, {}!", "world");
  std::cout << value << "\n";
  std::print("Hello, {}!", "world\n");
  std::println("Unformatted table : ");
  std::println("{} {} {}", "Daniel", "Gray", "25");
  std::println("{} {} {}", "Stanley", "Woods", "33");
  std::println("{} {} {}", "Jordan", "Parker", "45");
  std::println("{} {} {}", "Joe", "Ball", "21");
  std::println("{} {} {}", "Josh", "Carr", "27");
  std::println("{} {} {}", "Izaiah", "Robinson", "29");

  std::println("-----");

  std::println("Formatted table : ");
  std::println("{:<10} {:<10} {:<5}", "Lastname", "Firstname", "Age");
  std::println("{:<10} {:<10} {:<5}", "Daniel", "Gray", "25");
  std::println("{:<10} {:<10} {:<5}", "Stanley", "Woods", "33");
  std::println("{:<10} {:<10} {:<5}", "Jordan", "Parker", "45");
  std::println("{:<10} {:<10} {:<5}", "Joe", "Ball", "21");
  std::println("{:<10} {:<10} {:<5}", "Josh", "Carr", "27");
  std::println("{:<10} {:<10} {:<5}", "Izaiah", "Robinson", "29");

  std::println("-----");

  // dynamic width
  int col_width{10};
  std::println("Formatted table with dynamic width: ");
  std::println("{:<{}} {:<{}} {:<{}}", "Lastname", col_width, "Firstname",
               col_width, "Age", col_width / 2);
  std::println("{:<{}} {:<{}} {:<{}}", "Daniel", col_width, "Gray", col_width,
               "25", col_width / 2);
  std::println("{:<{}} {:<{}} {:<{}}", "Stanley", col_width, "Woods", col_width,
               "33", col_width / 2);
  std::println("{:<{}} {:<{}} {:<{}}", "Jordan", col_width, "Parker", col_width,
               "45", col_width / 2);
  std::println("{:<{}} {:<{}} {:<{}}", "Joe", col_width, "Ball", col_width,
               "21", col_width / 2);
  std::println("{:<{}} {:<{}} {:<{}}", "Josh", col_width, "Carr", col_width,
               "27", col_width / 2);
  std::println("{:<{}} {:<{}} {:<{}}", "Izaiah", col_width, "Robinson",
               col_width, "29", col_width / 2);

  std::println("-----");

  // right justified
  std::println("Right justified table:  ");
  col_width = 20;
  std::println("{:>{}} {:>{}} {:>{}}", "Lastname", col_width, "Firstname",
               col_width, "Age", col_width / 2);
  std::println("{:>{}} {:>{}} {:>{}}", "Daniel", col_width, "Gray", col_width,
               "25", col_width / 2);
  std::println("{:>{}} {:>{}} {:>{}}", "Stanley", col_width, "Woods", col_width,
               "33", col_width / 2);
  std::println("{:>{}} {:>{}} {:>{}}", "Jordan", col_width, "Parker", col_width,
               "45", col_width / 2);
  std::println("{:>{}} {:>{}} {:>{}}", "Joe", col_width, "Ball", col_width,
               "21", col_width / 2);
  std::println("{:>{}} {:>{}} {:>{}}", "Josh", col_width, "Carr", col_width,
               "27", col_width / 2);
  std::println("{:>{}} {:>{}} {:>{}}", "Izaiah", col_width, "Robinson",
               col_width, "29", col_width / 2);

  std::println("-----");

  // left justified
  std::println("Left justified table :  ");
  col_width = 20;
  std::println("{:<{}} {:<{}} {:<{}}", "Lastname", col_width, "Firstname",
               col_width, "Age", col_width / 2);
  std::println("{:<{}} {:<{}} {:<{}}", "Daniel", col_width, "Gray", col_width,
               "25", col_width / 2);
  std::println("{:<{}} {:<{}} {:<{}}", "Stanley", col_width, "Woods", col_width,
               "33", col_width / 2);
  std::println("{:<{}} {:<{}} {:<{}}", "Jordan", col_width, "Parker", col_width,
               "45", col_width / 2);
  std::println("{:<{}} {:<{}} {:<{}}", "Joe", col_width, "Ball", col_width,
               "21", col_width / 2);
  std::println("{:<{}} {:<{}} {:<{}}", "Josh", col_width, "Carr", col_width,
               "27", col_width / 2);
  std::println("{:<{}} {:<{}} {:<{}}", "Izaiah", col_width, "Robinson",
               col_width, "29", col_width / 2);

  std::println("-----");

  // Internal justified
  std::println("Internal justified: ");
  std::print("{:>10}\n", -123.45);
  std::print("{:^10}\n", -123.45);
  std::print("{:<10}\n", -123.45);

  std::println("-----");

  // setfill
  std::println("Table with fill characters :  ");
  col_width = 20;
  std::println("{:*<{}} {:*<{}} {:*<{}}", "Lastname", col_width, "Firstname",
               col_width, "Age", col_width / 2);
  std::println("{:*<{}} {:*<{}} {:*<{}}", "Daniel", col_width, "Gray",
               col_width, "25", col_width / 2);
  std::println("{:*<{}} {:*<{}} {:*<{}}", "Stanley", col_width, "Woods",
               col_width, "33", col_width / 2);
  std::println("{:*<{}} {:*<{}} {:*<{}}", "Jordan", col_width, "Parker",
               col_width, "45", col_width / 2);
  std::println("{:*<{}} {:*<{}} {:*<{}}", "Joe", col_width, "Ball", col_width,
               "21", col_width / 2);
  std::println("{:*<{}} {:*<{}} {:*<{}}", "Josh", col_width, "Carr", col_width,
               "27", col_width / 2);
  std::println("{:*<{}} {:*<{}} {:*<{}}", "Izaiah", col_width, "Robinson",
               col_width, "29", col_width / 2);

  std::println("-----");

  // control bool output format : 1/0 or true/false
  bool condition{true};
  bool other_condition{false};

  std::println("condition: {}", condition);             // true
  std::println("other_condition: {}", other_condition); // false

  // This is a hack - ref: https://github.com/fmtlib/fmt/issues/170
  std::println("condition: {:d}", condition);
  std::println("other_condition: {:d}", other_condition);

  std::println("-----");

  // show or hide the +  sign for positive numbers
  std::println("show or hide the +  sign for positive numbers: ");
  int pos_num{34};
  int neg_num{-45};

  std::println("pos_num: {}", pos_num);
  std::println("neg_num: {}", neg_num);

  std::println("pos_num: {:+}", pos_num);
  std::println("neg_num: {:-}", neg_num);

  std::println("-----");

  // different number systems : std::dec, std::hex, std::oct
  std::println("different number systems: dec, hex, oct");
  int pos_int{717171};
  int neg_int{-5};
  double double_var{498.32};

  std::println("default base format : ");
  std::println("pos_int : {}", pos_int);
  std::println("neg_int : {}", neg_int);
  std::println("double_var : {}", double_var);

  std::println("pos_int in different bases : ");
  std::println("pos_int (dec) : {}", pos_int); // Default
  std::println("pos_int (hex) : {:x}", pos_int);
  std::println("pos_int (hex) : {:X}", pos_int);
  std::println("pos_int (oct) : {:o}", pos_int);
  std::println("pos_int (binary) : {:b}", pos_int);
  std::println("pos_int (decimal) : {:d}", pos_int);

  std::println("neg_int in different bases : ");
  std::println("neg_int (dec) : {}", neg_int);
  std::println("neg_int (hex) : {:x}", neg_int);
  std::println("neg_int (oct) : {:o}", neg_int);
  std::println("neg_int (binary) : {:08b}",
               neg_int); // Prints the pos number representation prepended with
                         // a negative sign. Make sure this is what you want.
  std::println("neg_int (decimal) : {:d}", neg_int);

  // We'll see more about floating point format specifiers shortly.
  std::println("double_var in different formats: ");
  std::println("double_var (default): {}", double_var);
  std::println("double_var (fixed): {:f}", double_var);
  std::println("double_var (scientific): {:e}", double_var);
  std::println("double_var (general): {:g}", double_var);

  std::println("-----");

  // uppercase and nouppercase
  std::println("uppercase and nouppercase: ");
  pos_int = 717171;
  std::println("pos_int (nouppercase - default): ");
  std::println("pos_int (dec): {}", pos_int);
  std::println("pos_int (hex): {:x}", pos_int);
  std::println("pos_int (oct): {:o}", pos_int);

  // For integers, the # toogles the alternative format flag. This shows the
  // base prefix like 0b, and 0x.
  std::println("pos_int (uppercase): ");
  std::println("{:#X}", pos_int);
  std::println("{:#B}", pos_int);

  std::println("-----");

  // fixed and scientific : for floating point values
  // control the precision.
  std::println("fixed and scientific: for floating point values: ");
  double a{3.1415926535897932384626433832795};
  double b{2006.0};
  double c{1.34e-10};

  std::println("double values (default : use scientific where necessary) : ");
  std::println("a : {}", a);
  std::println("b : {}", b);
  std::println("c : {}", c);

  std::println("double values (precision) : ");
  std::println("a: {:.6}", a);
  std::println("b: {:.6}", b);
  std::println("c: {:.6}", c);

  std::println("double values (fixed) : ");
  std::println("a: {:.6f}", a);
  std::println("b: {:.6f}", b);
  std::println("c: {:.6f}", c);

  std::println("double values (scientific) : ");
  std::println("a: {:.6e}", a);
  std::println("b: {:.6e}", b);
  std::println("c: {:.6e}", c);

  std::println("-----");

  // argument indexes: Allow us to order arguments. This is good for example for
  // applications that use localization.
  std::println("argument indexes: ");
  std::println("It's {:.2f} degrees outside and it's {}", 34.5, "sunny");
  std::println("It's {1} today. And the temperature is {0:.2f} degrees outside",
               34.5, "sunny");
}

export void print_ints_binary() {
  // Printing integers in binary
  unsigned short int data{15};

  std::println("data (dec): {0:d}", data);   // Decimal
  std::println("data (oct): {0:o}", data);   // Octal
  std::println("data (hex): {0:x}", data);   // Hexadecimal
  std::println("data (bin): {:016b}", data); // Binary (16 digits)
}

export void bitwise_shift_operators() {
  // Shift operators
  unsigned short int value{0xff0u};

  std::println("Size of short int: {}",
               sizeof(unsigned short int)); // 2 bytes or 16 bits
  std::println("binary value: {:016b}, decimal value: {}", value, value);

  // Shift left by one bit
  value = static_cast<unsigned short int>(value << 1);
  std::println("binary value: {:016b}, decimal value: {}", value, value);

  // Shift left by one bit
  value = static_cast<unsigned short int>(value << 1);
  std::println("binary value: {:016b}, decimal value: {}", value, value);

  // Shift left by one bit
  value = static_cast<unsigned short int>(value << 1);
  std::println("binary value: {:016b}, decimal value: {}", value, value);

  // Shift left by one bit
  value = static_cast<unsigned short int>(value << 1);
  std::println("binary value: {:016b}, decimal value: {}", value, value);

  // Shift left by one bit
  value = static_cast<unsigned short int>(value << 1);
  std::println("binary value: {:016b}, decimal value: {}", value, value);

  // Shift right by one bit
  value = static_cast<unsigned short int>(value >> 1);
  std::println("binary value: {:016b}, decimal value: {}", value, value);

  // Shift right by four bits in one go
  value = static_cast<unsigned short int>(value >> 4);
  std::println("binary value: {:016b}, decimal value: {}", value, value);
}

export void logical_bitwise_operators() {
  // Logical bitwise operators
  unsigned int value1{0x3}; // 0000 0011
  unsigned int value2{0x5}; // 0000 0101

  std::println("value1: {:08b}", value1);
  std::println("value2: {:08b}", value2);

  // Bitwise AND operator
  std::println("Bitwise and:");
  std::println("value1 & value2: {:08b}", (value1 & value2));

  // Bitwise OR operator
  std::println("Bitwise or:");
  std::println("value1 | value2: {:08b}", (value1 | value2));

  // Bitwise not
  std::println("Bitwise NOT :");
  std::println("~value1: {:08b}", ~value1);
  std::println("~value2: {:08b}", ~value2);

  // Bitwise XOR operator
  std::println("Bitwise xor:");
  std::println("value1 ^ value2: {:08b}", (value1 ^ value2));
}

export void compound_bitwise_operators() {
  // Compound bitwise opreators
  unsigned int sandbox_var{0b00110100};

  // Print out initial value
  std::println("Initial value: ");
  std::println("sandbox_var: {:08b}", sandbox_var);

  // Compound left shift
  std::println("Shift left 2 bit positions in place:  ");
  sandbox_var <<= 2;
  std::println("sandbox_var: {:08b}", sandbox_var);

  // Compound right shift
  std::println("Shift right 4 bit positions in place:  ");
  sandbox_var >>= 4;
  std::println("sandbox_var: {:08b}", sandbox_var);

  // Compound OR with 0000 0010 to have all lower 4 bits turned on
  std::println("Compound OR with 0000 0010 :  ");
  sandbox_var |= 0b00001111;
  std::println("sandbox_var: {:08b}", sandbox_var);

  // Compound AND with 0000 1100 to turn off the 2 lowest bits
  std::println("Compound AND with 0000 1100 :  ");
  sandbox_var &= 0b000001100;
  std::println("sandbox_var: {:08b}", sandbox_var);

  // XOR with 00000011 to turn on the 4 lowest bits again
  std::println("Compound XOR with 0000 0011 :  ");
  sandbox_var ^= 0b00000011;
  std::println("sandbox_var: {:08b}", sandbox_var);
}

export void masks() {
  // Masks: highlight a bit of interest and turn off all the others
  unsigned int mask_bit_1{0b00000001}; // bit 1
  unsigned int mask_bit_2{0b00000010}; // bit 2
  unsigned int mask_bit_3{0b00000100}; // bit 3
  unsigned int mask_bit_4{0b00001000}; // bit 4
  unsigned int mask_bit_5{0b00010000}; // bit 5
  unsigned int mask_bit_6{0b00100000}; // bit 6
  unsigned int mask_bit_7{0b01000000}; // bit 7
  unsigned int mask_bit_8{0b10000001}; // bit 8

  // Sandbox variable
  unsigned int var{0b00000000}; // Starts off all bits off
  std::println("var: {:08b}", var);
  std::println("\n");

  // SETTING BITS
  // Setting : |= with mask of the bit

  std::println("Turning on bit in position 2");
  var |= mask_bit_2; // Turn on bit in position 2
  std::println("var: {:08b}", var);
  std::println("\n");

  // Set bit 5
  std::println("Setting bit in position 6: ");
  var |= mask_bit_6;
  std::println("var: {:08b}", var);
  std::println("\n");

  // RESETTING BITS : set to 0
  // Resetting : &= (~mask)

  std::println("Turning off bit in position 2");
  var &= (~mask_bit_2); // Turn off bit in position 1
  std::println("var: {:08b}", var);
  std::println("\n");

  std::println("Turning off bit in position 6");
  var &= (~mask_bit_6); // Turn off bit in position 5
  std::println("var: {:08b}", var);
  std::println("\n");

  // Set all bits
  std::print("Setting all bits: ");
  var |= (mask_bit_1 | mask_bit_2 | mask_bit_3 | mask_bit_4 | mask_bit_5 |
          mask_bit_6 | mask_bit_7 | mask_bit_8);
  std::println("var: {:08b}", var);
  std::println("\n");

  // Reset bits at pos 0,2,4,6
  std::println("Reset bits at pos 1,3,5,7: ");
  var &= ~(mask_bit_1 | mask_bit_3 | mask_bit_5 | mask_bit_7);
  std::println("var: {:08b}", var);
  std::println("\n");

  // Check state of a bit: & with mask
  std::println("Checking the state of each bit position (on/off): ");
  std::println("bit1 is {}", static_cast<bool>(var & mask_bit_1));
  std::println("bit2 is {}", static_cast<bool>(var & mask_bit_2));
  std::println("bit3 is {}", static_cast<bool>(var & mask_bit_3));
  std::println("bit4 is {}", static_cast<bool>(var & mask_bit_4));
  std::println("bit5 is {}", static_cast<bool>(var & mask_bit_5));
  std::println("bit6 is {}", static_cast<bool>(var & mask_bit_6));
  std::println("bit7 is {}", static_cast<bool>(var & mask_bit_7));
  std::println("bit8 is {}", static_cast<bool>(var & mask_bit_8));

  std::println("\n");

  std::println("bit8 is {}", (var & mask_bit_7) >> 6);
  std::println("bit8 is {}", (var & mask_bit_8) >> 7);
  std::println("\n");

  // Toggle bits
  // Toggle : var ^ mask

  // Toggle bit 0
  std::println("Toggle bit 1: ");
  var ^= mask_bit_1;
  std::println("var: {:08b}", var);
  std::println("\n");

  // Toggle bit7
  std::println("Toggle bit 8: ");
  var ^= mask_bit_8;
  std::println("var: {:08b}", var);
  std::println("\n");

  // Toggle multiple bits in one go : the 4 higher bits
  std::println("Toggle multiple bits in one go : the 4 higher bits: ");
  var ^= (mask_bit_8 | mask_bit_7 | mask_bit_6 | mask_bit_5);
  std::println("var: {:08b}", var);
}
*/