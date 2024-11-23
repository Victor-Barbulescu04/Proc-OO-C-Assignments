//
// Created by vicb2 on 11/16/2024.
//

#include "GameController.h"

int main() {
    GameController controller;

    // Initialize the map layout
    const std::vector<std::vector<char>> mapBuilder = {
        {'.', '.', '>', '+', '.'},
        {'.', '!', '@', '.', '>'},
        {'.', '?', '.', '>', '!'},
        {'.', '@', '#', '.', '.'},
        {'@', '.', '?', '>', '@'}
    };

    // Play the game
    controller.start(mapBuilder);
}
