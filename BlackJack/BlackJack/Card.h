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
class Card
{
public:
	Card(int s, int n);
	~Card(void);
private: 
	int  imageNum;
	int score;

public:
	
	float x;
	float y;
	bool move;
	

	int getScore();
	int getImageNum();
	void setScore(int s);
	void setImageNum(int n);
	void drawCard(float comp);
};

