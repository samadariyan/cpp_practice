module;

#include <fmt/format.h>

export module utilities; 

import canvas;

export void static_functions_demo(){

	//Before we introduce reference members
    raw::Configuration config1{ 800, 600, "My Canvas", false };
	raw::Canvas canvas1 = raw::Canvas::create_default_canvas(config1);
	raw::Canvas canvas2= raw::Canvas::create_default_canvas(config1);
	raw::Canvas canvas3= raw::Canvas::create_default_canvas(config1);
	raw::Canvas canvas4 = raw::Canvas::create_default_canvas(config1);

	fmt::print("Total canvas count: {}\n", raw::Canvas::get_total_canvas_count());

	//After we introduce reference members
	/*
	raw::Configuration config1{ 800, 600, "My Canvas", false };
	raw::Canvas canvas1{ 10, 10, config1 };
	//canvas1.print();


	auto canvas2 = raw::Canvas::create_default_canvas(config1);
	canvas2.print();
	*/



	fmt::println("Done.");


}