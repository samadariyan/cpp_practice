module;

#include <fmt/format.h>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

export module utilities;

export unsigned char mask_bit_0{0b00000001}; // Bit0
export unsigned char mask_bit_1{0b00000010}; // Bit1
export unsigned char mask_bit_2{0b00000100}; // Bit2
export unsigned char mask_bit_3{0b00001000}; // Bit3
export unsigned char mask_bit_4{0b00010000}; // Bit4
export unsigned char mask_bit_5{0b00100000}; // Bit5
export unsigned char mask_bit_6{0b01000000}; // Bit6
export unsigned char mask_bit_7{0b10000000}; // Bit7

export void use_options_v0(bool flag0, bool flag1, bool flag2, bool flag3,
                           bool flag4, bool flag5, bool flag6, bool flag7) {
  fmt::println("Flag0 is : {}, do something with it.", flag0);
  fmt::println("Flag1 is : {}, do something with it.", flag1);
  fmt::println("Flag2 is : {}, do something with it.", flag2);
  fmt::println("Flag3 is : {}, do something with it.", flag3);
  fmt::println("Flag4 is : {}, do something with it.", flag4);
  fmt::println("Flag5 is : {}, do something with it.", flag5);
  fmt::println("Flag6 is : {}, do something with it.", flag6);
  fmt::println("Flag7 is : {}, do something with it.", flag7);
}

