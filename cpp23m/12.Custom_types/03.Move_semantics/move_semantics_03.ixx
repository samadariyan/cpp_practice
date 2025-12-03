module;

#include <fmt/format.h>
#include <vector>

export module move_semantics_03;

import canvas;

namespace move_semantics_03
{
    raw::Canvas make_canvas(std::size_t width, std::size_t height){
        return raw::Canvas(width, height);
    }

    export void canvas_move_semantics_demo_1(){
        std::vector<raw::Canvas> canvases(3);

        for(size_t i{0} ; i < 3 ; ++i){
            fmt::println("Iteration: {}", i);
            canvases[i] = make_canvas(10,10);
            fmt::println("");
        }   
    }


    export void canvas_move_semantics_demo_2(){
        raw::Canvas c(10,10);
        c = make_canvas(20,20);

        raw::Canvas c2 (30,30);
        c = c2;
        fmt::println("All done.");
    }

} // namespace move_semantics_03;
