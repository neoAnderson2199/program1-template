#include "Star.h"
#include <iostream>

Star::Star(){
	current_planets = 0;
	next_id = 0;
	planets = NULL;
}

Star::~Star(){
	for(int i = 0; i < current_planets; i ++){
		delete planets[i];
		planets[i] = NULL;
	}
	delete[] planets;
	planets = NULL;
}

long Star::addPlanet(){
	Planet** temp = new Planet*[current_planets + 1];
	for(int i = 0; i < current_planets; i ++){
		temp[i] = planets[i];
	}
	delete[] planets;
	planets = temp;
	temp = NULL;
	planets[current_planets] = new Planet(rand()%3001);
	current_planets ++;
	return (*planets[current_planets-1]).getID();
}

bool Star::removePlanet(long id){
	bool retVal = false;
	if(planets == NULL) return retVal;
	int p = 0;
	for(int i = 0; i < current_planets; i ++){
		if((*planets[i]).getID() == id){
			delete planets[i]; 
			p = i;
			retVal = true;
		}
	}
	if(retVal){
		Planet** temp = new Planet*[current_planets-1];
		for(int i = 0; i < p; i ++){
			temp[i] = planets[i];
		}
		for(int i = p+1; i < current_planets; i ++){
			temp[i-1] = planets[i];
		}
		delete[] planets;
		planets = temp;
		temp = NULL;
		current_planets --;
	}
	return retVal;
}

Planet* Star::getPlanet(long id){
	if(planets == NULL) return NULL;
	for(int i = 0; i < current_planets; i++){
		if((*planets[i]).getID() == id) return planets[i];
	}
	return NULL;
}

void Star::orbit(){
	for(int i = 0; i < this->current_planets; i++){
		(*planets[i]).orbit();
	}
}

void Star::printStarInfo(){
	std::cout<< "The star has " << current_planets << " planets." << std::endl;
	std::cout<< "Planets:" << std::endl;
	for(int i = 0; i < current_planets; i++){
		std::cout<< "Planet " << (*planets[i]).getType() << (*planets[i]).getID() << " is " << (*planets[i]).getDistance() <<" miles away at position " << (*planets[i]).getPos() << " around the star." << std::endl;
	}
}

	
	
	
	
	
	
	
	
	
	
	
	
	

	
