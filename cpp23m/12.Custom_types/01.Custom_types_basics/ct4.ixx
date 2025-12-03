/*
    . Separating declarations from definitions in different files.
        . module interface file: ct4.ixx
        . module implementation file: ct4.cpp 
*/
module;

#include <cstdint>

export module ct4;

namespace ct4
{
    export class Pixel{
        public: 
            Pixel() = default;
            Pixel(uint32_t color, unsigned int x, unsigned int y);
            ~Pixel();

            //Getters
            uint32_t get_color() const;
            unsigned int get_x() const;
            unsigned int get_y() const;

            //Setters: 
            void set_color(uint32_t color);
            void set_x(unsigned int x);
            void set_y(unsigned int y);
        private:
            uint32_t m_color{0xFF000000};
            unsigned int m_pos_x{0};
            unsigned int m_pos_y{0}; 
    };
    
} // namespace ct4
