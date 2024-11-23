//
// Created by vicb2 on 11/14/2024.
//

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "Entity.h"

class Room;

class Weapon : public Entity{
protected:
    std::string name;
    int ammo = 0;
    int range = 0;

    Room* getRoomInDirection(Room *r, char direction);
    bool checkIfHit(const Room* r);
public:
    Weapon(int ammo, const std::string& name, int range);
    ~Weapon() override;

    [[nodiscard]] int getAmmo() const;
    [[nodiscard]] std::string getName() const;

    void changeAmmo(int amount);
    void setName(const std::string& name);

    char character() override;

    /**
     * Fires the current weapon the player is holding
     * @param r the room adjacent to the one the shot originated from
     * @param direction the direction the shot was intended for
     * @return whether the shot hit the alien
     */
    virtual bool fire(Room *r, char direction) = 0;
};

class Knife final : public Weapon {
public:
    using Weapon::Weapon;
    ~Knife() override;

    // Interact will be called when there is the option to pick up a new weapon
    void interact(Person *p) override;
    void hint() override;

    bool fire(Room *r, char direction) override;
};

class Gun final : public Weapon {
public:
    // Calls the parents constructor
    using Weapon::Weapon;
    ~Gun() override;

    // Interact will be called when there is the option to pick up a new weapon
    void interact(Person *p) override;
    void hint() override;

    bool fire(Room *r, char direction) override;
};

class Flamethrower final : public Weapon {
public:
    // Calls the parents constructor
    using Weapon::Weapon;
    ~Flamethrower() override;

    // Interact will be called when there is the option to pick up a new weapon
    void interact(Person *p) override;
    void hint() override;

    bool fire(Room *r, char direction) override;
};



#endif //WEAPON_H
