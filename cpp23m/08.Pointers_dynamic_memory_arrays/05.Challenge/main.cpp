/*
    . Explore dynamic memory with the shape animator sfml application: 
        . dm_1: storing the data in a std::vector
        . dm_2: storing the data in dynamic arrays: new and delete
        . dm_3: storing the data in dynamic arrays: smart pointers 

*/

import utilities;

int main(){

    //This is the best way to go
    /*
    dm_1::app();
    */

    //This is the worst way to go
    /*
    dm_2::app();
    */

    //This is the second worst way
    dm_3::app();
    
}