module;

#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

#include <string>

export module challenge1;

namespace ftxui_it1 {
export void app() {

    using namespace ftxui;

    // Create the UI elements
    auto document = vbox(
        {hbox({text("Cell 1    ") | bold | color(Color::Red), text("Cell 2")}),
         hbox({text("Cell 3    "), text("Cell 4")})});

    // Create a screen and display the UI
    auto screen = ScreenInteractive::Fullscreen();
    screen.Loop(Renderer([&] { return document; }));
}

} // namespace ftxui_it1

namespace ftxui_it2 {
export void app() {
    using namespace ftxui;

    std::string message = "Click a button!";

    auto button1 = Button("Button 1", [&] { message = "Button 1 clicked!"; });
    auto button2 = Button("Button 2", [&] { message = "Button 2 clicked!"; });

    auto container = Container::Vertical({button1, button2});

    auto renderer = Renderer(container, [&] {
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