#include "Vector.h"
#include <cstdlib>

Vector::Vector(int elements) {
	planets = new Planets*[elements];
}

Vector::~Vector() {
	delete[] planets;
}

void insert(int index, Planet * p) {
	
	


