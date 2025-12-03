module;

#include <string>
#include <fmt/format.h>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>

export module utilities; 


export void random_num_old_style(){
    std::srand(std::time(nullptr)); // use current time as seed for random generator

    //The basics
    /*
    int random_value = std::rand();
    std::cout << "Random value on [0, " << RAND_MAX << "]: " << random_value << '\n';
    */

    // Generate random numbers in a loop
    /*
    int random_num;
    for(size_t i {0} ; i < 20 ; ++i){
        random_num = std::rand();
        fmt::println("random_num {}: {}", i,  random_num ); // 0 ~ RAND_MAX
    }
    */


    //Generate a number between 0 and 10
    int random_num = std::rand() % 100 + 1; // [0~10]

    fmt::println("value: {}", random_num);
    for (size_t i{ 0 }; i < 20; ++i) {
        random_num = std::rand() % 100 + 1;
        fmt::println("random_num {} : {}", i, random_num);// 0 ~ 100
    } 
}


export void random_num_modern_cpp(){
    // Random numbers ( C++17 )
    std::random_device rd;  // Provides seeds with less predictability
    std::mt19937 marsenne{ rd() };  // Initialize our mersenne twister with a random seed
    std::uniform_int_distribution die{ 1, 6 };  // We want uniform distribution.

    auto rando_num {die(marsenne)};
    fmt::println("Value: {}", rando_num);

    for (size_t count{ 0 }; count < 48; ++count) {
        fmt::println("{}", die(marsenne));
    }
}

export void random_num_example(){
    //Random number example
    std::vector<std::string> predictions { 
            "a lot of kids running in the backyard!",
            "a lot of empty beer bootles on your work table.",
            "you Partying too much with kids wearing weird clothes.",
            "you running away from something really scary",
            "clouds gathering in the sky and an army standing ready for war",
            "dogs running around in a deserted empty city",
            "a lot of cars stuck in a terrible traffic jam",
            "you sitting in the dark typing lots of lines of code on your dirty computer",
            "you yelling at your boss. And oh no! You get fired!",
            "you laughing your lungs out. I've never seen this before.",
            "Uhm , I don't see anything!",
            "you eating nice food"
    };

    //Use the marsenne twister to generate a random number and store that in a variable named index.
    std::random_device rd;  // Provides seeds with less predictability
    std::mt19937 marsenne{ rd() };  // Initialize our mersenne twister with a random seed
    const int size(predictions.size()-1); // The distribution expects constant expressions in it's initializer.
    std::uniform_int_distribution distr{ 0, size };  // We want uniform distribution.
    auto index = distr(marsenne);

    fmt::println("Prediction :I see {}", predictions[index]); //[0 ~ (size-1)]
}