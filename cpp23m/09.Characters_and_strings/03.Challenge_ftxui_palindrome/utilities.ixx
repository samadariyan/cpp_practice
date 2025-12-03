module;

#include <cctype>
#include <cstring>
#include <fmt/format.h>

#include <ftxui/dom/elements.hpp>       // for text, Element, hbox, vbox, border
#include <ftxui/screen/screen.hpp>      // for Screen
#include <ftxui/component/component.hpp> // for Input, Renderer, ScreenInteractive
#include <ftxui/component/screen_interactive.hpp> // for ScreenInteractive

export module utilities; 

namespace ftxui_palindrome_app
{

    bool is_palindrome(const std::string& str) {

        if(str.empty()){
            return false;
        }

        size_t start = 0;
        size_t end = str.size() - 1;

        while (start < end) {
            // Skip non-alphanumeric characters
            while (start < end && !std::isalnum(str[start])) {
                start++;
            }
            while (start < end && !std::isalnum(str[end])) {
                end--;
            }

            // Compare characters (case-insensitive)
            if (std::tolower(str[start]) != std::tolower(str[end])) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }


    export void app(){

        using namespace ftxui;

        //Setup variables to store input and the result
        std::string user_input;
        std::string result;

        //The input component
        auto input_component = Input(&user_input, "Enter text");

        //Renderer to diplay input and output
        auto renderer = Renderer(input_component,[&](){

            // Check if input is a palindrome and update the result
            if (user_input.empty()) {
                result = "Enter a string to check if it is a palindrome.";
            } else if (is_palindrome(user_input)) {
                result = "The string is a palindrome!";
            } else {
                result = "The string is not a palindrome.";
            }

            auto answer = is_palindrome(user_input);


            //Render the ftxui components
            return vbox({
                text("Palindrome Checker") | bold | color(Color::Yellow),
                separator(),
                hbox(text("Input: "), input_component->Render()) | border,
                separator(),
                text("Result: " + result ) | color(is_palindrome(user_input) ? Color::Green : Color::Red)
            });

        });


        //Set up the screen and start the event loop
        auto screen = ScreenInteractive::TerminalOutput();
        screen.Loop(renderer);

    }
    
} // namespace ftxui_palindrome_app
