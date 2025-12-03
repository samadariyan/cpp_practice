module;

#include <fmt/format.h>

export module overloading_1;

namespace overloading_1
{
    export void print(int value){
        fmt::println("Integer: {}", value);
    }

    export void print(int value1, int value2){
        fmt::println("Integer1: {}, Integer2: {} ", value1, value2);
    }

    export void print(double value){
        fmt::println("Double: {}", value);
    }

    export void print(const std::string& value){
        fmt::println("String: {}", value);
    }
    
} // namespace overloading_1
