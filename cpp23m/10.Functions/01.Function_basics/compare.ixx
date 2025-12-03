module;

export module compare;

//Iteration 1 of separating functions across multiple files
namespace it_1
{
    export int maximum(int a, int b) {
        if (a > b)
            return a;
        else
            return b;
    }

    export int minimum(int a, int b) {
        if (a < b)
            return a;
        else
            return b;
    }
    
} // namespace it_1

namespace it_2
{
    export int maximum(int a, int b);  // Function declaration , prototype
                            // Signature doesn't include return type
    export int minimum(int a, int b);
    
} // namespace it_2

