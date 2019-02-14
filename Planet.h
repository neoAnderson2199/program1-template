#ifndef HEADER_P
#define HEADER_P

class Planet{
private:
	int id;
	int distance;
	int pos;
	int type;
public:
	Planet(){id=-1;};
	Planet(int);
	int orbit();
	long int getID(){return id;};
	int getDistance(){return distance;};
	int getPos(){return pos;};
	char getType(){return type;};
};

#endif
