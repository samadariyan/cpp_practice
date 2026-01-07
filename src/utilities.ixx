
module;

// #include <Font.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fmt/format.h>
#include <ftxui/component/component.hpp> // for Input, Renderer, ScreenInteractive
#include <ftxui/component/screen_interactive.hpp> // for ScreenInteractive
#include <ftxui/dom/elements.hpp>  // for text, Element, hbox, vbox, border
#include <ftxui/screen/screen.hpp> // for Screen
#include <string>
#include <vector>

#include <iostream>

export module utilities;

// import pointers_1;
// import pointers_2;
// import pointers_3;
// import pointers_4;

// import dynamic_memory_allocation;
// import unique_pointers;
// import shared_pointers;
// import references;
// import pointer_challenge;

// import handling_characters;
// import handling_c_strings;
// import handling_std_strings;
// import string_views;
// import string_literals;
// import challenge1;
// import challenge2;
// import charachter_challenges;

// import parameters;

// import overloading_1;
// import overloading_2;
// import overloading_4;

// import attributes;
// import static_vars;
// import recursion;

/*
export void pointer_basics() {

    Pointer basics pointers_1::pointer_declaration_initialization();
    pointers_1::assignment_and_access();
    pointers_1::pointer_to_char();

    Pointers and const pointers_2::raw_modifiable_variables();
    pointers_2::non_const_pointer_to_non_const_data();
    pointers_2::pointer_to_const();
    pointers_2::where_const_applies();
    pointers_2::const_data_const_pointer();
    pointers_2::non_const_data_const_pointer();

    Relationship between arrays and pointers
    pointers_3::pointers_arrays_relationship();
    pointers_3::swapping_addresses();

    Pointer arithmetics pointers_4::pointer_arithmetic_navigation();
    pointers_4::pointer_arithmetic_distance();
    pointers_4::pointer_arithmetic_compare_pointers();
}

export void dynamic_memory_allocation_demo() {
    dynamic_memory_allocation::pointer_review();
    dynamic_memory_allocation::pointers_gone_bad();
    dynamic_memory_allocation::dynamic_heap_memory();
    dynamic_memory_allocation::dangling_pointers();
    dynamic_memory_allocation::when_new_fails();
    dynamic_memory_allocation::null_ptr_safety();
    dynamic_memory_allocation::memory_leaks();
    dynamic_memory_allocation::dynamic_arrays();
    dynamic_memory_allocation::static_vs_dynamic_arrays();
}

export void smart_pointers_demo() {
    unique_pointers::tinker_with_unique_pointers();
    shared_pointers::tinker_with_shared_pointers();
}

export void references() {
    declaring_and_using_references();
    comparing_pointers_and_references();
    references_and_const();
    ref_with_range_based_for_loop();
}

export void challenge() {
    This is the best way to go dm_1::app();

    This is the worst way to go dm_2::app();

    This is the second worst way dm_3::app();
}

export void handling_characters_demo() {
    // handling_characters::is_al_num();
    // handling_characters::is_alphabetic();
    // handling_characters::is_blank();
    // handling_characters::is_upercase();
    // handling_characters::is_digit();
    // handling_characters::change_to_lowercase();
}

export void handling_c_strings_demo() {
    handling_c_strings::cstring_strlen();
    handling_c_strings::cstring_strcmp();
    handling_c_strings::cstring_strncmp();
}

export void handling_std_strings_demo() {
    handling_std_strings::std_string_declaration();
    // handling_std_strings::std_string_concatenation();
}

export void string_views_demo() {
    // string_views::the_problem();
    // string_views::the_solution();
    // string_views::string_view_construction();
    // string_views::std_string_view_visualizes_original_string();
    // string_views::std_string_view_change_view_window();
    // string_views::std_string_view_lifetime();
    // string_views::std_string_view_data();
    string_views::std_string_view_behaviors();
}


export void string_literals_demo() {
    // string_literals::escape_sequences();
    string_literals::raw_string_literals();
}


export void ftxui_demo() {
    // The basics
    // ftxui_it1::app();

    // Interactiviey
    ftxui_it2::app();
}



export void plindrom() {
    // Start Input
    ftxui_palindrome_app::app();
}


export void char_challange() {

// challenge_1::app();
// challenge_2::app();
challenge_3::app();
// challenge_4::app();
}

// Function that takes one input and doesn't return anything
export void print_number(auto number) {
    fmt::println("number: {}", number); //
}

// Function that doesnt' take parameters and returns nothing
export void say_hello() {
    fmt::println("Hello there");
    return; // You could omit this return statement for functions returning void
}

*/

