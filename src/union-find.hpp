#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include "equivalence-class.hpp"

#include <vector>

class UnionFind {

	public:
		UnionFind(int n = 0);
		~UnionFind();

		// Creates new EquivalenceClass and returns its class_id, which is equal to its index in the elements vector
		int MakeSet();

		unsigned int num_sets() const;
		unsigned int num_elements() const;

	private:
		std::vector<EquivalenceClass*> elements;
		unsigned int set_count;

		void clear();

};

#endif