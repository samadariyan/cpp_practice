/*
    . exploring the basics of pointers
*/
module;

#include <fmt/format.h>
#include <iostream>

export module pointers_1;

namespace pointers_1{
    export void pointer_declaration_initialization(){

        //1.Declaring and using pointers
        int *p_number{};// Will initialize with nullptr
        double *p_fractional_number{};

        // Explicitly initialize with nullptr
        int *p_number1{ nullptr };
        int *p_fractional_number1{ nullptr };

        // Pointers to different variables are  of the same size
        fmt::println("sizeof(int): {}", sizeof(int));// 4
        fmt::println("sizeof(double): {}", sizeof(double));// 8
        fmt::println("sizeof(double*): {}", sizeof(double *));
        fmt::println("sizeof(int*): {}", sizeof(int *));
        fmt::println("sizeof(p_number1): {}", sizeof(p_number1));
        fmt::println("sizeof(p_fractional_number1): {}", sizeof(p_fractional_number1));

    }


    export void assignment_and_access(){

        // Initializing pointers and assigning them data
        // We know that pointers store addresses of variables
        int int_var{ 43 };
        int *p_int{ &int_var };// The address of operator (&);

        fmt::println("int var: {}", int_var);
        fmt::println("address of int_var: {}", fmt::ptr(p_int));


        // You can also change the address stored in a pointer any time
        int int_var1{ 65 };
        p_int = &int_var1;// Assign a different address to the pointer
        fmt::println("p_int (with different address): {}", fmt::ptr(p_int));

        // Can't cross assign between pointers of different types
        int *p_int1{ nullptr };
        double double_var{ 33 };
        //p_int = &double_var; // Compiler error
        
        // Dereferencing a pointer : {}
        int *p_int2{ nullptr };
        int int_data{ 56 };
        p_int2 = &int_data;
        fmt::println("value: {}", *p_int2);// Dereferencing a pointer

    }

    export void pointer_to_char(){

        //Pointers to char
        const char *message{ "Hello World!" };
        fmt::println("message: {}", message);	//This works
        fmt::println("message: {}", *message);	//This also works
        std::cout << message << "\n";

        //Can't modify a through a pointer to a string literal
        //*message = "B"; // Compiler error
        //fmt::println("*message: {}", *message);

        //Printing the address of the first character
        fmt::println("message address: {}", fmt::ptr(message));

        // Allow users to modify the string
        char message1[]{ "Hello World!" };
        //message1[0] = 'B';
        *message1 = 'B';
        fmt::println("message1: {}", message1);

    }

}   //namespace pointers_1
