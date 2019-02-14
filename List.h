#ifndef HEADER_HL
#define HEADER_HL

class Node{
public:
	Planet* data;
	Node* next, prev;
	Node();
	Node(Planet* d);
};

class List{
public:
	Node* head, tail;
	int size;
	List();
	~List();
	void insert(int index, Planet *p);
	Planet* read(int index);
	bool remove(int index);
	unsigned size();
};

#endif
