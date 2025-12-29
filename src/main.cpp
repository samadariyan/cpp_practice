
#include <array>
#include <cstddef>
#include <fmt/format.h>

import utilities;
// import compare;
// import math;
// import parameters;

/*
    . Passing parameters to functions:
        . By value:
            . The function receives a copy of the value passed to it.
            . The original value is not modified.

        . By reference:
            . The function receives a reference to the value passed to it.
            . The original value is modified.

        . By Pointer:
            . The function receives a pointer to the value passed to it.
            . The original value is modified.

        . Default parameters:
            . Parameters that have default values.
            . They only have to show up in the declaration.


// Pass by value

void say_age(int age) {
    ++age;
    fmt::println("Hello! You are {} years old! &age: {}", age, fmt::ptr(&age));
}

// Pass by const value
// Can't have this const age function together with the one on top because they
// achieve the same thing in the eyes of the compiler. The warning or error you
// get may be different.

void say_age(const int age) {
    //++age;  //Can't assign to a variable that is const
    fmt::println("Hello, you are {} years old! &age: ", age, fmt::ptr(&age));
}


// Pass by pointer

void say_age(int* age) { // Parameter
    ++(*age);
    fmt::println("Hello ,you are {} years old! &age: {}\n", *age,
                 fmt::ptr(&age)); // 24
}

// Pass by pointer to const

int dog_count{10}; // Global

void say_age(const int* age) // The value pointed to is constant
{
    //++(*age); //One way to do this

    // Another way to do this
    // int value = *age;
    //++value;
    /// *age = value;
    fmt::println("Hello , you are {}  years old! &age :{} \n", *age,
                 fmt::ptr(&age)); //

    // But we can make the pointer point somewhere else
    age = &dog_count; // This compiles
}

// Pass by const pointer to const

int dog_count{10}; // Global
void say_age(const int* const age) {
    //++(*age); // The value pointed to is const.
    fmt::println("Hello , you are {} years old! &age : {}\n", *age,
                 fmt::ptr(&age)); // 24
    // age = &dog_count;
    //  The pointer itself is const, you can't make it point somewhere else.
}


// Pass by reference

void say_age(int& age) {
    ++age;
    fmt::println("Hello, you are {} years old! &age: {}\n", age,
                 fmt::ptr(&age)); // 24
}


// Pass by const reference

void say_age(const int& age) {
    //++age; // Comiler error
    fmt::println("Hello, you are {} years old! &age: {}\n", age,
                 fmt::ptr(&age)); // 24
}


// Default parameters: They only have to show up in the declaration.
void compute(int age = 27, double weight = 72.4, double distance = 12.5) {
    fmt::println(
        "Doing computations on age : {} weight :{} and distance :{}  \n", age,
        weight, distance);
}

void greet_teacher(std::string_view name_sv = "teacher", int homeworks = 12,
                   int exams = 4, double pass_rate = 0.5,
                   std::string_view first_dpmt = "Computer Sce") {
    fmt::println("Good morning {} !\n", name_sv);
    fmt::println("In the past semester, we had {} homeworks, and {} exams. The "
                 "pass rate was around {} \n",
                 homeworks, exams, pass_rate);
    fmt::println("The best performing department is {} \n", first_dpmt);
}

*/

/*

int main() {
    // pointer_basics();
    // dynamic_memory_allocation_demo();
    // smart_pointers_demo();
    // references();
    // challenge();

    // handling_characters_demo();
    // handling_c_strings_demo();
    // handling_std_strings_demo();
    // string_views_demo();
    // string_literals_demo();
    // ftxui_demo();
    // plindrom();
    // char_challange();

    // Call the function

    // using namespace it_2;

    // int x{10};
    // int y{20};
    // auto result = add(7, 3);
    // result = add(11, 20);
    // fmt::println("Result: {}", result);

    // result = maximum(x, y);
    // fmt::println("Result max: {}", result);

    // result = minimum(x, y);
    // fmt::println("Result min: {}", result);

    // result = inc_mult(x, y);
    // fmt::println("Result inc_mult: {}", result);

    // Other functions
    // print_number(10);
    // say_hello();

    // int age{23};

    // fmt::println("------------------------------------------\n");
    // fmt::println("age (before call), {} &age {}\n", age,
    //              fmt::ptr(&age)); // 23
    // say_age(age);

    // fmt::println("age (after call), {} &age {}\n", age,
    //              fmt::ptr(&age)); // 24

    // Default Parameters
    // compute();

    // Call and use default arguments
    // greet_teacher();
    // greet_teacher("Mr Bean");
    // greet_teacher("Mr Hamston", 7);
    // greet_teacher("Mr Walker", 7, 3);
    // greet_teacher("Mr Paku", 7, 3, 0.7);
    // greet_teacher("Mr Kojo", 7, 3, 0.7, "Applied Mathematics");
}

*/

