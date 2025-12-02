module;

// #include <format> //form std::format
// #include <print>  // for std::print and std::println

#include <iostream> // for std::cout

export module utilities;

export void standard_format_facilities() {
  // This may not work on your compiler but it works on latest visual c++
  // C++ 23 adds std::print and std::println, but they only work well on Visual
  // C++. We'll stick to fmt going forward.

  auto value = std::format("Hello {}", " World!");
  std::cout << value << "\n";

  std::print("Hello, {}", "world\n");
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

  // Using the external format library

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
  std::println("neg_int (binary) : {:032b}",
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
