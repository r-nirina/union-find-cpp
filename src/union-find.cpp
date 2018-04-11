#include "union-find.hpp"

UnionFind::UnionFind(int n) :
set_count(0) {
	for (unsigned int i = 0; i < n; i++) {
		MakeSet();
	}
}

UnionFind::~UnionFind() {
	clear();
}

int UnionFind::MakeSet() {
	int id = num_elements();
	elements.push_back(new EquivalenceClass(id));
	set_count++;
	return id;
}

unsigned int UnionFind::num_elements() const {
	return elements.size();
}

unsigned int UnionFind::num_sets() const {
	return set_count;
}

/* ------------ private ------------- */

void UnionFind::clear() {
	for (unsigned int i = 0; i < elements.size(); ++i)  {
		delete elements[i];
	}
	elements.clear();
	set_count = 0;
}