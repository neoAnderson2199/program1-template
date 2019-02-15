#include "Planet.h"
#ifndef HEADER_S
#define HEADER_S

class Star{
private:
	int current_planets;
public:
	Planet** planets;
	Star();
	~Star();
	long addPlanet();
	bool removePlanet(long);
	Planet* getPlanet(long);
	void orbit();
	void printStarInfo();
	int getCurrentNumPlanets(){return current_planets;};
};

#endif
