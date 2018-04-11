#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include "equivalence-class.hpp"

#include <vector>

class UnionFind {

	public:
		UnionFind(int n = 0);
		~UnionFind();

		// Duplicates vector elements while keeping the same tree state within its content
		// Resets current instance
		UnionFind& operator=(const UnionFind& rhs);

		// Creates new EquivalenceClass and returns its class_id, which is equal to its index in the elements vector
		// Increments internal number of sets accordingly
		int MakeSet();

		// Uses path compression
		int Find(int x);

		unsigned int num_sets() const;
		unsigned int num_elements() const;

	private:
		std::vector<EquivalenceClass*> elements;
		unsigned int set_count;

		// Resets everything
		void clear();

		// Calls Find on all elements, thus flattening the tree
		void compress();
		void flatten();

};

#endif