// road.h

#ifndef _road_h
#define _road_h

#include <string>

class Road;

class Vehicle {
public:
    Vehicle(Road *road_on) : _can_move{false}, road{road_on} { }
    virtual ~Vehicle() = default;

    bool can_move() const { return _can_move; }
    void reset_move_state() { _can_move = false; }

    virtual void check_can_move_from(int location) = 0;
    virtual void celebrate() = 0;
    virtual void display() = 0;
protected:
    bool _can_move;        // is vehicle in a place where it can move?
    Road *road;            // current road vehicle is on
};

class Road {
public:
    // Road constructor
    Road(std::string description);
    // Destructor that erases all vehicles on the road
    ~Road() {
        for (int i = 0; i < length; ++i) {
            delete spots[i]; // Delete each Vehicle pointer
        }
        delete[] spots; // Delete the array of pointers
    }

    void advance_one_step();
    bool is_clear() const;
    int steps_to_clear() const;
    // return true if the spot exists and is nullptr or it doesn't exist
    bool spot_is_clear(int index) const;
    void display();
private:
    int length;
    int cur_step;
    Vehicle** spots;      // array of spaces, allocated in constructor
};

// TODO: add car, taxi, eighteenwheeler classes
class Car : public Vehicle {
public:
    Car(Road *road_on) : Vehicle(road_on) { }
    ~Car() override = default;

    void check_can_move_from(int location) override;
    void celebrate() override;
    void display() override;
};

class Taxi : public Vehicle {
public:
    Taxi(Road *road_on) : Vehicle(road_on) { }
    ~Taxi() override = default;

    void check_can_move_from(int location) override;
    void celebrate() override;
    void display() override;
};

class EighteenWheeler : public Vehicle {
public:
    EighteenWheeler(Road *road_on) : Vehicle(road_on) { }
    ~EighteenWheeler() override = default;

    void check_can_move_from(int location) override;
    void celebrate() override;
    void display() override;
};

#endif