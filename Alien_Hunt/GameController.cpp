//
// Created by vicb2 on 11/15/2024.
//

#include "GameController.h"

#include <iostream>

#include "Room.h"
#include "Alien.h"
#include "Weapon.h"
#include "Hazard.h"
#include "Person.h"
#include "Survivor.h"
#include "Treasure.h"
#include "Entity.h"

using namespace std;

// -------------------------------------------------------- //
// Constructor/destructor

GameController::GameController() = default;
GameController::~GameController() {
    // Delete the map and its contents
    for (auto& row : currMap) {
        for (auto& element : row) {
            delete element;
            element = nullptr;
        }
    }

    currMap.clear();

    // Delete the current room pointer
    delete currRoom;
    currRoom = nullptr;

    // Delete the current player pointer
    delete player;
    player = nullptr;
}

// -------------------------------------------------------- //
// Map builder functions

vector<vector<Room *>> GameController::buildMap(const vector<vector<char> > &map) {
    const int rows = map.size();
    const int cols = map[0].size();

    // Initialize the 2D vector of Room pointers
    vector<vector<Room*>> roomGrid(rows, vector<Room*>(cols, nullptr));

    // Create Room objects and store them in the grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            roomGrid[i][j] = buildRoom(map[i][j]);
        }
    }

    // Link the rooms
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Room* currentRoom = roomGrid[i][j];

            // Set up pointer if not in the first row
            if (i > 0) {
                currentRoom->setUp(roomGrid[i - 1][j]);
                roomGrid[i - 1][j]->setDown(currentRoom);
            }

            // Set down pointer if not in the last row
            if (i < rows - 1) {
                currentRoom->setDown(roomGrid[i + 1][j]);
                roomGrid[i + 1][j]->setUp(currentRoom);
            }

            // Set left pointer if not in the first column
            if (j > 0) {
                currentRoom->setLeft(roomGrid[i][j - 1]);
                roomGrid[i][j - 1]->setRight(currentRoom);
            }

            // Set right pointer if not in the last column
            if (j < cols - 1) {
                currentRoom->setRight(roomGrid[i][j + 1]);
                roomGrid[i][j + 1]->setLeft(currentRoom);
            }
        }
    }

    return roomGrid;
}

Room *GameController::buildRoom(char entity) {
    Entity* startingEntity = new NullEntity();

    // Build entities in the room (if applicable)
    switch (entity) {
        case '>': {
            // Clean up Null Entities memory
            delete startingEntity;
            // Create two guns and two flamethrowers on the map
            if (gunCount < 2) {
                startingEntity = new Gun(3, "gun", 2);
                gunCount++;
            } else {
                startingEntity = new Flamethrower(3, "flamethrower", 3);
                flamethrowerCount++;
            }
            break;
        } case '!': {
            // Clean up Null Entities memory
            delete startingEntity;
            startingEntity = new Survivor();
            break;
        } case '@': {
            // Clean up Null Entities memory
            delete startingEntity;
            // Create two exposed wire hazards and two low oxygen hazards
            if (exposedWiresCount < 2) {
                startingEntity = new ExposedWires("exposed wires", 5);
                exposedWiresCount++;
            } else {
                startingEntity = new LowOxygenRoom("low oxygen", 4);
                lowOxygenCount++;
            }
            break;
        } case '?': {
            // Clean up Null Entities memory
            delete startingEntity;
            // Create one ammo and one medkit
            if (ammoCount < 1) {
                startingEntity = new Ammo(3, "ammo");
                ammoCount++;
            } else {
                startingEntity = new Medkit(3, "medkit");
                medkitCount++;
            }
            break;
        } case '#': {
            // Clean up Null Entities memory
            delete startingEntity;
            startingEntity = new Alien();
            break;
        } default:
        break;
    }

    // Build room with the assigned entity
    Room* startingRoom = new Room(startingEntity, nullptr);

    // If the entity in the room is a person, add a person to the room.
    if (entity == '+') {
        Person* newPerson = new Person(10, startingRoom);
        newPerson->setWeapon(new Knife(1, "knife", 1));
        startingRoom->setPerson(newPerson);

    }

    return startingRoom;
}

// -------------------------------------------------------- //
// Print contents functions

void GameController::printRoomHints(const Room *room) {
    if (room->getLeft() != nullptr) {
        room->getLeft()->getEntity()->hint();
    }
    if (room->getRight() != nullptr) {
        room->getRight()->getEntity()->hint();
    }
    if (room->getUp() != nullptr) {
        room->getUp()->getEntity()->hint();
    }
    if (room->getDown() != nullptr) {
        room->getDown()->getEntity()->hint();
    }
}

