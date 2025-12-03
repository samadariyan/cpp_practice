module;

#include <cstddef>
#include <fmt/format.h>
#include <vector>


export module canvas;

export import pixel;

namespace raw{

    //Add a configration struct and set up a method to print the configuration.
    export struct Configuration{
        std::size_t width{0};
        std::size_t height{0};
        std::string title{""};
        bool full_screen{false};
    };


    export class Canvas {

    public:
        Canvas(std::size_t width , std::size_t height, const Configuration& config);
        Canvas(const Canvas& src);
        Canvas(Canvas&& other) noexcept;
        ~Canvas();

        Canvas& operator=(const Canvas& rhs);
        Canvas& operator=(Canvas&& other) noexcept;

        void modify_pixel(std::size_t x, std::size_t y, const Pixel& pixel);
        Pixel& retrieve_pixel(std::size_t x, std::size_t y);

        void swap(Canvas& other) noexcept;

        void print() const;

        // Static methods
        static Canvas create_default_canvas(const Configuration& config);
        static std::size_t get_total_canvas_count();

    private:
        void verify_coordinate(std::size_t x, std::size_t y) const;

        std::size_t m_width{ 0 };
        std::size_t m_height{ 0 };
        Pixel** m_pixels{ nullptr };

        //Static member variable
        //static std::size_t s_canvas_count;
        static inline std::size_t s_canvas_count {0};

        // Static constexpr variables: These are used in the create_default_canvas method.
        static constexpr std::size_t DEFAULT_WIDTH {10};
        static constexpr std::size_t DEFAULT_HEIGHT {20};

        // Reference member variable
        const Configuration& m_config;


    };

    export void swap(Canvas& first, Canvas& second) noexcept;
}   // namespace raw
