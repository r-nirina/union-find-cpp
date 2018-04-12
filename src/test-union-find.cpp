#include "union-find.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int main () {

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator = default_random_engine(seed);
    uniform_int_distribution<int> int_distribution(-20, 20);

	// vector<int> to_disjoin = { -1, 10, -3, 0, 2, 5, 8, 0, -5 };
	vector<int> to_disjoin;
	unsigned int n = 100 - int_distribution(generator);
	for (unsigned int i = 0; i < n; ++i) {
		to_disjoin.push_back(int_distribution(generator));
	}
	cout << "Partitioning following " << n << " values into 3 disjoint sets (negative, null, and positive values) :" << endl;
	for (unsigned int i = 0; i < to_disjoin.size(); ++i) {
		cout << "	" << to_disjoin[i];
		if ((i % 20) + 1 == 20) cout << endl;
	}
	cout << endl << endl;

	UnionFind uf(to_disjoin.size());
	// Joining negative, null and positive numbers together
	for (unsigned int i = 0; i < to_disjoin.size(); ++i) {
		for (unsigned int j = i; j < to_disjoin.size(); ++j) {
			bool under_0 = to_disjoin[i] < 0 && to_disjoin[j] < 0;
			bool equal_0 = to_disjoin[i] == 0 && to_disjoin[j] == 0;
			bool over_0 = to_disjoin[i] > 0 && to_disjoin[j] > 0;
			if (under_0 || equal_0 || over_0) {
				uf.Union(i, j);
			}
		}
	}
	// uf.print();

	vector<vector<int>> disjoint_sets = uf.fetch_sets();
	char s = 'a';
	for (unsigned int i = 0; i < disjoint_sets.size(); ++i) {
		cout << "set(" << s << ")	--->	{  ";
		for (unsigned int j = 0; j < disjoint_sets[i].size(); ++j) {
			cout << to_disjoin[disjoint_sets[i][j]] << "  ";
		}
		cout << "}" << endl;
		s++;
	}

	return 0;

}