void GameController::printCurrMap() const {
    if (debugMode) {
        for (const auto& row : currMap) {
            for (const auto& element : row) {
                cout << element->getContents() << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void GameController::printGameDescription() {
    std::cout << "Game Mechanics:\n";
    std::cout << "Movement:\n";
    std::cout << "Use the following keys to move around the spaceship:\n";
    std::cout << "- 'e': Move East\n";
    std::cout << "- 'w': Move West\n";
    std::cout << "- 'n': Move North\n";
    std::cout << "- 's': Move South\n";
    std::cout << "- 'a': Shoot/Slash\n";
    std::cout << "- 'h': How to Play\n";
    std::cout << "- 'q': Quit\n\n";

    std::cout << "Hazards:\n";
    std::cout << "- Alien: If you enter a room with the Alien, it will attack, and the game will end. "
                 "Be on high alert for hints that indicate its presence.\n";
    std::cout << "- Exposed Wires and Pits: Some rooms contain either exposed wires or open pits. "
                 "Entering one of these rooms could result in a fall and taking 5 damage.\n";
    std::cout << "- Low Oxygen Room: If you enter a room with low oxygen, you’ll take 4 damage. "
                 "Look out for subtle hints about air quality as you approach these areas.\n\n";

    std::cout << "Treasures and Weapons:\n";
    std::cout << "- Ammo: Scattered around the spaceship, you'll find ammo for your gun or flamethrower. "
                 "Pick these up to stay prepared for the Alien encounter.\n";
    std::cout << "- Weapons: You'll have access to three types of weapons:\n";
    std::cout << "  * Knife: A close-range weapon with limited power.\n";
    std::cout << "  * Gun: A medium-range weapon, very effective but requires ammo.\n";
    std::cout << "  * Flamethrower: A powerful weapon that can burn the Alien if you have ammo!\n\n";

    std::cout << "Obstacles:\n";
    std::cout << "- Survivors: Your crew members have gone insane and will drag you to a random location if encountered. "
                 "If you hear footsteps, a Survivor may be nearby.\n\n";

    std::cout << "Good luck, and may you survive the dangers of the spaceship!\n\n";
}

char GameController::printControlPrompt() {
    char input;
    cout << "Action: N)orth, S)outh, E)ast, W)est, F)ire, H)elp, Q)uit: ";
    cin >> input;
    cout << endl;
    return input;
}


// -------------------------------------------------------- //
// Game control functions

void GameController::start(const std::vector<std::vector<char>>& mapBuilder) {
    std::cout << "Welcome to the Spaceship Survival Game!\n\n";
    printGameDescription();

    currMap = buildMap(mapBuilder);

    Room* room = currMap[0][3];
    Person* player = room->getPerson();
    bool gameOver = false;

    while (!gameOver) {
        // If in debug mode, print the map
        printCurrMap();

        // Player and object interact together
        room->interact();
        // If the interaction kills the player, game over
        gameOver = checkGameOver(player);
        if (gameOver) {
            cout << "You were tragically killed! Game Over!" << endl;
            break;
        }

        // Print hints from neighboring rooms
        printRoomHints(room);

        char choice = printControlPrompt();;
        switch (choice) {
            case 'w': {
                if (room->getLeft() != nullptr) {
                    player->setRoom(room->getLeft());
                    room->getLeft()->setPerson(player);
                    room->setPerson(nullptr);
                    room = room->getLeft();
                }
                break;
            }
            case 'e': {
                if (room->getRight() != nullptr) {
                    player->setRoom(room->getRight());
                    room->getRight()->setPerson(player);
                    room->setPerson(nullptr);
                    room = room->getRight();
                }
                break;
            }
            case 'n': {
                if (room->getUp() != nullptr) {
                    player->setRoom(room->getUp());
                    room->getUp()->setPerson(player);
                    room->setPerson(nullptr);
                    room = room->getUp();
                }
                break;
            }
            case 's': {
                if (room->getDown() != nullptr) {
                    player->setRoom(room->getDown());
                    room->getDown()->setPerson(player);
                    room->setPerson(nullptr);
                    room = room->getDown();
                }
                break;
            }
            case 'f' : {
                if (player->attack()) {
                    cout << "Congratulations! You killed the alien!" << endl;
                    gameOver = true;
                }
                break;
            }
            case 'h' : {
                printGameDescription();
                break;
            }
            case 'd' : {
                cout << "toggling debug mode" << endl;
                 debugMode = !debugMode;
                break;
            }
            case 'q': {
                gameOver = true;
                break;
            }
            default: break;
        }
    }

    // Delete the map once the game ends
    deconstructMap();
}

bool GameController::checkGameOver(const Person* p) {
    if (p->getHealth() <= 0) {
        return true;
    }
    return false;
}

void GameController::deconstructMap() {
    for (auto& row : currMap) {
        for (auto& element : row) {
            delete element;
            element = nullptr;
        }
    }
}

