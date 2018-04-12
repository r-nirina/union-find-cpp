#include "union-find.hpp"

UnionFind::UnionFind(int n) :
set_count(0) {
	for (int i = 0; i < n; ++i) {
		MakeSet();
	}
}

UnionFind::~UnionFind() {
	clear();
}


UnionFind& UnionFind::operator=(const UnionFind& rhs) {
	clear();
	for (unsigned int i = 0; i < rhs.num_elements(); ++i) {
		MakeSet();
	}
	for (unsigned int i = 0; i < rhs.num_elements(); ++i) {
		elements[i]->parent = elements[rhs.elements[i]->parent->class_id];
	}
	return *this;
}


int UnionFind::MakeSet() {
	int id = num_elements();
	elements.push_back(new UFNode(id));
	set_count++;
	return id;
}

int UnionFind::Find(int x) {
	return elements[x]->Find();
}

bool UnionFind::Union(int x, int y) {
	int rep_x = Find(x);
	int rep_y = Find(y);
	if (rep_x != rep_y) {
		if (elements[rep_x]->rank < elements[rep_y]->rank) {
			elements[rep_x]->parent = elements[rep_y];
		} else {
			elements[rep_y]->parent = elements[rep_x];
			if (elements[rep_x]->rank == elements[rep_y]->rank) {
				elements[rep_x]->rank++;
			}
		}
		return true; // Une union a été effectuée
	} else return false; // Les deux noeuds sont dans la même classe donc pas d'union

	set_count--;
	return false;
}


unsigned int UnionFind::num_elements() const {
	return elements.size();
}

unsigned int UnionFind::num_sets() const {
	return set_count;
}

bool UnionFind::are_in_same_set(int x, int y) {
	return elements[x]->is_in_same_set(*(elements[y]));
}

bool UnionFind::are_in_same_set(std::vector<int>& ids) {
	if (ids.empty()) return true;
	int rep = Find(ids[0]);
	for (unsigned int i = 0; i < ids.size(); ++i) {
		if (rep != Find(ids[i])) return false;
	}
	return true;
}

void UnionFind::print(std::ostream& out) {
	char s = 'a';
	std::vector<std::vector<int>> sets = fetch_sets();
	for (unsigned int i = 0; i < sets.size(); ++i) {
		if (!sets[i].empty()) {
			out << "set(" << s << ")	--->	{ ";
			for (unsigned int j = 0; j < sets[i].size(); ++j) {
				out << sets[i][j] << " ";
			}
			out << "}" << std::endl;
			s++;
		}
	}
}

std::ostream& operator<<(std::ostream& out, UnionFind& uf) {
	uf.print(out);
	return out;
}


/* ------------ private ------------- */

void UnionFind::clear() {
	for (unsigned int i = 0; i < elements.size(); ++i)  {
		delete elements[i];
	}
	if (!elements.empty()) elements.clear();
	set_count = 0;
}

void UnionFind::compress() {
	for (unsigned int i = 0; i < elements.size(); ++i) {
		Find(i);
	}
}

void UnionFind::flatten() {
	compress();
}

std::vector<std::vector<int>> UnionFind::fetch_sets(bool drop_empty_sets) {
	std::vector<std::vector<int>> sets;
	sets.resize(num_elements());
	flatten();
	for (unsigned int i = 0; i < elements.size(); ++i) {
		sets[Find(i)].push_back(i);
	}
	if (drop_empty_sets) {
		std::vector<std::vector<int>> not_empty_sets;		
		for (unsigned int i = 0; i < sets.size(); ++i) {
			if (!sets[i].empty()) not_empty_sets.push_back(sets[i]);
		}
		return not_empty_sets;
	}
	return sets;
}