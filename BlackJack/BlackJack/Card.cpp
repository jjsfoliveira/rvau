#include "Card.h"


Card::Card(int s, int n)
{
	score = s;
	imageNum = n;
	st = WAIT;
	it = n_iterations;
	x,y,z,delta_x, delta_y, delta_z =0;
}


Card::~Card(void)
{
}

int Card::getScore(){
	return score;
}
int Card::getImageNum(){
	return imageNum;
}
void Card::setScore(int s){
	score = s;
}
void Card::setImageNum(int n){
	imageNum = n;
}

void Card::drawCard(float comp){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imageNum);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0); 
		glTexCoord2f(0.0,0.0);glVertex3d(0, 0, -1);
		glTexCoord2f(1.0,0.0);glVertex3d(comp, 0,  -1);
		glTexCoord2f(1.0,1.0);glVertex3d( comp, (comp * 363)/250, -1);
		glTexCoord2f(0.0,1.0);glVertex3d( 0, (comp * 363)/250, -1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Card::setState(){
	switch(st){
	case WAIT: 
		st = MOVE;
		return;
	case MOVE:
		st = FINISH;
		return;
	case FINISH:
		return;
	}
}

