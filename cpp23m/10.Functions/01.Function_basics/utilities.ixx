module;

#include <fmt/format.h>

export module utilities;

//Function that takes one input and doesn't return anything

export void print_number(auto number){
    fmt::println("number: {}", number);
}


// Function that doesnt' take parameters and returns nothing
export void say_hello()
{
  fmt::println("Hello there");
  return;// You could omit this return statement for functions returning void
}