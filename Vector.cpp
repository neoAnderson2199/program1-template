#include "Vector.h"
#include <cstdlib>

Vector::Vector(int elements) {
	planets = new Planets*[elements];
}

Vector::~Vector() {
	delete[] planets;
}

void insert(int index, Planet * p) {
	Planet ** old_planets;
	if (index < 0) return;
	if (index >= size()) {
		int temp = size();
		old_planets = planets;
		planets = new Planets*[index + 1];
		for (int i = 0; i < temp; i++) {
			planets[i] = old_planets[i];
		}
		delete[] old_planets;
		for (int i = size(); i < index; i++) planets[i] = NULL;
		planets[i] = p;
	}
	else {
		old_planets = planets;
		planets = new Planets*[size() + 1];
		for (int i = 0; i < index; i++) {
			planets[i] = old_planets[i];
		}
		planets[index] = p;
		for (int i = index+1; i < size(); i++) {
			planets[i] = old_planets[i-1];
		}
		delete old_planets;
	}
}

Planet * Vector::read(int index) {
	if (index < 0 || index > size()-1) return NULL;
	else return planets[index];
}

/**NEEDS SOME FIXING!!!!!!!!!!!**/
bool Vector::remove(int index) {
	if (index < 0 || index > size()-1) return false;
	else return true;

/**ALSO NEEDS SOME FIXING**/
unsigned Vector::size() {
	unsigned count = 0;
	return count;
}
