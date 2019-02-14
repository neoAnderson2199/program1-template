#include "Planet.h"
#ifndef HEADER_S
#define HEADER_S

class Star{
private:
	int current_planets;
	int next_id;
public:
	Planet** planets;
	Star();
	~Star();
	int addPlanet();
	bool removePlanet(int);
	Planet* getPlanet(int);
	void orbit();
	void printStarInfo();
	int getCurrentNumPlanets(){return current_planets;};
};

#endif