#include "equivalence-class.hpp"

EquivalenceClass::EquivalenceClass(unsigned int id) :
class_id(id),
rank(0),
parent(this) {}

int EquivalenceClass::Find() {
    int rep = parent->class_id;
    if (rep != class_id) {
        rep = parent->Find();
        parent = parent->parent;
    }
    return rep;
}