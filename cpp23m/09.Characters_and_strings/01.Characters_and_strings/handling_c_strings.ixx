module;

#include <cstring>
#include <fmt/format.h>

export module handling_c_strings;

namespace handling_c_strings
{
        export void cstring_strlen(){
        //std::strlen : Find the length of a string
        // real arrays and those decayed into pointers
        const char message1 [] {"The sky is blue."};

        //Array decays into pointer when we use const char*
        const char* message2 {"The sky is blue."};
        fmt::println( "message1 : {}",  message1 );
        fmt::println( "message2 : {}",  message2 );

        //strlen ignores null character
        fmt::println( "strlen(message1) : {}", std::strlen(message1) );

        // std::sizeof includes the null character
        fmt::println( "sizeof(message1) : {}",  sizeof(message1) );

        //strlen still works with decayed arrays
        fmt::println( "strlen(message2) : {}" , std::strlen(message2) );

        //std::size prints size of pointer
        fmt::println( "sizeof(message2) : {}",  sizeof(message2) );
    }
    

    export void cstring_strcmp(){

        // std::strcmp - signature : int strcmp( const char *lhs, const char *rhs );
        // Returns negative value if lhs appears before rhs in lexicographical order,
        // Zero if lhs and rhs compare equal.
        // and Positive value if lhs appears after rhs in lexicographical order.
        fmt::println("");
        fmt::println( "std::strcmp : " );

        const char* string_data1{ "Blabama" };
        const char* string_data2{ "Alabama" };

        char string_data3[]{ "Blabama" };
        char string_data4[]{ "Alabama" };

        //Print out the comparison
        fmt::println( "std::strcmp ({} ,{} ) : {}",  string_data1 , string_data2, std::strcmp(string_data1, string_data2) );

        fmt::println( "std::strcmp ({}, {}): {}" , string_data3 , string_data4,  std::strcmp(string_data3, string_data4) );

        string_data1 = "Alabama";
        string_data2 = "Alabamb";

        //string_data3 = "Alabama"; // Error: can't directly assign to a static array
        //string_data4 = "Alabamb";

        //Print out the comparison
        fmt::println( "std::strcmp ({}, {} ) : {}",string_data1,  string_data2,  std::strcmp(string_data1, string_data2) );


        string_data1 = "Alacama";
        string_data2 = "Alabama";

        //Print out the comparison
        fmt::println( "std::strcmp ({}, {}) : {}", string_data1 ,  string_data2 , std::strcmp(string_data1, string_data2) );

        string_data1 = "India";
        string_data2 = "France";

        //Print out the comparison
        fmt::println( "std::strcmp ({}, {}) : {}", string_data1,  string_data2, std::strcmp(string_data1, string_data2) );

        string_data1 = "Kigali";
        string_data2 = "Kigali";

        //Print out the comparison
        fmt::println( "std::strcmp ({}, {}): {}", string_data1 , string_data2 , std::strcmp(string_data1, string_data2) );
    }

    export void cstring_strncmp(){
        // std::strncmp : int strncmp( const char *lhs, const char *rhs, std::size_t count );
        // Compares n characters in the strings
        // Returns : Negative value if lhs appears before rhs in lexicographical order.
        // Zero if lhs and rhs compare equal, or if count is zero.
        // Positive value if lhs appears after rhs in lexicographical order.
        // Print out the comparison

        const char* string_data1{ "Alabama" };
        const char* string_data2{ "Blabama" };
        size_t n{3};
        fmt::println("");
        fmt::println( "std::strncmp: " );
        fmt::println( "std::strncmp ({}, {}, {}): {}", string_data1, string_data2, n,
                    std::strncmp(string_data1,string_data2,n) );

        string_data1 = "aaaia";
        string_data2 = "aaance";

        fmt::println( "std::strncmp ({}, {}, {}): {}", string_data1, string_data2, n,
                    std::strncmp(string_data1,string_data2,n) );

        n = 5;

        fmt::println( "std::strncmp ({}, {}, {}): {}", string_data1, string_data2, n,
                    std::strncmp(string_data1,string_data2,n) );

        string_data1 = "aaaoa";
        string_data2 = "aaance";

        fmt::println( "std::strncmp ({}, {}, {}): {}", string_data1, string_data2, n,
                    std::strncmp(string_data1,string_data2,n) );
    }

    
} // namespace handling_c_strings