// Marking a function as constexpr gives it the potential
// to be evaluated at compile time
// export constexpr int get_value(int multiplier) { return 3 * multiplier; }

// Evaluate this function at compile time. If you can't
// do that throw a compiler error
// export consteval int get_value(int multiplier) { return 3 * multiplier; }

/*
export void process_arguments(int argc, char* argv[]) {
    fmt::println("number of arguments: {}", argc);
}


export void calculator(int argc, char* argv[]) {

// check nomber of args
if (argc != 4) {
    fmt::println("Program can only called with 3 arguments like:");
    fmt::println("MyRocket a + b");
    fmt::print("You called with : MyRocket");
    for (int i{1}; i < argc; ++i) {
        fmt::print(" {}", argv[i]);
    }
    fmt::print("\n");
    return;
}
// grab operands
double first_number{atof(argv[1])};
double second_number{atof(argv[3])};

if ((first_number == 0.0) || (second_number == 0.0)) {
    fmt::println("Please use valid numbers ( different from zero) for "
    "first and second parameters) ");
    return;
}

// grab the operation
const char* operation{argv[2]};
char c;

if ((std::strlen(operation) == 1) &&
((*operation == '+') || (*operation == '-') || (*operation == 'x') ||
(operation[0] == '/'))) {
    c = *operation;
} else {
    fmt::println("{} is not a valid operation.", *operation);
return;
}

// Do the operation
switch (c) {
    case '+':
    fmt::println("{} + {} = {}", first_number, second_number,
    first_number + second_number);
    break;

    case '-':
    fmt::println("{} - {} = {}", first_number, second_number,
    first_number - second_number);
    break;

    case 'x':
    fmt::println("{} x {} = {}", first_number, second_number,
    first_number * second_number);

    break;
    case '/':
    fmt::println("{} / {} = {}", first_number, second_number,
    first_number / second_number);
    break;
}
}
*/

/*
export void overloading_1_demo() {
    using namespace overloading_1;
    print(10);
    print(10, 20);
    print(3.14);
    print("Hello World!");
}

export void overloading_2_demo() {
    using namespace overloading_2;
    int array[] = {1, 2, 3, 4, 5};
    process(array, 5); // Calls the array version
    process(42);       // Calls the single value version
}

*/

/*
    . Overloading std::getline
    . std::getline is overloaded in the C++ standard library to allow reading a
   whole line or reading up to a specific delimiter. . These are examples I
   picked up for this lecture, but the exhaustive list of overloads should be
   checked in the standard library documentation.
*/

/*
export void overloading_3_demo() {
    std::string line;

    // Read a whole line from standard input
    fmt::print("Enter a line: ");
    std::getline(std::cin, line);
    fmt::println("You entered: {}", line);

    // Read up to a specific delimiter (comma)
    fmt::print("Enter values separated by commas: ");
    std::getline(std::cin, line, ',');
    fmt::println("First value: {}", line);
}

export void overloading_4_demo() {
    using namespace overloading_4;
    fmt::print("Rolling a 6-sided die: {}\n", roll());
    fmt::print("Rolling a 20-sided die: {}\n", roll(20));
    fmt::print("Rolling 3 6-sided dice: {}\n", roll(6, 3));

    fmt::print("Area of a square with side 2.0: {}\n", area(2.0));
    fmt::print("Area of a rectangle with length 2.0 and width 3.0: {}\n",
               area(2.0, 3.0));
    fmt::print("Area of a circle with radius 1.0: {}\n", area(1.0, true));

    respond();
    respond("What is the meaning of life?");
    respond("What is the meaning of life?", true);
}

*/

/*
// Declaring and using lambdas
export void declare_and_use_lambda_func() {
    Lambda function signature :
                                [capture list] (parameters) ->return type{
                                // Function body
                                }
    */

/*
// Declaring a lambda function and calling it through a name
auto func = []() { fmt::println("Hello World!"); };

// Call the lambda
func();
func();

// Declare a lambda function and call it directly
[]() { fmt::println("Hello World!"); }();

// Lambda function that takes parameters
[](double a, double b) { fmt::println("a + b: {}", (a + b)); }(10.0, 22.0);

auto func1 = [](double a, double b) { fmt::println("a + b: {}", (a + b)); };

func1(10, 20);
func1(5, 7);


// Lambda function that returns something
auto result = [](double a, double b) { return a + b; }(10, 60);
fmt::println("Result: {}", result);

fmt::println("Result: {} ",
             [](double a, double b) { return a + b; }(10, 60));

*/

