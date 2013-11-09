#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#ifndef __APPLE__
#include <GL/gl.h>
#include <GL/glut.h>
#else
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#endif

#include "RGBpixmap.h"

#pragma once


enum state {WAIT, MOVE_1, MOVE_2, ROTATION, FINISH};
//static int turnCard = 0;
class Card
{
public:
	Card(int s, int n);
	~Card(void);
private: 
	int  imageNum;
	int score;

public:
	const static int Card::n_iterations = 100; 
	const static int Card::comp = 50;
	//const static int Card::per_it = 20;
	const static int Card::x_init = -30;
	const static int Card::deltaRot_y = 6;
	float x;
	float y;
	float z;
	state st;
	int it;
	int per_it;
	float rot_y;
	bool turnCard;

	float delta_x;
	float delta_y;
	float delta_z;

	int getScore();
	int getImageNum();
	void setScore(int s);
	void setImageNum(int n);
	void drawCard(float comp);
	void setState();
	void initCard_1(double _x, double _y, double _z, int n_finish);
	void initCard_2(int n_finish);
};

