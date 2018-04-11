#ifndef EQUIVALENCE_CLASS_HPP
#define EQUIVALENCE_CLASS_HPP

class EquivalenceClass {

	public:
		EquivalenceClass(unsigned int id);

		int Find();

		int class_id;
		int rank;
		EquivalenceClass* parent;

};

#endif