/*
// Store the lambda name in a variable
auto func1 = [](double a, double b) { return a + b; };

auto result1 = func1(23, 7);
auto result2 = func1(9, 45);

fmt::println("Result1: {} ", result1);
fmt::println("Result2: {} ", result2);
fmt::println("direct call: {} ", func1(5, 2));

// Explicitly specify the return type
auto func3 = [](double a, double b) -> int { return a + b; };

auto func4 = [](double a, double b) { return a + b; };

auto result3 = func3(10.1, 20.2);
auto result4 = func4(10.1, 20.2);

fmt::println("result3 : {}", result3);
fmt::println("result4 : {}", result4);
fmt::println("sizeof(result3) : {}", sizeof(result3)); // 4
fmt::println("sizeof(result4) : {}", sizeof(result4)); // 8

}

export void capture_lists() {
    // Capture lists
    double a{10};
    double b{20};

    auto func = [a, b]() {
        fmt::println("a + b = {} + {} = {}", a, b, (a + b));
    };
    func();
}

export void capture_by_value_modification() {
    int x{10};

    // Lambda capturing 'x' by value
    auto lambda = [x]() mutable {
        x += 5;
        fmt::println("Inside lambda (modified copy): {}", x);
    };

    // print x befor, in lamda and after
    fmt::println("Original value before lambda: {}", x);
    lambda();
    fmt::println("Original value after lambda: {}", x); // Unchanged
}


export void capture_by_reference_modification() {
    int x{10};

    // Lambda capturing 'x' by reference
    auto lambda = [&x]() {
        x += 5;
        // Modifies the original variable

        fmt::println("Inside lambda (modified original): {}", x);
    };

    fmt::println("Original value before lambda: {}", x);
    lambda();
    fmt::println("Original value after lambda: {}", x);
    // Changed
}

export void capture_all_by_value() {
    int x{10};
    int y{20};

    // Lambda capturing all by value
    auto lambda = [=]() mutable {
        // Modify the captured values inside the lambda
        x += 5;
        y += 5;

        fmt::println("Inside lambda (x copy modified): {}", x);
        fmt::println("Inside lambda (y copy modified): {}", y);
    };

    fmt::println("Original values before lambda: x = {}, y = {}", x, y);
    lambda();
    fmt::println("Original values after lambda: x = {}, y = {}", x, y);
    // Unchanged
}

export void capture_all_by_reference() {
    int x = 10;
    int y = 20;

    // Lambda capturing all by reference
    auto lambda = [&]() {
        // Directly modify the original variables
        x += 5;
        y += 10;

        fmt::println("Inside lambda (x modified): {}", x);
        fmt::println("Inside lambda (y modified): {}", y);
    };

    fmt::println("Original values before lambda: x = {}, y = {}", x, y);
    lambda();
    fmt::println("Original values after lambda: x = {}, y = {}", x, y);
    // Changed
}

*/

/*

export void attributes_demo() {

    //[[noretun]]
    fmt::println("Exiting the program");
    attributes::exit_program(); // This call may not return
    fmt::println("Program ends properly");


    //[[deprecated]]
    attributes::old_function(); // This will generate a warning
    attributes::new_function(); // This will not generate a warning


    //[[nodiscard]]
    attributes::calculate_value(); // This will generate a warning

    int result =
        attributes::calculate_value(); // This will not generate a warning


    //[[fallthrough]]
    attributes::handle_switch(1);


    //[[likely]] and [[unlikely]]
    auto value1 = attributes::process_value(42);
    auto value2 = attributes::process_value(43);
    fmt::println("Value1: {}, Value2: {}", value1, value2);


    //[[assume]]
    attributes::process_data(5);


    //[[nodiscard]] with message
    attributes::compute_important_value();

}

*/

/*

export void static_vars_demo() {
    static_vars::user_login();
    static_vars::user_login();
    static_vars::user_login();
}

*/

