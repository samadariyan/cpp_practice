module;

#include <cstdint>
#include <fmt/format.h>

module ct4;

namespace ct4
{
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
    
} // namespace ct4
