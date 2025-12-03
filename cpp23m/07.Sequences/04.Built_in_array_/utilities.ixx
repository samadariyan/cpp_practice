module;

#include <string>
#include <fmt/format.h>

export module utilities; 


export void declaration_and_initialization(){
    //Declare and initialize an array
    //constexpr size_t array_size {5};

    //Declare the array
    //int scores [array_size]; // Junk data because the array is not initialized.

    // Read data
    /*
    fmt::println( "scores [0]: {}", scores[0] );
    fmt::println( "scores [1]: {}", scores[1] );

    // Read with a loop
    for( size_t i {0} ; i < array_size ; ++i){
        fmt::println("scores [{}]: {}", i, scores[i] );
    }

    //Writing data back into the array
    scores[0] = 20;
    scores[1] = 21;
    scores[2] = 22;

    //Print the data out
    fmt::println("Printing after changing the data: ");
    for( size_t i {0} ; i < array_size ; ++i){
        fmt::println("scores [{}] : {}", i, scores[i] );
    }
    */


    // Write data in a loop
    /*
    fmt::println("Changing the data in a loop");
    for(size_t i{0}; i < array_size ; ++i){
        scores[i] = i * 10;
    }

    //Print the data out
    for( size_t i {0} ; i < array_size ; ++i){
        fmt::println("scores [{}] : {}", i, scores[i] );
    }
    */


    // Declare and initialize at the same time
    /*
    double salaries[5] {12.7, 7.5, 13.2, 8.1, 9.3};
    for(size_t i{0}; i < 5; ++i){
        fmt::println("salaries [{}]: {}", i, salaries[i] );
    }

    // If you don't initialize all the elements, those you leave out
    // are initialized to 0
    int families[5] {12, 7, 5};
        for(size_t i{0}; i < 5; ++i){
        fmt::println("families [{}]: {}", i, families[i] );
    }
    */

    // Omit the size of the array at declaration
    int class_sizes[] {10,12,15,11,18,17,23,56};
    // Will print this with a range based for loop
    
    for(auto value : class_sizes){
        fmt::println("value: {}", value);
    }

    //Read only arrays
    const int birds [] {10,12,15,11,18,17,23,56};
    //birds[0] = 11;

    // Sum up scores array, store result in sum
    int scores[]{ 2, 5, 8, 2, 5, 6, 9 };
    int sum{ 0 };

    for (int element : scores) {
         sum += element; 
    }
    fmt::println("Score sum: {}", sum);
}

export void size_of_an_array(){
    //Size of an array
    int scores[]{ 1, 2, 5 };
    //int count{ std::size(scores) };// std::size( C++17)

    fmt::println("sizeof(scores) : {}", sizeof(scores));    //12
    fmt::println("sizeof(scores[0]) : {}", sizeof(scores[0]));  //4
    //fmt::println("count : {}", count);  //3


    int count {sizeof(scores)/ sizeof(scores[0])};

    //Loop through the elements of the array
    for(size_t i{}; i < count; ++i){
        fmt::println("scores[{}]: {}", i, scores[i]);
    }
}


export void arrays_of_characters(){
    //Arrays of characters
    //char message[5] {'H', 'e', 'l', 'l', 'o'}; // No space for null terminator. BAD. May crash your program
    char message[6] {'H', 'e', 'l', 'l', 'o', '\0'}; //The null terminator is there. GOOD
    //char message [] { 'H', 'e', 'l', 'l', 'o', '\0' }; // Good. Null terminator included
    //char message[] { 'H', 'e', 'l', 'l', 'o' }; // Deduced size 5. No space for null terminator. BAD.
    //char message[6]{ 'H', 'e', 'l', 'l', 'o' }; // Good. Null terminator is auto filled in. I wouldn't rely on this though.

    //fmt::println("Message: {}", message);

    int data[5] {1, 2, 3 , 4 , 5};
    //fmt::println("Data: {}", data); // fmt knows how to print arrays of characters.

    // Print out the array through looping
    fmt::println( "message : ");
    for( auto c : message){
        fmt::println("{}", c );
    }

    //Change characters in our array
    message[1] = 'a';

    //Print out the array through looping
    fmt::println( "message : ");
    for( auto c : message){
        fmt::println("{}", c );
    }

    // If a character array is null terminated, it's called as C-String
    char message1 [] {'H','e','l','l','o','\0'};
    fmt::println( "message1 : {}", message1 );
    fmt::println( "sizeof(message1) : {}", sizeof(message1) );  // 6

    // String literal
    char message4 [] {"Hello"}; // The null terminator is auto filled in.
    fmt::println( "message4 : {}", message4 );
    fmt::println( "sizeof(message4) : {}", sizeof(message4) );  // 6
}


export void array_bounds(){
    //Array bounds
    int numbers[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Read beyond bounds : May read garbage or crash your program
    fmt::println("numbers[12] : {}",  numbers[12]);

    // Write beyond bounds. The compiler allows it. But you don't own
    // the memory at index 12, so other programs may modify it and your
    // program may read bogus data at a later time. Or you can even
    // corrupt data used by other parts of your ptogram

    numbers[129] = 1000;
    fmt::println("numbers[129]: {}", numbers[129]);

    fmt::println("Program ending....");
}