/*

export void recursion_demo() {
    auto value = recursion::fibonacci(7);
    fmt::println("value: {}", value);

    // Memoization
    auto result = recursion::fibonacci_memo(10);
    fmt::println("Fibonacci of 10 is: {}", result);

    // Iterative
    result = recursion::fibonacci_iterative(10);
    fmt::println("Fibonacci of 10 is: {}", result);

    ////
    // Trying to set up a lambda computing fibonacci:
    auto fibonacci_lambda = [](int n) {
        if (n < 2)
            return n;
        return fibonacci_lambda(n - 1) + fibonacci_lambda(n - 2);
        // Compiler error: Can't mention the lambda name
    };
    ////


// This works
auto fibonacci_lambda = [](this auto& self, int n) {
    if (n < 2)
        return n;
    return self(n - 1) + self(n - 2);
};

value = fibonacci_lambda(10);
fmt::println("Fibonacci (lambda) of 10 is: {}", value);
}

*/

/*


namespace it_1 {

export void app() {

    // Initialization
    sf::RenderWindow window(sf::VideoMode({200, 200}), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        // Event processing

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Rendering
        window.clear();
        window.draw(shape);
        window.display();
    }
}

} // namespace it_1

namespace it_2 {
// Initialization
void init(sf::RenderWindow& window, sf::CircleShape& circle) {

    // Configure the window
    window.create(sf::VideoMode({800, 600}), "Sfml at work!");

    // Configure the circle
    circle.setRadius(100.f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition({300.f, 200.f});
}

// Event processing
void process_events(sf::RenderWindow& window) {

    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

// Rendering
void render(sf::RenderWindow& window, const sf::CircleShape& shape) {
    window.clear(sf::Color::Black); // Black background
    window.draw(shape);
    window.display();
}

// App
export void app() {
    sf::RenderWindow window;
    sf::CircleShape shape;

    // Initialize the window and  circle
    init(window, shape);

    // Event loop
    while (window.isOpen()) {
        process_events(window);
        render(window, shape);
    }
}

} // namespace it_2


*/

/*
    Ftxui based calculator

    namespace it_1 {
using namespace ftxui;

// Functions to do the operations
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return b != 0 ? a / b : 0; }

export void app() {

    // UI state variables
    double num1 = 0;
    double num2 = 0;
    double result = 0;
    bool is_calculated = false;

    // Input boxes for numbers
    std::string num1_str = "0";
    std::string num2_str = "0";
    auto input1 = Input(&num1_str, "Enter first number");
    auto input2 = Input(&num2_str, "Enter second number");

    // Operation selector menu
    std::vector<std::string> operations = {"Add", "Subtract", "Multiply",
                                           "Divide"};
    int operation_index{0};
    auto operation_menu = Menu(&operations, &operation_index);

    // Calculate button
    auto button = Button("Calculate", [&] {
        num1 = std::stod(num1_str);
        num2 = std::stod(num2_str);

        // Perform the selected operation using function overloading
        switch (operation_index) {
        case 0:
            result = add(num1, num2);
            break;
        case 1:
            result = subtract(num1, num2);
            break;
        case 2:
            result = multiply(num1, num2);
            break;
        case 3:
            result = divide(num1, num2);
            break;
        }

        is_calculated = true;
    });

    // Renderer for the UI components
    auto container =
        Container::Vertical({input1, input2, operation_menu, button});

    auto renderer = Renderer(container, [&]() {
        return vbox({text("Basic Calculator") | bold | center, separator(),
                     hbox(text("First Number: "), input1->Render()) | center,
                     hbox(text("Second Number: "), input2->Render()) | center,
                     hbox(text("Operation: "), operation_menu->Render()) |
                         center,
                     button->Render() | center, separator(),
                     is_calculated ? text("Result: " + std::to_string(result)) |
                                         bold | center
                                   : text("")}) |
               border;
    });

    // Launch the UI
    auto screen = ScreenInteractive::TerminalOutput();
    screen.Loop(renderer);
}

} // namespace it_1
*/

/*
    . Sfml show the distance between points.
    . Distance shown as text.
*/

