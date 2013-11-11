#include "Card.h"


Card::Card(int s, int n)
{
	score = s;
	imageNum = n;
	st = WAIT;
	it = n_iterations;
	x,y,z,delta_x, delta_y, delta_z =0;
	per_it = 30;
	rot_y = 180;
	rot_z = 90;
	delta_rot_z = 5;
	turnCard = true;
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
	
	glTranslated(comp/2, 0, -2.1);
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

void Card::initCard_1(double _x, double _y, double _z, int n_finish){
	
	x = _x;
	y= _y;
	z= _z;
	st = MOVE_1;

	if(_x > _y && _x > _z){
		per_it = ((float)(x_init+((Card::comp+5)*n_finish))/(_x+x_init+((Card::comp+5)*n_finish)))*100;
	}else if(_y > _x && _y > _z){
		per_it = ((float)(x_init+((Card::comp+5)*n_finish))/(_y+x_init+((Card::comp+5)*n_finish)))*100;
	}else if(_z > _x && _z > _y){
		per_it = ((float)(x_init+((Card::comp+5)*n_finish))/(_z+x_init+((Card::comp+5)*n_finish)))*100;
	}else{
		per_it = 30;
	}
	if(per_it <0){
		per_it = per_it*(-1);
	}

	//delta_rot_z = (90/(float)(per_it*n_iterations))*100;
	
	delta_x = (3*comp)/(n_iterations*(float)(per_it/100.0));
	//delta_x = (3*comp)/(20);
}

void Card::initCard_2(int n_finish){
	st = MOVE_2;
	float a = (float)x_init+((Card::comp+5)*n_finish);
	float aux;
	if(a < x){
		aux = x - a;
	}else {
		aux = -(a-x);
	}
	delta_x = aux/it;
	delta_y = y/it;
	delta_z = z/it;
}