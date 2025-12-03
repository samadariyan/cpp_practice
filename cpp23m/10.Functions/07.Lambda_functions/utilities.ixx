module;

#include <fmt/format.h>

export module utilities;

//Declaring and using lambdas
export void declare_and_use_lambda_func(){
    /*
	Lambda function signature :
								[capture list] (parameters) ->return type{
										// Function body
								}
	*/
	// Declaring a lambda function and calling it through a name
    /*
    auto func = [](){
        fmt::println("Hello World!");
    };

    //Call the lambda
    func();
    func();
    */

   	// Declare a lambda function and call it directly
    /*
    [](){
        fmt::println("Hello World!");
    }();
    */

   // Lambda function that takes parameters
   /*
   [](double a, double b){
        fmt::println( "a + b: {}" , (a + b)  );  
   }(10.0, 22.0);
   */

    /*
	auto func1 = [](double a, double b){
		fmt::println( "a + b: {}" , (a + b)  );
	};

	func1(10,20);
	func1(5,7);
    */

   // Lambda function that returns something
   /*
    auto result = [](double a, double b){
        return a + b;
    }(10,60);
    fmt::println("Result: {}", result);

    fmt::println("Result: {} " , [](double a, double b){
		return a + b;
	}(10,60) );
    */

    //Store the lambda name in a variable
    /*
    auto func1 = [](double a, double b){
        return a + b;
    };

    auto result1 = func1(23,7);
    auto result2 = func1(9,45);

    fmt::println( "Result1: {} " , result1);
    fmt::println( "Result2: {} " , result2);
    fmt::println( "direct call: {} " , func1(5,2));
    */

   	// Explicitly specify the return type
    auto func3 = [] (double a, double b) -> int {
        return a + b;
    };

    auto func4 = [] (double a, double b){
        return a + b;
    };

    auto result3 = func3(10.1, 20.2);
    auto result4 = func4 (10.1, 20.2);

    fmt::println("result3 : {}", result3);
	fmt::println("result4 : {}", result4);
	fmt::println("sizeof(result3) : {}", sizeof(result3));// 4
	fmt::println("sizeof(result4) : {}", sizeof(result4));// 8

}


export void capture_lists(){
    //Capture lists
    double a{10};
    double b{20};

    auto func =[a,b](){
        fmt::println("a + b: {}", (a + b));
    };
    func();
}


export void capture_by_value_modification() {
    int x {10};

    // Lambda capturing 'x' by value
    auto lambda = [x]() mutable {
        x += 5;
        fmt::println("Inside lambda (modified copy): {}", x);
    };
    fmt::println("Original value before lambda: {}", x);
    lambda();
    fmt::println("Original value after lambda: {}", x);  // Unchanged
}

export void capture_by_reference_modification() {
    int x {10};

    // Lambda capturing 'x' by reference
    auto lambda = [&x]() {
        x += 5;  // Modifies the original variable
        fmt::println("Inside lambda (modified original): {}", x);
    };

    fmt::println("Original value before lambda: {}", x);
    lambda();
    fmt::println("Original value after lambda: {}", x);  // Changed
}


export void capture_all_by_value() {
    int x {10};
    int y {20};

    // Lambda capturing all by value
    auto lambda = [=]() mutable {
        // Modify the captured values inside the lambda
        x += 5;
        y += 5;

        fmt::println("Inside lambda (x copy modified): {}", x);
        fmt::println("Inside lambda (y copy modified): {}", y);
    };

    fmt::println("Original values before lambda: x = {}, y = {}", x, y);
    lambda();
    fmt::println("Original values after lambda: x = {}, y = {}", x, y);  // Unchanged
}


export void capture_all_by_reference() {
    int x = 10;
    int y = 20;

    // Lambda capturing all by reference
    auto lambda = [&]() {
        // Directly modify the original variables
        x += 5;
        y += 10;

        fmt::println("Inside lambda (x modified): {}", x);
        fmt::println("Inside lambda (y modified): {}", y);
    };

    fmt::println("Original values before lambda: x = {}, y = {}", x, y);
    lambda();
    fmt::println("Original values after lambda: x = {}, y = {}", x, y);  // Changed
}