#include "Vector.h"
#include <cstdlib>

Vector::Vector(){
	planets = NULL;
	s = 0;
}
Vector::Vector(int elements) {
	planets = new Planet*[elements];
	s = 0;
}

Vector::~Vector() {
	for(unsigned i = 0; i < s; i++) {
		delete planets[i];
	}
	delete[] planets;
}

void Vector::insert(int index, Planet * p) {
	Planet ** old_planets;
	if(index < 0) return;
	old_planets = planets;
	if((unsigned)index >= s) {
		planets = new Planet*[index + 1];
		for(unsigned i = 0; i < s; i++) {
			planets[i] = old_planets[i];
		}
		for(unsigned i = s; i < (unsigned)index; i++){
			planets[i] = NULL;
		}
		planets[index] = p;
		s = (unsigned)index + 1;
	}else {
		planets = new Planet*[s + 1];
		for(int i = 0; i < index; i++) {
			planets[i] = old_planets[i];
		}
		planets[index] = p;
		for(unsigned i = (unsigned)(index+1); i < s+1; i++) {
			planets[i] = old_planets[i-1];
		}
		s++;
	}
	delete[] old_planets;
	old_planets = NULL;
}

Planet* Vector::read(int index) {
	if(index < 0) return NULL;
	if((unsigned)index >= s) return NULL;
	else return planets[index];
}

/**NEEDS SOME FIXING!!!!!!!!!!!**/
bool Vector::remove(int index) {
	if(index < 0) return false;
	if((unsigned)index >= s) {
		return false;
	}else {
		delete planets[index];
		for(unsigned i = (unsigned)index; i < s-1; i ++) planets[i] = planets[i+1]; 
		s--;
		return true;
	}
}

/**ALSO NEEDS SOME FIXING**/
unsigned Vector::size() {
	return s;
}
