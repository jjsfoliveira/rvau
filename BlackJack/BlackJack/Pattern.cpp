#include "Pattern.h"


Pattern::Pattern(char *_name, double _width, double _center1, double _center2, string type)
{
	name = _name;
	width = _width;
	center[0] = _center1;
	center[1] = _center2;
	this->type = type;
}

void Pattern::setTrans(double c[3][4]){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
				trans[j][i] = c[j][i];
				//printf("ggg-- %f", c[j][i]);
		}
	}
}


Pattern::~Pattern(void)
{
}
