module;

#include <SFML/Graphics.hpp>

export module game;
export class Game {
public:
    Game();
    void run();

private:
    void handle_key_press(sf::Keyboard::Key key);
    void process_events();
    void render();

    sf::RenderWindow window_;
};