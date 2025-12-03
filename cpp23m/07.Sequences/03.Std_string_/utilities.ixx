module;

#include <string>
#include <fmt/format.h>

export module utilities; 


export void declare_and_initialize(){
    // Basic Declaration and Initialization
    // Declaring a std::string and initializing it with a literal
    std::string str1 = "Hello, World!";
    fmt::println("str1: {}", str1);
}


export void construction(){
    //Using Constructors
    // Creating a std::string using various constructors
    std::string str1 {"Hello world"};
    std::string str2(str1); // Copy constructor
    std::string str3(str1, 7, 5); // Substring constructor: start at index 7, length 5
    std::string str4(10, 'A'); // Fill constructor: 10 characters of 'A'
    fmt::println("str2: {}", str2);
    fmt::println("str3: {}", str3);
    fmt::println("str4: {}", str4);
}

export void access_and_modify(){
    //Accessing Characters
    // Accessing individual characters using the [] operator and at() method
    std::string str1 {"Hello world!"};
    fmt::println("First character of str1: {}", str1[0]);
    fmt::println("Second character of str1 using at(): {}", str1.at(1));

    //Modifying Strings
    // Modifying characters in the string
    str1[0] = 'h';
    str1.at(7) = 'w';
    fmt::println("Modified str1: {}", str1);

}

export void appending_and_concatenation(){
    //Appending and Concatenation
    //Appending to a string using operator+= and append()
    std::string str1 {"Hello world!"};
    std::string str2 {"Dog"};
    str1 += " How are you?";
    str2.append(" Goodbye!");
    fmt::println("Appended str1: {}", str1);
    fmt::println("Appended str2: {}", str2);

    // Concatenating strings using operator+
    std::string str3{"How are you."};
    std::string str5 = str3 + " Everyone!";
    fmt::println("Concatenated str5: {}", str5);
}


export void substrings_and_finding(){
    //Substrings
    // Extracting a substring using substr()
    std::string str1 {"Hello world"};
    std::string subStr = str1.substr(7, 5); // Start at index 7, length 5
    fmt::println("Substring of str1: {}", subStr);

    //Finding Substrings
    // Finding a substring within a string using find()
    size_t pos = str1.find("World");
    if (pos != std::string::npos) {
        fmt::println("'World' found at position: {}", pos);
    } else {
        fmt::println("'World' not found");
    }
}


export void comparison(){
    // Comparison
    // Comparing strings using compare()
    std::string str1 {"Hello"};
    std::string str2 {"World"};
    if (str1.compare(str2) == 0) {
        fmt::println("str1 is equal to str2");
    } else {
        fmt::println("str1 is not equal to str2");
    }

    if(str1.compare(str2) > 0){
        fmt::println("str1 is greater");
    }else{
        fmt::println("str2 is greater");
    }
}


export void inserting_and_erasing(){
    //Inserting and Erasing
    //Inserting a substring into a string
    std::string str1 {"Hello world"};
    str1.insert(5, ", Beautiful");
    fmt::println("After insertion: {}", str1);

    // Erasing a part of the string
    str1.erase(5, 11); // Erase 11 characters starting from index 5
    fmt::println("After erasing: {}", str1);
}


export void length_capacity_clear(){
    //Length and Capacity
    // Getting the length and capacity of a string
    std::string str1{"Hello world!"};
    fmt::println("Length of str1: {}", str1.length());
    fmt::println("Capacity of str1: {}", str1.capacity());

    //Iterating over a string
    //Using range-based for loop to iterate over a string
    fmt::print("Characters in str1: ");
    for (const auto& ch : str1) {
        fmt::print("{} ", ch);
    }
    fmt::print("\n");

    // Clearing a string
    // Clearing the contents of a string
    str1.clear();
    fmt::println("Cleared str1, new length: {}", str1.length());
}
