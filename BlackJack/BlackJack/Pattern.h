#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
#pragma once
class Pattern
{
public:
	Pattern(char *_name, double _width, double _center1, double _center2, string type);
	~Pattern(void);
	char           *name;
	int             id;
	double          width;
	double          center[2];
	double          trans[3][4];
	string type;
	void setTrans(double c[3][4]);


private:

};

