#include "Star.h"
#include <iostream>

Starlist::Starlist(){
	list = new List();
}

Starlist::~Starlist(){
	delete list;
}

long Starlist::addPlanet(){
	Planet* temp = new Planet(rand()%3001);
	list->insert(list->size(), temp);
	return temp->getID();
}

bool Starlist::removePlanet(long id){
	int temp = -1;
	for(unsigned i = 0; i < list->size(); i++){
		if((list->read(i))->getID() == id) temp = i;
	}
	return list->remove(temp);
}

Planet* Starlist::getPlanet(long id){
	int temp = -1;
	for(unsigned i = 0; i < list->size(); i++){
		if((list->read(i))->getID() == id) temp = i;
	}
	return list->read(temp);
}

void Starlist::orbit(){
	for(unsigned i = 0; i < list->size(); i++){
		(list->read(i))->orbit();
	}
}

void Starlist::printStarInfo(){
	std::cout<< "The star has " << list->size() << " planets." << std::endl;
	std::cout<< "Planets:" << std::endl;
	for(unsigned i = 0; i < list->size(); i++){
		Planet* temp = list->read(i);
		std::cout<< "Planet " << temp->getType() << temp->getID() << " is " << temp->getDistance() <<" miles away at position " << temp->getPos() << " around the star." << std::endl;
	}
}

unsigned int Starlist::getCurrentNumPlanets(){
	return list->size();
}

Starvector::Starvector(){
	vector = new Vector();
}

Starvector::~Starvector(){
	delete vector;
}

long Starvector::addPlanet(){
	Planet* temp = new Planet(rand()%3001);
	vector->insert(vector->size(), temp);
	return temp->getID();
}

bool Starvector::removePlanet(long id){
	int temp = -1;
	for(unsigned i = 0; i < vector->size(); i++){
		if((vector->read(i))->getID() == id) temp = i;
	}
	return vector->remove(temp);
}

Planet* Starvector::getPlanet(long id){
	int temp = -1;
	for(unsigned i = 0; i < vector->size(); i++){
		if((vector->read(i))->getID() == id) temp = i;
	}
	return vector->read(temp);
}

void Starvector::orbit(){
	for(unsigned i = 0; i < vector->size(); i++){
		(vector->read(i))->orbit();
	}
}

void Starvector::printStarInfo(){
	std::cout<< "The star has " << vector->size() << " planets." << std::endl;
	std::cout<< "Planets:" << std::endl;
	for(unsigned i = 0; i < vector->size(); i++){
		Planet* temp = vector->read(i);
		std::cout<< "Planet " << temp->getType() << temp->getID() << " is " << temp->getDistance() <<" miles away at position " << temp->getPos() << " around the star." << std::endl;
	}
}

unsigned int Starvector::getCurrentNumPlanets(){
	return vector->size();
}

	
	
	
	
	
	
	
	
	
	
	
	
	

	
