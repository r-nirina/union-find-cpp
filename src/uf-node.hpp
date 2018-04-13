#ifndef UF_NODE_HPP
#define UF_NODE_HPP

class UFNode {

	public:
		UFNode(unsigned int id);

		int Find();

		bool is_in_same_set(UFNode& rhs);

		int class_id;
		int rank;
		UFNode* parent;

};

#endif