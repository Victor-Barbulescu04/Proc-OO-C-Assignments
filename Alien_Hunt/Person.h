//
// Created by vicb2 on 11/14/2024.
//

/* Person Class
 * Responsible for managing a persons inventory, health, actions
 * and location on the spaceship
 */

#ifndef PERSON_H
#define PERSON_H

// Forward Declarations
class Weapon;
class Room;

class Person {
private:
    int health = 0;
    Weapon* weapon = nullptr;
    Room* room = nullptr;
public:
    Person(int startingHealth, Room* startingRoom);
    ~Person();

    [[nodiscard]] int getHealth() const;
    void changeHealth(int amount);

    [[nodiscard]] Weapon* getWeapon() const;
    void setWeapon(Weapon* w);

    [[nodiscard]] Room* getRoom() const;
    void setRoom(Room* r);

    [[nodiscard]] char character() const;

    [[nodiscard]] bool attack() const;
};



#endif //PERSON_H
