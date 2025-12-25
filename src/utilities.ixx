
module;

// #include <fmt/format.h>

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

import attributes;
import static_vars;
import recursion;

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

export void attributes_demo() {

    //[[noretun]]
    /*
    fmt::println("Exiting the program");
    attributes::exit_program();// This call may not return
    fmt::println("Program ends properly");
    */

    //[[deprecated]]
    /*
    attributes::old_function(); // This will generate a warning
    attributes::new_function(); // This will not generate a warning
    */

    //[[nodiscard]]
    /*
    //attributes::calculate_value(); // This will generate a warning
    int result = attributes::calculate_value(); // This will not generate a
    warning
    */

    //[[fallthrough]]
    /*
    attributes::handle_switch(1);
    */

    //[[likely]] and [[unlikely]]
    /*
    auto value1 = attributes::process_value(42);
    auto value2 = attributes::process_value(43);
    fmt::println("Value1: {}, Value2: {}", value1, value2);
    */

    //[[assume]]
    /*
    attributes::process_data(5);
    */

    //[[nodiscard]] with message
    // attributes::compute_important_value();
}

export void static_vars_demo() {
    static_vars::user_login();
    static_vars::user_login();
    static_vars::user_login();
}

export void recursion_demo() {
    auto value = recursion::fibonacci(7);
    fmt::println("value: {}", value);

    // Memoization
    auto result = recursion::fibonacci_memo(10);
    fmt::println("Fibonacci of 10 is: {}", result);

    // Iterative
    result = recursion::fibonacci_iterative(10);
    fmt::println("Fibonacci of 10 is: {}", result);

    // Trying to set up a lambda computing fibonacci:
    /*
    auto fibonacci_lambda = [](int n){
        if( n < 2) return n;
        return fibonacci_lambda( n -1 ) + fibonacci_lambda( n - 2); // Compiler
    error: Can't mention the lambda name
    };
    */

    // This works
    auto fibonacci_lambda = [](this auto& self, int n) {
        if (n < 2)
            return n;
        return self(n - 1) + self(n - 2);
    };

    value = fibonacci_lambda(10);
    fmt::println("Fibonacci (lambda) of 10 is: {}", value);
}
