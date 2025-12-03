/*
    . Topics: 
        . the private and public access specifiers
        . constructors
            . Compiler generated default constructor
            . Default constructor
            . The need for default constructors
            . Explicitly defaulted default constructor
        . destructors
        . setters and getters
        . const members functions
        . the this pointer
        . Different ways to allocate objects in C++
            . on the stack
            . on the heap with raw pointers
            . on the heap with smart pointers
*/
module;


#include <cstdint>
#include <fmt/format.h>

export module ct2;

namespace ct2
{
    export class Pixel{
        public: 

            //Default constructor: explicitly defaulted
            Pixel() = default;

            /*
            //Not recommended in modern C++
            Pixel(){

            }
            */

            //Constructor
            Pixel(uint32_t color, unsigned int x, unsigned int y){
                m_color = color;
                m_pos_x = x;
                m_pos_y = y;
            }

            //Destructor
            ~Pixel(){
                //Release the memory
                fmt::println("Pixel object destroyed...");
            }

            //Getters
            uint32_t get_color() const{
                //m_color = 0xffffffff;
                return m_color;
            }

            unsigned int get_x() const{
                return m_pos_x;
            }

            unsigned int get_y() const{
                return m_pos_y;
            }

            //Setters: 
            void set_color(uint32_t color){
                this->m_color = color;
            }

            void set_x(unsigned int x){
                this->m_pos_x = x;
            }

            void set_y(unsigned int y){
                this->m_pos_y = y;
            }

            //Setters  for count
            void set_count(unsigned int count){
                this-> count = count;
            }

        private:
            uint32_t m_color{0xFF000000};
            unsigned int m_pos_x{0};
            unsigned int m_pos_y{0}; 
            unsigned int count{0};
    };
    
} // namespace ct2
