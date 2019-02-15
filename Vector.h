#include "Planet.h"
#ifndef HEADERH_NB
#define HEADERH_NB

class Vector {
	public:
		Planet ** planets;
		unsigned s;
		Vector();
		Vector(int);
		~Vector();
		void insert(int, Planet *);
		Planet * read(int);
		bool remove(int);
		unsigned size();
};

#endif
