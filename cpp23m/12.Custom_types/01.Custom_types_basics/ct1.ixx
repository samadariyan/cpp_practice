/*
    . The syntax to create classes
    . private and private keywords
    . struct and class
        . class makes things private by default
        . sturct makes things public by default
    . create object of our class
    . Access data inside of the class: 
        . reading 
        . changing information in the class object
    . Move the code of the class into a module file.
*/
module;

#include <cstdint>

export module ct1;

namespace ct1
{
    export class Pixel{
        public:
            uint32_t m_color{0xFF000000};
            unsigned int m_pos_x{0};
            unsigned int m_pos_y{0}; 
    };


    /*
    export struct Pixel{
        //public:
            uint32_t m_color{0xFF000000};
            unsigned int m_pos_x{0};
            unsigned int m_pos_y{0}; 
    };
    */
    
} // namespace ct1
