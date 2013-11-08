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
	
	glPushMatrix();
	
	glTranslated(comp/2, 0, -2.5);
	glRotated(180,0.0,1.0,0.0);
	glTranslated(-comp/2, 0, 0);

	glBindTexture(GL_TEXTURE_2D, 55);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0); 
		glTexCoord2f(0.0,0.0);glVertex3d(0, 0, -1);
		glTexCoord2f(1.0,0.0);glVertex3d(comp, 0,  -1);
		glTexCoord2f(1.0,1.0);glVertex3d( comp, (comp * 363)/250, -1);
		glTexCoord2f(0.0,1.0);glVertex3d( 0, (comp * 363)/250, -1);
	glEnd();
	glPopMatrix();
	

	glDisable(GL_TEXTURE_2D);
}

void Card::setState(){
	switch(st){
	case WAIT: 
		//st = MOVE;
		return;
	case MOVE_1:
		st = FINISH;
		return;
	case FINISH:
		return;
	}
}

void Card::initCard_1(double _x, double _y, double _z){
	
	x = _x;
	y= _y;
	z= _z;
	st = MOVE_1;
	
	delta_x = (3*comp)/(n_iterations*(float)(Card::per_it/100.0));
	//delta_x = (3*comp)/(20);
}

void Card::initCard_2(int n_finish){
	st = MOVE_2;
	float a = (float)x_init+((Card::comp+5)*n_finish);
	float aux;
	if(a < 0){
		aux = x - (float)x_init+((Card::comp+5)*n_finish);
	}else {
		aux = x + (float)x_init+((Card::comp+5)*n_finish);
	}
	delta_x = aux/it;
	delta_y = y/it;
	delta_z = z/it;
}