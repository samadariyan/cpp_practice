module;

#include <fmt/format.h>

export module utilities; 

export void process_arguments(int argc, char* argv[]){
    fmt::println("number of arguments: {}", argc);

    for(size_t i{0}; i < argc; ++i){
        fmt::println("arg [{}]: {}", i, argv[i]);
    }   
}


export void calculator(int argc, char* argv[]){

    //Check the number of arguments
    if(argc != 4){
        fmt::println("Program can only be called with 3 arguments like: ");
		fmt::println("Rocket a + b");
		fmt::println("You called with : ");
		for (int i{ 0 }; i < argc; ++i) {
			 fmt::print(" {}", argv[i]); 
		}
		return;
    }

	// Grab the operands
	double first_number{ std::atof(argv[1]) };
	double second_number{ std::atof(argv[3]) };

    if ((first_number == 0.0) || (second_number == 0.0)) {
		fmt::println("Please use valid numbers ( different from zero) for first and second parameters)");
		return;
	}

    // Grab the operation
	const char *operation{ argv[2] };
    char c;

	if ((std::strlen(operation) == 1)
				&& (	   (operation[0] == '+') 
						|| (operation[0] == '-') 
						|| (operation[0] == 'x')
						|| (operation[0] == '/'))
				){
		c = operation[0];
	} else {
		fmt::println("{} is not a valid operation.", operation);
		return;
	}

    // Do the operation
	switch (c) {
	case '+':
		fmt::println("{} + {} = {}", first_number, second_number, first_number + second_number);
		break;

	case '-':
		fmt::println("{} - {} = {}", first_number, second_number, first_number - second_number);
		break;

	case 'x':
		fmt::println("{} x {} = {}", first_number, second_number, first_number * second_number);

		break;

	case '/':
		fmt::println("{} / {} = {}", first_number, second_number, first_number / second_number);

		break;
	}

}