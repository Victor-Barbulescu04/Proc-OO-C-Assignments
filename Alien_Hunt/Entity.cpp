// Authors: Victor Barbulescu & Vamsi Sudersanam
// Course : CSC 2210/001
// Date: 11/17/2024

#include "Entity.h"
// Destructor definition
Entity::~Entity() = default;

// -------------------------------------------------------- //
// Null Entity Function Definitions

NullEntity::NullEntity() = default;
NullEntity::~NullEntity() = default;

void NullEntity::interact(Person *p) {}
void NullEntity::hint() {}
char NullEntity::character() {return '.';}




