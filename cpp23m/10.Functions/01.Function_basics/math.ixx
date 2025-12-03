module;

export module math;

namespace it_1
{
    //A function to add up two numbers
    export int add(int a, int b){

        //Body of the function
        return a + b;

    }

    export int inc_mult(int a, int b) {
        int result = ((++a) * (++b));
        return result;
    }
    
} // namespace it_1


namespace it_2
{
    export int add(int a, int b);
    export int inc_mult(int a, int b);
    
} // namespace it_2