/*
    . Sequences and arrays as function parameter
        . Passing arrays as function parameters
        . Passing (seemingly) sized arrays as function parameters: The size is
   ignored by the compiler . Passing arrays by reference: Enforce the size .
   Passing std::vector or std::array as function parameters
*/

/*

// Passing array function parameters

// double sum(double scores[], size_t count)
double sum(double* scores, size_t count) {

    double score_sum{};
    fmt::println("sizeof(scores)  : {}", sizeof(scores));
    // Inside the function the array decays to a pointer
    fmt::println("sizeof(int*) : {}", sizeof(int*));
    // auto arr_size = std::size(scores);
    // std::size doesn't work here because the array has decayed to a pointer

    for (size_t i{0}; i < count; ++i) {
        score_sum += scores[i];
    }
    return score_sum;
}

// Passing (seemingly) sized array function parameters
// The 5 size is not enforced. It's just ignored by the compiler.

double sum(double scores[5], size_t count) {
    double sum{};

    for (size_t i{}; i < count; ++i) {
        sum += scores[i];
    }
    return sum;
}

// Enforce the size. Pass the sized array by reference
// This is just a piece of syntax you have to remember.
// If the size is different from the one specified, the compiler will throw an
// error.
double sum(const double (&scores)[10]) {
    double sum{};
    for (size_t i{}; i < std::size(scores); ++i) {
        sum += scores[i];
    }
    return sum;
}


// Passing multi-dimensional arrays as function parameters (2d and 3d)
double sum(const double array[][3], size_t size) {
    double sum{};
    for (size_t i{}; i < size; ++i) // Loop through rows
    {
        for (size_t j{}; j < 3; ++j) // Loop through elements in a row
        {
            sum += array[i][j]; // Array access notation
            // sum += *( *(array + i) +j);	// Pointer arithmetic notation.
            // Confusing . Prefer array noation
        }
    }
    return sum;
}

double sum_3d(const double array[][3][2], size_t size) {

    double sum{};
    for (size_t i{}; i < size; ++i) // Loop through rows
    {
        for (size_t j{}; j < 3; ++j) // Loop through elements in a row
        {
            for (size_t k{}; k < 2; ++k) {
                sum += array[i][j][k];
                // sum += *(*(*(array + i) + j)+k);
            }
        }
    }
    return sum;
}


// Passing std::array as a function parameter
double sum(const std::array<double, 10>& scores) {
    double sum{};
    for (size_t i{}; i < scores.size(); ++i) {
        sum += scores[i];
    }
    return sum;
}

*/

// attributes_demo();
// static_vars_demo();
// recursion_demo();

// int main() {

/*

// Passing array function parameters

double my_scores[]{10.5, 34.3, 4.8, 6.5};
fmt::println("sizeof(my_scores) : {}", sizeof(my_scores));

double result = sum(my_scores, std::size(my_scores));
fmt::println("result : {}", result);


// Passing (seemingly) sized array function parameters

double student_scores[]{10.0, 20.0, 30.0, 40.0, 50.0, 60.0};
// Less than 5 parameters

double result = sum(student_scores, std::size(student_scores));
fmt::println("result : {}", result);


// Enforce the size. Pass the sized array by reference

double student_scores[]{
    10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0,
};

double sum_result = sum(student_scores);

fmt::println("result is : {}", sum_result);


// Passing multi-dimensional arrays as function parameters (2d and 3d)
double weights[][3]{{10.0, 20.0, 30.0},
                    {40.0, 50.0, 60.0},
                    {70.0, 80.0, 90.0},
                    {100.0, 110.0, 120.0}};

double result = sum(weights, std::size(weights));
fmt::println("2d array sum: {}", result);


double weights_3d[][3][2]{{
                              {10, 20},
                              {30, 40},
                              {50, 60},
                          },
                          {
                              {70, 80},
                              {90, 100},
                              {110, 120},
                          }};

double result = sum_3d(weights_3d, std::size(weights_3d));
fmt::println("3d array sum: {}", result);


// Passing std::array as a function parameter
std::array<double, 10> student_scores{10.0, 20.0, 30.0};
double sum_result = sum(student_scores);
fmt::println("result is : {}", sum_result);


// For the evaluation to take place at compile time, we have
// to remember to store the return value in a constexpr result variable.
int run_time_mulitplier{10}; // Run time

int result = get_value(4);
// int result = get_value(run_time_mulitplier);
fmt::println("value: {}", result);



int main(int argc, char* argv[]) {
    // process_arguments(argc, argv);
    calculator(argc, argv);
}

*/

/*
int main() {

    overloading_1_demo();
    overloading_2_demo();
    overloading_3_demo();
    overloading_4_demo();
}

*/

int main() {
    // declare_and_use_lambda_func();
    // capture_lists();
    // capture_by_value_modification();
    // capture_by_reference_modification();
    // capture_all_by_value();
    capture_all_by_reference();
}