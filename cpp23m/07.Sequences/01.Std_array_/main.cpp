/*
    . Exploring the std::array collection type in C++.
    . Goal: 
        . Show that std::array is one of your best default choices when you need to deal with sequence data in C++.
    . Benefits: 
        . Each collection knows its size.
        . Easy to pass to functions (doesn't need to pass the size as a separate parameter).
        . Convenient functions to get the front and back elements.
        . Can be compared using comparison operators (==, !=, <, <=, >, >=).
        . Can assign a std::array to another std::array.
        . Can store an std::array in another container.
        . You don't have to mess with low lever arrays and pointers. 

    . Points to make: 
        . The differences between at() and operator[].
        . std::array should be your choice if you know the size of the collection at compile time, and you won't need to change its size.
   
*/

#include <array>
#include <fmt/format.h>

import utilities;

int main(){
    //setup_and_visit();
    //modifications();
    //fill_with_data();
    //front_and_back();
    //two_dimensional_data();
    //comparing_std_array();
    //assigning_std_array();

}