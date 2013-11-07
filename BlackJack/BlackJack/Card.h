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


enum state {WAIT, MOVE, FINISH};

class Card
{
public:
	Card(int s, int n);
	~Card(void);
private: 
	int  imageNum;
	int score;

public:
	const static int Card::n_iterations = 200; 
	
	float x;
	float y;
	float z;
	state st;
	int it;

	float delta_x;
	float delta_y;
	float delta_z;

	int getScore();
	int getImageNum();
	void setScore(int s);
	void setImageNum(int n);
	void drawCard(float comp);
	void setState();
};

