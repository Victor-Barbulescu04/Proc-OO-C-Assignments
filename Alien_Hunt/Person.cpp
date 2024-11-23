//
// Created by vicb2 on 11/14/2024.
//

#include "Person.h"

#include <iostream>

#include "Room.h"
#include "Weapon.h"

// -------------------------------------------------------- //
// Constructor/destructor

Person::Person(int startingHealth, Room *startingRoom) {
    health = startingHealth;
    room = startingRoom;
}
Person::~Person() {
    delete weapon;
    weapon = nullptr;
}

// -------------------------------------------------------- //
// Health functions

int Person::getHealth() const {
    return health;
}

void Person::changeHealth(int amount) {
    health += amount;
}

// -------------------------------------------------------- //
// Weapon functions

void Person::setWeapon(Weapon *w) {
    delete weapon;
    weapon = w;
}

Weapon *Person::getWeapon() const {
    return weapon;
}

// -------------------------------------------------------- //
// Room functions

Room *Person::getRoom() const {
    return room;
}
void Person::setRoom(Room *r) {
    room = r;
}

// -------------------------------------------------------- //
// Character function

char Person::character() const {
    return '+';
}

// -------------------------------------------------------- //
// Attack function

bool Person::attack() const {
    char direction;
    std::cout << "Fire N)orth, S)outh, E)ast, W)est?";
    std::cin >> direction;
    std::cout << std::endl;

    if (direction == 'n') {
        return weapon->fire(room->getUp(), 'n');
    }
    if (direction == 'e') {
        return weapon->fire(room->getRight(), 'e');
    }
    if (direction == 's') {
        return weapon->fire(room->getDown(), 's');
    }
    if (direction == 'w') {
        return weapon->fire(room->getLeft(), 'w');
    }

    // If the input is bad, hold your fire
    std::cout << "No such direction!\n";
    return false;
}













