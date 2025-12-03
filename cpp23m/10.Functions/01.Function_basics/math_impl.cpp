module;

module math;

namespace it_2
{
    //A function to add up two numbers
    int add(int a, int b){

        //Body of the function
        return a + b;

    }

    int inc_mult(int a, int b) {
        int result = ((++a) * (++b));
        return result;
    }
    
} // namespace it_2
