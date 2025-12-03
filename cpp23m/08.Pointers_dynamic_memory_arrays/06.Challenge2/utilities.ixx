module;

#include <ftxui/component/screen_interactive.hpp> // For ScreenInteractive
#include <ftxui/dom/elements.hpp>                // For text, vbox, hbox
#include <ftxui/component/component.hpp> // for Button, Horizontal, Renderer, etc.
#include <string>

export module utilities; 


namespace ftxui_it1
{
    export void app(){

        using namespace ftxui;

        //Create the UI elements
        auto document = vbox({
            /*
            text("One"),
            text("One"),
            text("One"),
            text("One"),
            text("One"),
            text("Two")
            */
            hbox({text("Cell 1    ") | bold | color(Color::Red), text("Cell 2")}),
            hbox({text("Cell 3    "), text("Cell 4")})


        });

        //Create a screen and display the UI
        auto screen = ScreenInteractive::Fullscreen();
        screen.Loop(Renderer([&] { return document; }));

    }
    
} // namespace ftxui_it1


namespace ftxui_it2
{
    export void app(){
        using namespace ftxui;

        std::string message = "Click a button!";

        auto button1 = Button("Button 1", [&] { message = "Button 1 clicked!"; });
        auto button2 = Button("Button 2", [&] { message = "Button 2 clicked!"; });

        /*
        auto layout = vbox({
            text(message),
            button1->Render(),
            button2->Render(),
        });
        */

       auto container = Container::Vertical({
            button1,
            button2
       });

       auto renderer = Renderer(container, [&]{
            return vbox({
                text(message),
                button1->Render(),
                button2->Render(),

            });
       });

        auto screen = ScreenInteractive::Fullscreen();
        screen.Loop(renderer);      
    }
    
} // namespace ftxui_it2

