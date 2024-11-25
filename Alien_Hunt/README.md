# Spaceship Survival Game  

Welcome to the **Spaceship Survival Game**! This project is an interactive, text-based adventure game where players navigate through a perilous spaceship, encounter dangerous hazards, and battle an alien lurking in its corridors.

---

## **Game Overview**  

Your mission is to survive and eliminate the Alien before it gets to you. But beware—the spaceship is filled with deadly hazards, insane survivors, and hidden treasures that will either help or hinder your journey.

### **Core Features**  
- **Dynamic Map**: Navigate through a grid-based spaceship with interconnected rooms.
- **Hazards and Obstacles**:
  - **Alien**: Encountering it without preparation means game over.
  - **Exposed Wires and Low Oxygen Rooms**: These can deal 5 and 4 damage respectively.
  - **Survivors**: They teleport you to random locations.
- **Weapons**:
  - **Knife**: Close-range, always available.
  - **Gun**: Medium-range, effective but requires ammo.
  - **Flamethrower**: Long-range and powerful but consumes ammo.
- **Clues and Hints**: Each hazard provides subtle clues about its proximity.

---

## **How to Play**  

### **Controls**  
- `w` - Move West  
- `e` - Move East  
- `n` - Move North  
- `s` - Move South  
- `f` - Attack (Use your equipped weapon)  
- `h` - Display How to Play instructions  
- `q` - Quit the game
- `d` - Debugging mode

### **Hints for Hazards**  
- **"You hear a grotesque screeching nearby...."** - An Alien is nearby.  
- **"You hear sparks nearby."** - Exposed wires in the adjacent room.  
- **"You hear air leaking out nearby."** - Low oxygen detected nearby.  
- **"You hear distant screeching...."** - A Survivor is nearby and may relocate you.

---

## **Design Structure**
- **Object-Oriented Design**: This program separates game elements into objects, each with their own distinct role.
- **Entity Interface**: All non-player game entities are programmed to fit the Entity interface, allowing for entities to be created and manipulated dynamically throughout runtime.
- **Null Object Pattern**: This game makes use of the Null Object pattern in place of null pointers for objects of type Entity. This allows for simplified and scalable logic throughout the program.
- **Game Controller Class**: The core logic that enables objects to interact with one another is all stored in the GameController class. This class implements just one public-facing method: start. This method takes in a map layout and handles the rest of the games interactions in the background. This approach ensures that the main program remains clean and easy to build upon. It also allows for easy custom-map creation on the users end.
- **Room Traversal Logic**: Due to the requirements of the project, rooms are traversed via accessing internal pointers to adjacent rooms. The GameController class has a backing 2D Vector that's used for map construction and destruction, but is not used for traversal or interaction logic.

---

## **Setup and Installation**  

### **Prerequisites**  
- **C++ Compiler**: Ensure you have a C++17 compatible compiler (e.g., GCC, Clang, MSVC).  
- **Development Environment**: Recommended to use CLion, Visual Studio, or any preferred IDE.  

### **Clone the Repository**  
1. Open your terminal and run:  
   ```bash
   git clone https://github.com/Victor-Barbulescu04/Proc-OO-C-Assignments
2. Open the Alien_Hunt directory, download its contents, and enjoy!
