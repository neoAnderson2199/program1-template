#include "List.h"
#include "Vector.h"
#ifndef HEADER_S
#define HEADER_S

class Starlist{
private:
	List* list;
public:
	Starlist();
	~Starlist();
	long addPlanet();
	bool removePlanet(long);
	Planet* getPlanet(long);
	void orbit();
	void printStarInfo();
	unsigned int getCurrentNumPlanets();
};

class Starvector{
private:
	Vector* vector;
public:
	Starvector();
	~Starvector();
	long addPlanet();
	bool removePlanet(long);
	Planet* getPlanet(long);
	void orbit();
	void printStarInfo();
	unsigned int getCurrentNumPlanets();
};

#endif
