/*
    . Separating declarations from definitions in the same file.
*/
module;

#include <cstdint>
#include <fmt/format.h>

export module ct3;

namespace ct3
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


    //Implementations
    //Constructor
    Pixel::Pixel(uint32_t color, unsigned int x, unsigned int y){
        m_color = color;
        m_pos_x = x;
        m_pos_y = y;
    }

    //Destructor
    Pixel::~Pixel(){
        //Release the memory
        fmt::println("Pixel object destroyed...");
    }

    //Getters
    uint32_t Pixel::get_color() const{
        //m_color = 0xffffffff;
        return m_color;
    }

    unsigned int Pixel::get_x() const{
        return m_pos_x;
    }

    unsigned int Pixel::get_y() const{
        return m_pos_y;
    }

    //Setters: 
    void Pixel::set_color(uint32_t color){
        this->m_color = color;
    }

    void Pixel::set_x(unsigned int x){
        this->m_pos_x = x;
    }

    void Pixel::set_y(unsigned int y){
        this->m_pos_y = y;
    }

} // namespace ct3
