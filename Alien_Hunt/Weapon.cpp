//
// Created by vicb2 on 11/14/2024.
//

#include "Weapon.h"

#include <iostream>

#include "Alien.h"
#include "Person.h"
#include "Room.h"

// -------------------------------------------------------------------------------------- //
// Weapon base class implementation

// -------------------------------------------------------- //
// Constructor/destructor

Weapon::Weapon(const int ammo, const std::string &name, const int range) {
    this->ammo = ammo;
    this->name = name;
    this->range = range;
}

Weapon::~Weapon() = default;

// -------------------------------------------------------- //
// Ammo functions

int Weapon::getAmmo() const {
    return ammo;
}

void Weapon::changeAmmo(int amount) {
    this->ammo += ammo;
}

// -------------------------------------------------------- //
// Name functions

std::string Weapon::getName() const {
    return name;
}

void Weapon::setName(const std::string &name) {
    this->name = name;
}

// -------------------------------------------------------- //
// Entity function

char Weapon::character() {
    return '>';
}

// -------------------------------------------------------- //
// Helper functions

bool Weapon::checkIfHit(const Room *r) {
    if (dynamic_cast<Alien*>(r->getEntity())) {
        std::cout << "You hit the alien!" << std::endl;
        return true;
    }
    std::cout << "You missed!" << std::endl;
    return false;
}

Room *Weapon::getRoomInDirection(Room *r, char direction) {
    Room* roomInDirection = nullptr;
    switch (direction) {
        case 'n': {
            roomInDirection = r->getUp();
            break;
        }
        case 'e': {
            roomInDirection = r->getRight();
            break;
        }
        case 's': {
            roomInDirection = r->getDown();
            break;
        }
        case 'w': {
            roomInDirection = r->getLeft();
        }
        default: std::cout << "error determining direction" << std::endl;
    }

    return roomInDirection;
}

// -------------------------------------------------------------------------------------- //
// Knife derived class implementation

// -------------------------------------------------------- //
// Destructor
Knife::~Knife() = default;

// -------------------------------------------------------- //
// Entity methods

void Knife::interact(Person *p) {
    char grab;
    std::cout << "you found a knife? Grab? y/n" << std::endl;
    std::cin >> grab;

    if (grab == 'y') {
        std::cout << "you grabbed the knife on the ground!" << std::endl;
        delete p->getWeapon();
        // TODO This could be not how pointers work
        p->setWeapon(this);
    } else {
        std::cout << "you ignored the knife on the ground!" << std::endl;
    }
}

void Knife::hint() {
    std::cout << "You see the glint of a blade through a crack in the wall..." << std::endl;
}

// Since the knife has a range of 1 room, return the room passed in when Person was
// prompted to attack
bool Knife::fire(Room *r, char direction) {
    return checkIfHit(r);
}

// -------------------------------------------------------------------------------------- //
// Gun derived class implementation

// -------------------------------------------------------- //
// Destructor
Gun::~Gun() = default;

// -------------------------------------------------------- //
// Entity methods

void Gun::interact(Person *p) {
    char grab;
    std::cout << "you found a gun? Grab? y/n" << std::endl;
    std::cin >> grab;

    if (grab == 'y') {
        std::cout << "you grabbed the gun on the ground!" << std::endl;
        delete p->getWeapon();
        // TODO This could be not how pointers work
        p->setWeapon(this);
    } else {
        std::cout << "you ignored the gun on the ground!" << std::endl;
    }
}

void Gun::hint() {
    std::cout << "You see the smoking barrel of a gun through the door..." << std::endl;
}
// -------------------------------------------------------- //
// Fire method

bool Gun::fire(Room *r, char direction) {
    std::cout << "You pull the trigger of your gun!" << std::endl;
    Room* toReturn = r;

    if (r != nullptr && ammo > 0) {
        ammo--;
        // If the room adjacent to the player contains the alien, return.
        // The alien has been hit
        if (checkIfHit(toReturn)) {
            return toReturn;
        }

        // If not, let the bullet fly.
        int i = 1;
        while (i < range) {
            toReturn = getRoomInDirection(toReturn, direction);

            // If the returned room is null, the shot hit a wall
            if (toReturn == nullptr) {
                break;
            }

            // If along the flight path, the bullet hits the alien, return.
            if (checkIfHit(toReturn)) {
                return toReturn;
            }

            i++;
        }
    }

    // If the adjacent room in the direction you shot is null, you shot a wall
    // This is always a miss. Return false.
    std::cout << "You missed!" << std::endl;
    return false;
}

// -------------------------------------------------------------------------------------- //
// Flamethrower derived class implementation

// -------------------------------------------------------- //
// Destructor
Flamethrower::~Flamethrower() = default;

// -------------------------------------------------------- //
// Entity methods

void Flamethrower::interact(Person *p) {
    char grab;
    std::cout << "you found a flamethrower? Grab? y/n" << std::endl;
    std::cin >> grab;

    if (grab == 'y') {
        std::cout << "you grabbed the flamethrower on the ground!" << std::endl;
        delete p->getWeapon();
        p->setWeapon(this);
    } else {
        std::cout << "you ignored the flamethrower on the ground!" << std::endl;
    }
}

void Flamethrower::hint() {
    std::cout << "You see the flaming barrel of a flamethrower through the door..." << std::endl;
}
// -------------------------------------------------------- //
// Fire method

bool Flamethrower::fire(Room *r, char direction) {
    std::cout << "You pull the trigger of your flamethrower!" << std::endl;
    Room* toReturn = r;

    if (r != nullptr && ammo > 0) {
        ammo--;
        // If the room adjacent to the player contains the alien, return.
        // The alien has been hit
        if (checkIfHit(toReturn)) {
            return toReturn;
        }

        // If not, let the bullet fly.
        int i = 1;
        while (i < range) {
            toReturn = getRoomInDirection(toReturn, direction);

            // If the returned room is null, the shot hit a wall
            if (toReturn == nullptr) {
                break;
            }

            // If along the flight path, the bullet hits the alien, return.
            if (checkIfHit(toReturn)) {
                return toReturn;
            }

            i++;
        }
    }

    // If the adjacent room in the direction you shot is null, you shot a wall
    // This is always a miss. Return false.
    std::cout << "You missed!" << std::endl;
    return false;
}

















