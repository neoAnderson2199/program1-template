#include "Planet.h"
#include <iostream>

Planet::Planet(int dis){
	id = dis;
	distance = dis;
	char types[] = {'h', 'r', 'g'};
	type = types[rand()%3];
    pos = rand()%360;
}

int Planet::orbit(){
	if(pos == 359){
		pos = 0;
	}else{
		pos ++;
	}
	return pos;
}
