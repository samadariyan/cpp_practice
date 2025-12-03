module;

#include <SFML/Graphics.hpp>

export module utilities;

import board;

void handleInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

export void app(){

    sf::RenderWindow window(sf::VideoMode(Board::WIDTH * Board::BLOCK_SIZE, 
                            Board::HEIGHT * Board::BLOCK_SIZE), 
                            "Tetris");
    Board board;
    board.initialize();
    BoardEntity entity(board);

    while ((window.isOpen()))
    {
        handleInput(window);
        window.clear();
        entity.draw(window);
        window.display();
    }
}