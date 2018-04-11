#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include "uf-node.hpp"

#include <vector>

class UnionFind {

	public:
		UnionFind(int n = 0);
		~UnionFind();

		// Duplicates vector elements while keeping the same tree state within its content
		// Resets current instance
		UnionFind& operator=(const UnionFind& rhs);

		// Creates new UFNode and returns its class_id, which is equal to its index in the elements vector
		// Increments internal number of sets accordingly
		int MakeSet();

		// Uses path compression
		int Find(int x);

		// Union by rank
		// Returns true if x and y were joined, which means they were not in the same equivalence class before, returns false otherwise
		bool Union(int x, int y);

		unsigned int num_sets() const;
		unsigned int num_elements() const;
		bool are_in_same_set(int x, int y);
		bool are_in_same_set(std::vector<int>& ids);

	private:
		std::vector<UFNode*> elements;
		unsigned int set_count;

		// Resets everything
		void clear();

		// Calls Find on all elements, thus flattening the tree
		void compress();
		void flatten();

};

#endif