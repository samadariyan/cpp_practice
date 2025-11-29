module;

#include <fmt/format.h> //Global module fragment

export module utilities; // Module definition

//Module purview
export int add_number(int first_parameter, int second_parameter){
    return first_parameter + second_parameter;
}

export void do_work(){
    fmt::print("Hello");
    fmt::print("World");
    fmt::print("\n"); //This prints a new line character

    int num1 {5};
    int num2 {6};
    //int result = num1 + num2;
    int result = add_number(num1,num2);
    fmt::println("Result: {}", result);
    fmt::println("Doing something inside do_work");
}
