module;

#include <fmt/format.h>

export module utilities; 

// Tools
constexpr int Pen{ 10 };
constexpr int Marker{ 20 };
constexpr int Eraser{ 30 };
constexpr int Rectangle{ 40 };
constexpr int Circle{ 50 };
constexpr int Ellipse{ 60 };

//Colors
constexpr int Red{ 70 };
constexpr int Green{ 80 };
constexpr int Blue{ 90 };


bool car()
{
  fmt::println("car function running");
  return false;
}

bool house()
{
  fmt::println("house function running");
  return true;
}
bool job()
{
  fmt::println("job function running");
  return false;
}
bool spouse()
{
  fmt::println("spouse function running");
  return false;
}

//std::unreachable: C++ 23 
void handle_color(int color) {
    switch (color) {
        case Red:
			fmt::println("Handling Red");
            break;
        case Green:
			fmt::println("Handling Green");
            break;
        case Blue:
			fmt::println("Handling Blue");
            break;
        default:
            // We expect that all cases are covered, so reaching here should never happen.
            std::unreachable();
    }
}

export void if_statement(){
    //If statements
    int number1  {75};
    int number2 {60};
    bool result = (number1 < number2); // Expression yielding a condition

    //Regular if statement
    /*
    //if(result == true){
    if(result){
        fmt::println("It is true");
    }else{
        fmt::println("It is false");
    }
    */

    //Negative if statements
    /*
    if(!result){
        fmt::println("It is true");
    }else{
        fmt::println("It is false");
    }
    */


  	// Use expression as condition directly
    /*
    fmt::println( "Using expression as condition : " );
    if(number1 < number2){
      	fmt::println("{} is less than {}" ,number1, number2 );
  	}else{
      	fmt::println("{} is NOT less than {}" ,number1, number2 );
  	}
    */

    // Nesting if statements
    /*
  	fmt::println("Nesting if statements");

  	bool red = false;
  	bool green{ true };
  	bool yellow{ false };
  	bool police_stop{ true };
	
   	//   If green : go
   	//   If red, yellow : stop
   	//   If green and police_stop : stop
   	
  	if(red){
      	fmt::println( "Stop" );
  	}
  	if(yellow){
      	fmt::println( "Slow down" );
  	}
    if(green){
        fmt::println( "Go" );
    }

    fmt::println( "Police officer stops(verbose)" );
    if(green){
    	if(police_stop){
        	fmt::println( "Stop" );
    	}else{
           	fmt::println( "Go" );
       	}
   	}

  	fmt::println("Police officer stops(less verbose)");
  	if (green && !police_stop) {
    	fmt::println("Go");
  	} else {
    	fmt::println("Stop");
  	}
    */

   	//If with initializer
    /*
	bool go{ true };
  	if (int speed{ 10 }; go) {
    	fmt::println("speed: {}", speed);

    	if (speed > 5) {
      	fmt::println("Slow down!");
    	} else {
      	fmt::println("All good!");
    	}
  	} else {
    	fmt::println("speed: {}", speed);
    	fmt::println("Stop");
  	}
    */

    //Else if
    int tool{ Eraser };

  	if (tool == Pen) {
    	fmt::println("Active tool is pen");
    	// Do the actual painting
  	} else if (tool == Marker) {
    	fmt::println("Active tool is Marker");
  	} else if (tool == Eraser) {
    	fmt::println("Active tool is Eraser");
  	} else if (tool == Rectangle) {
    	fmt::println("Active tool is Rectangle");
  	} else if (tool == Circle) {
    	fmt::println("Active tool is Circle");
  	} else if (tool == Ellipse) {
    	fmt::println("Active tool is Ellipse");
  	}
}


export void switch_statement(){
    //Switch statement
    /*
    int tool { Pen};

    switch (tool)
    {
    case Pen : {
        fmt::println("Active tool is pen.");
    }break;

    case Marker : {
        fmt::println("Active tool is Marker.");
    }break;

    case Eraser:
    case Rectangle:
    case Circle : {
        fmt::println("Combined block.");
    }break;

    case Ellipse : {
        fmt::println("Active tool is Ellipse.");
    }break;
    
    default: {
        fmt::println("No match was found");
    }break;
    }
    */

    //Switch with initializer
    int tool{ Eraser };

	switch (double strength{ 3.56 }; tool) {
		case Pen: {
			fmt::println("Active tool is Pen. strength : {}", strength);
		} break;

		case Marker: {
			fmt::println("Active tool is Marker. strength : {}", strength);
		} break;

		case Eraser:
		case Rectangle:
		case Circle: {
			fmt::println("Drawing Shapes. strength : {}", strength);
		} break;

		case Ellipse: {
			fmt::println("Active tool is Ellipse. strength : {}", strength);
		} break;

		default: {
			fmt::println("No match found. strength : {}", strength);
		} break;
	}
}

export void short_circuit_evaluations(){
    //Short circuit evaluations
    /*
    bool a{ false };
    bool b{ true };
    bool c{ true };
    bool d{ true };

    bool p{ false };
    bool q{ false };
    bool r{ false };
    bool m{ true };

    //AND : If one of the operands is false, the result is false. 
    fmt::println( "AND short circuit" );
    bool result = a && b && c && d;
    fmt::println( "AND - result: {}", result );

    //OR : If one of the operands is true, the result is true.
    fmt::println( "OR short circuit" );
    result = p || q || r || m;
	fmt::println( "OR - result: {}", result );
    */

    //How to make me happy
    if (car() && house() && job() && spouse()) {
        fmt::println( "AND - I am happy" );
    }
    else {
        fmt::println( "AND - I am sad" );
    }

    if (car() || house() || job() || spouse()) {
        fmt::println("OR - I am happy");
    } else {
        fmt::println("OR - I am sad");
    }
}

export void ternary_operator(){
    //Ternary operator
    int max{};
    
    int a{ 335 };
    int b{ 200 };
    
    //  if(a >  b){
    //     max = a;
    //  }else{
    //       max = b;
    //  }
    
    max = (a > b) ? a : b;// Ternary operator
    fmt::println("max :{} ", max);
}

export void std_unreachable(){
    //std::unreachable
    handle_color(Red);
    handle_color(Green);
    handle_color(Blue);
}