export void use_options_v1(unsigned char flags) {
  fmt::println("bit0 is : {}, do something with it!",
               ((flags & mask_bit_0) >> 0));
  fmt::println("bit1 is: {}, do something with it! ",
               ((flags & mask_bit_1) >> 1));
  fmt::println("bit2 is: {}, do something with it! ",
               ((flags & mask_bit_2) >> 2));
  fmt::println("bit3 is: {}, do something with it! ",
               ((flags & mask_bit_3) >> 3));
  fmt::println("bit4 is: {}, do something with it! ",
               ((flags & mask_bit_4) >> 4));
  fmt::println("bit5 is: {}, do something with it! ",
               ((flags & mask_bit_5) >> 5));
  fmt::println("bit6 is: {}, do something with it! ",
               ((flags & mask_bit_6) >> 6));
  fmt::println("bit7 is: {}, do something with it! ",
               ((flags & mask_bit_7) >> 7));
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
  fmt::println("Red is: {0:d}", ((my_color & red_mask) >> 24));
  fmt::println("Green is: {0:d}", ((my_color & green_mask) >> 16));
  fmt::println("Blue is: {0:d}", ((my_color & blue_mask) >> 8));
  fmt::println("Alpha is: {0:d}", ((my_color & alpha_mask) >> 0));
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
  */

  //===================================================================

  // std::setprecision() : the number of digits printed for a floating point
  // number. Default is 6
  /*
  double a {3.1415926535897932384626433832795};

  std::cout << "\n";
  std::cout << "a (default precision: 6): " << a << "\n";
  std::cout << std::setprecision(10);
  std::cout << "a (precision: 10): " << a << "\n";
  std::cout << std::setprecision(20);
  std::cout << "a (precision: 20): " << a << "\n";

  */

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
  auto value = fmt::format("Hello, {}!", "world");
  std::cout << value << "\n";
  fmt::print("Hello, {}!", "world\n");
  fmt::println("Unformatted table : ");
  fmt::println("{} {} {}", "Daniel", "Gray", "25");
  fmt::println("{} {} {}", "Stanley", "Woods", "33");
  fmt::println("{} {} {}", "Jordan", "Parker", "45");
  fmt::println("{} {} {}", "Joe", "Ball", "21");
  fmt::println("{} {} {}", "Josh", "Carr", "27");
  fmt::println("{} {} {}", "Izaiah", "Robinson", "29");

  fmt::println("-----");

  fmt::println("Formatted table : ");
  fmt::println("{:<10} {:<10} {:<5}", "Lastname", "Firstname", "Age");
  fmt::println("{:<10} {:<10} {:<5}", "Daniel", "Gray", "25");
  fmt::println("{:<10} {:<10} {:<5}", "Stanley", "Woods", "33");
  fmt::println("{:<10} {:<10} {:<5}", "Jordan", "Parker", "45");
  fmt::println("{:<10} {:<10} {:<5}", "Joe", "Ball", "21");
  fmt::println("{:<10} {:<10} {:<5}", "Josh", "Carr", "27");
  fmt::println("{:<10} {:<10} {:<5}", "Izaiah", "Robinson", "29");

  fmt::println("-----");

  // dynamic width
  int col_width{10};
  fmt::println("Formatted table with dynamic width: ");
  fmt::println("{:<{}} {:<{}} {:<{}}", "Lastname", col_width, "Firstname",
               col_width, "Age", col_width / 2);
  fmt::println("{:<{}} {:<{}} {:<{}}", "Daniel", col_width, "Gray", col_width,
               "25", col_width / 2);
  fmt::println("{:<{}} {:<{}} {:<{}}", "Stanley", col_width, "Woods", col_width,
               "33", col_width / 2);
  fmt::println("{:<{}} {:<{}} {:<{}}", "Jordan", col_width, "Parker", col_width,
               "45", col_width / 2);
  fmt::println("{:<{}} {:<{}} {:<{}}", "Joe", col_width, "Ball", col_width,
               "21", col_width / 2);
  fmt::println("{:<{}} {:<{}} {:<{}}", "Josh", col_width, "Carr", col_width,
               "27", col_width / 2);
  fmt::println("{:<{}} {:<{}} {:<{}}", "Izaiah", col_width, "Robinson",
               col_width, "29", col_width / 2);

  fmt::println("-----");

  // right justified
  fmt::println("Right justified table:  ");
  col_width = 20;
  fmt::println("{:>{}} {:>{}} {:>{}}", "Lastname", col_width, "Firstname",
               col_width, "Age", col_width / 2);
  fmt::println("{:>{}} {:>{}} {:>{}}", "Daniel", col_width, "Gray", col_width,
               "25", col_width / 2);
  fmt::println("{:>{}} {:>{}} {:>{}}", "Stanley", col_width, "Woods", col_width,
               "33", col_width / 2);
  fmt::println("{:>{}} {:>{}} {:>{}}", "Jordan", col_width, "Parker", col_width,
               "45", col_width / 2);
  fmt::println("{:>{}} {:>{}} {:>{}}", "Joe", col_width, "Ball", col_width,
               "21", col_width / 2);
  fmt::println("{:>{}} {:>{}} {:>{}}", "Josh", col_width, "Carr", col_width,
               "27", col_width / 2);
  fmt::println("{:>{}} {:>{}} {:>{}}", "Izaiah", col_width, "Robinson",
               col_width, "29", col_width / 2);

  fmt::println("-----");

  // left justified
  fmt::println("Left justified table :  ");
  col_width = 20;
  fmt::println("{:<{}} {:<{}} {:<{}}", "Lastname", col_width, "Firstname",
               col_width, "Age", col_width / 2);
  fmt::println("{:<{}} {:<{}} {:<{}}", "Daniel", col_width, "Gray", col_width,
               "25", col_width / 2);
  fmt::println("{:<{}} {:<{}} {:<{}}", "Stanley", col_width, "Woods", col_width,
               "33", col_width / 2);
  fmt::println("{:<{}} {:<{}} {:<{}}", "Jordan", col_width, "Parker", col_width,
               "45", col_width / 2);
  fmt::println("{:<{}} {:<{}} {:<{}}", "Joe", col_width, "Ball", col_width,
               "21", col_width / 2);
  fmt::println("{:<{}} {:<{}} {:<{}}", "Josh", col_width, "Carr", col_width,
               "27", col_width / 2);
  fmt::println("{:<{}} {:<{}} {:<{}}", "Izaiah", col_width, "Robinson",
               col_width, "29", col_width / 2);

  fmt::println("-----");

  // Internal justified
  fmt::println("Internal justified: ");
  fmt::print("{:>10}\n", -123.45);
  fmt::print("{:^10}\n", -123.45);
  fmt::print("{:<10}\n", -123.45);

  fmt::println("-----");

  // setfill
  fmt::println("Table with fill characters :  ");
  col_width = 20;
  fmt::println("{:*<{}} {:*<{}} {:*<{}}", "Lastname", col_width, "Firstname",
               col_width, "Age", col_width / 2);
  fmt::println("{:*<{}} {:*<{}} {:*<{}}", "Daniel", col_width, "Gray",
               col_width, "25", col_width / 2);
  fmt::println("{:*<{}} {:*<{}} {:*<{}}", "Stanley", col_width, "Woods",
               col_width, "33", col_width / 2);
  fmt::println("{:*<{}} {:*<{}} {:*<{}}", "Jordan", col_width, "Parker",
               col_width, "45", col_width / 2);
  fmt::println("{:*<{}} {:*<{}} {:*<{}}", "Joe", col_width, "Ball", col_width,
               "21", col_width / 2);
  fmt::println("{:*<{}} {:*<{}} {:*<{}}", "Josh", col_width, "Carr", col_width,
               "27", col_width / 2);
  fmt::println("{:*<{}} {:*<{}} {:*<{}}", "Izaiah", col_width, "Robinson",
               col_width, "29", col_width / 2);

  fmt::println("-----");

  // control bool output format : 1/0 or true/false
  bool condition{true};
  bool other_condition{false};

  fmt::println("condition: {}", condition);             // true
  fmt::println("other_condition: {}", other_condition); // false

  // This is a hack - ref: https://github.com/fmtlib/fmt/issues/170
  fmt::println("condition: {:d}", condition);
  fmt::println("other_condition: {:d}", other_condition);

  fmt::println("-----");

  // show or hide the +  sign for positive numbers
  fmt::println("show or hide the +  sign for positive numbers: ");
  int pos_num{34};
  int neg_num{-45};

  fmt::println("pos_num: {}", pos_num);
  fmt::println("neg_num: {}", neg_num);

  fmt::println("pos_num: {:+}", pos_num);
  fmt::println("neg_num: {:-}", neg_num);

  fmt::println("-----");

  // different number systems : std::dec, std::hex, std::oct
  fmt::println("different number systems: dec, hex, oct");
  int pos_int{717171};
  int neg_int{-5};
  double double_var{498.32};

  fmt::println("default base format : ");
  fmt::println("pos_int : {}", pos_int);
  fmt::println("neg_int : {}", neg_int);
  fmt::println("double_var : {}", double_var);

  fmt::println("pos_int in different bases : ");
  fmt::println("pos_int (dec) : {}", pos_int); // Default
  fmt::println("pos_int (hex) : {:x}", pos_int);
  fmt::println("pos_int (hex) : {:X}", pos_int);
  fmt::println("pos_int (oct) : {:o}", pos_int);
  fmt::println("pos_int (binary) : {:b}", pos_int);
  fmt::println("pos_int (decimal) : {:d}", pos_int);

  fmt::println("neg_int in different bases : ");
  fmt::println("neg_int (dec) : {}", neg_int);
  fmt::println("neg_int (hex) : {:x}", neg_int);
  fmt::println("neg_int (oct) : {:o}", neg_int);
  fmt::println("neg_int (binary) : {:032b}",
               neg_int); // Prints the pos number representation prepended with
                         // a negative sign. Make sure this is what you want.
  fmt::println("neg_int (decimal) : {:d}", neg_int);

  // We'll see more about floating point format specifiers shortly.
  fmt::println("double_var in different formats: ");
  fmt::println("double_var (default): {}", double_var);
  fmt::println("double_var (fixed): {:f}", double_var);
  fmt::println("double_var (scientific): {:e}", double_var);
  fmt::println("double_var (general): {:g}", double_var);

  fmt::println("-----");

  // uppercase and nouppercase
  fmt::println("uppercase and nouppercase: ");
  pos_int = 717171;
  fmt::println("pos_int (nouppercase - default): ");
  fmt::println("pos_int (dec): {}", pos_int);
  fmt::println("pos_int (hex): {:x}", pos_int);
  fmt::println("pos_int (oct): {:o}", pos_int);

  // For integers, the # toogles the alternative format flag. This shows the
  // base prefix like 0b, and 0x.
  fmt::println("pos_int (uppercase): ");
  fmt::println("{:#X}", pos_int);
  fmt::println("{:#B}", pos_int);

  fmt::println("-----");

  // fixed and scientific : for floating point values
  // control the precision.
  fmt::println("fixed and scientific: for floating point values: ");
  double a{3.1415926535897932384626433832795};
  double b{2006.0};
  double c{1.34e-10};

  fmt::println("double values (default : use scientific where necessary) : ");
  fmt::println("a : {}", a);
  fmt::println("b : {}", b);
  fmt::println("c : {}", c);

  fmt::println("double values (precision) : ");
  fmt::println("a: {:.6}", a);
  fmt::println("b: {:.6}", b);
  fmt::println("c: {:.6}", c);

  fmt::println("double values (fixed) : ");
  fmt::println("a: {:.6f}", a);
  fmt::println("b: {:.6f}", b);
  fmt::println("c: {:.6f}", c);

  fmt::println("double values (scientific) : ");
  fmt::println("a: {:.6e}", a);
  fmt::println("b: {:.6e}", b);
  fmt::println("c: {:.6e}", c);

  fmt::println("-----");

  // argument indexes: Allow us to order arguments. This is good for example for
  // applications that use localization.
  fmt::println("argument indexes: ");
  fmt::println("It's {:.2f} degrees outside and it's {}", 34.5, "sunny");
  fmt::println("It's {1} today. And the temperature is {0:.2f} degrees outside",
               34.5, "sunny");
}