namespace it_2 {
// Function to calculate the Euclidean distance between two points
double calculate_distance(const double origin[2],
                          const double mouse_position[2]) {
    double dx = mouse_position[0] - origin[0];
    double dy = mouse_position[1] - origin[1];
    return std::sqrt(dx * dx + dy * dy);
}

void init(sf::RenderWindow& window, sf::Font& font, sf::Text& origin_text,
          sf::Text& mouse_text, sf::Text& distance_text,
          const double origin[2]) {

    window.create(sf::VideoMode({800, 600}),
                  "Distance from Origin to Mouse Position");

    if (!font.openFromFile("arial.ttf")) {
        std::cerr << "Error loading font. Make sure the font file is in the "
                     "same directory as the binary.\n";
        return;
    }

    origin_text.setFont(font);
    origin_text.setCharacterSize(24);
    origin_text.setFillColor(sf::Color::White);
    origin_text.setPosition({50, 50});

    mouse_text.setFont(font);
    mouse_text.setCharacterSize(24);
    mouse_text.setFillColor(sf::Color::White);
    mouse_text.setPosition({50, 100});

    distance_text.setFont(font);
    distance_text.setCharacterSize(24);
    distance_text.setFillColor(sf::Color::White);
    distance_text.setPosition({50, 150});
}

void process_events(sf::RenderWindow& window) {

    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

void render(sf::RenderWindow& window, sf::Text& origin_text,
            sf::Text& mouse_text, sf::Text& distance_text) {
    window.clear(sf::Color::Black);
    window.draw(origin_text);
    window.draw(mouse_text);
    window.draw(distance_text);
    window.display();
}

export void app() {
    double origin[2] = {0.0, 0.0};
    double mouse_position[2] = {0.0, 0.0};
    double distance = 0.0;

    sf::RenderWindow window;
    sf::Font font;
    sf::Text origin_text(font), mouse_text(font), distance_text(font);

    init(window, font, origin_text, mouse_text, distance_text, origin);

    // Set up the event loop
    while (window.isOpen()) {
        process_events(window);

        // Additional processing

        // Get the mouse position
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        mouse_position[0] = static_cast<double>(mouse_pos.x);
        mouse_position[1] = static_cast<double>(mouse_pos.y);

        // Calculate distance from origin to mouse position
        distance = calculate_distance(origin, mouse_position);

        // Update the displayed text
        origin_text.setString("Origin Point: (" + std::to_string(origin[0]) +
                              ", " + std::to_string(origin[1]) + ")");
        mouse_text.setString("Mouse Position: (" +
                             std::to_string(mouse_position[0]) + ", " +
                             std::to_string(mouse_position[1]) + ")");
        distance_text.setString("Distance from Origin: " +
                                std::to_string(distance));

        // render
        render(window, origin_text, mouse_text, distance_text);
    }
}

} // namespace it_2

/*

namespace it_3 {

void init(sf::RenderWindow& window, sf::Font& font, sf::Text& distance_text) {

    window.create(sf::VideoMode({800, 600}),
                  "Distance from Origin to Mouse Position");

    if (!font.openFromFile("arial.ttf")) {
        std::cerr << "Error loading font. Make sure the font file is in the "
                     "'fonts' directory."
                  << std::endl;
    }

    distance_text.setFont(font);
    distance_text.setCharacterSize(24);
    distance_text.setFillColor(sf::Color::White);
    distance_text.setPosition({50, 550});
}

void process_events(sf::RenderWindow& window, bool& running) {

    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            running = false;
        }
    }
}

void render(sf::RenderWindow& window, const double origin[2],
            const double mouse_position[2], double distance,
            sf::Text& distance_text) {
    window.clear(sf::Color::Black);

    sf::CircleShape origin_point(5);
    origin_point.setFillColor(sf::Color::Red);
    origin_point.setPosition({(float)origin[0] - origin_point.getRadius(),
                              (float)origin[1] - origin_point.getRadius()});

    sf::CircleShape mouse_point(5);
    mouse_point.setFillColor(sf::Color::Green);
    mouse_point.setPosition(
        {(float)mouse_position[0] - mouse_point.getRadius(),
         (float)mouse_position[1] - mouse_point.getRadius()});

    distance_text.setString(std::to_string(distance));

    window.draw(origin_point);
    window.draw(mouse_point);
    window.draw(distance_text);
    window.display();
}

export void app(int argc, char* argv[]) {

    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <origin_x> <origin_y>"
                  << std::endl;
        return;
    }

    double origin[2];
    origin[0] = std::stod(argv[1]);
    origin[1] = std::stod(argv[2]);

    sf::RenderWindow window;
    sf::Font font;
    sf::Text distance_text(font);

    init(window, font, distance_text);

    double mouse_position[2] = {0.0, 0.0};
    double distance = 0.0;

    bool running{true};

    // Event loop
    while (running) {
        process_events(window, running);

        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        mouse_position[0] = static_cast<double>(mouse_pos.x);
        mouse_position[1] = static_cast<double>(mouse_pos.y);

        distance = it_2::calculate_distance(origin, mouse_position);

        render(window, origin, mouse_position, distance, distance_text);
    }
}

} // namespace it_3
*/
