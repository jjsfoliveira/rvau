#include <stdio.h>
#include <stdlib.h>

#pragma once
class Pattern
{
public:
	Pattern(char *_name, double _width, double _center1, double _center2);
	~Pattern(void);
	char           *name;
	int             id;
	double          width;
	double          center[2];
	double          trans[3][4];

	void setTrans(double c[3][4]);


private:

};

