#include "uf-node.hpp"

UFNode::UFNode(unsigned int id) :
class_id(id),
rank(0),
parent(this) {}

int UFNode::Find() {
    int rep = parent->class_id;
    if (rep != class_id) {
        rep = parent->Find();
        parent = parent->parent;
    }
    return rep;
}

bool UFNode::is_in_same_set(UFNode& rhs) {
    return Find() == rhs.Find();
}