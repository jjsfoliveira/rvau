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

#include <AR/arMulti.h>
#include <AR/gsub.h>
#include <AR/video.h>
#include <AR/param.h>
#include <AR/ar.h>
//#include "RGBpixmap.h"
#include "BlackJack.h"



//
// Camera configuration.
//
#ifdef _WIN32
char			*vconf = "Data\\WDM_camera_flipV.xml";
#else
char			*vconf = "";
#endif

int             xsize, ysize;
int             thresh = 100;
int             _count = 0;

char           *cparam_name    = "Data/camera_para.dat";
ARParam         cparam;

int temp = 20;

//Pattern patt = Pattern("Data/patt.hiro", 80.0, 0.0,0.0);


RGBpixmap pixmap;

static void   init(void);
static void   cleanup(void);
static void   keyEvent( unsigned char key, int x, int y);
static void   mainLoop(void);
static void   draw(int i);

BlackJack blackjack;


void myTransformations(int dummy){
	int j = 0;
	for(int i = 0; i< blackjack.packDiller.size(); i++){
		switch(blackjack.packDiller[i].st){
		case WAIT:
			break;
		case MOVE_1:
			if(blackjack.packDiller[i].it > Card::n_iterations*(1-(float)(Card::per_it/100.0))){
				blackjack.packDiller[i].it--;
				blackjack.packDiller[i].x = blackjack.packDiller[i].x -blackjack.packDiller[i].delta_x;
				break;
			}else{
				blackjack.packDiller[i].initCard_2(j);
				break;
			}
		case MOVE_2:
			blackjack.packDiller[i].it--;
			if(blackjack.packDiller[i].it <= 0){
				blackjack.packDiller[i].st = FINISH;
				blackjack.packDiller[i].x = Card::x_init+((Card::comp+5)*j);
				blackjack.packDiller[i].y = 0;
				blackjack.packDiller[i].z = 0;
				if(i == 0 && blackjack.packDiller.size() == 2){
					vector<double> r;
					r = blackjack.posDiferPatterns(0, 1);
					double rx = r[0];
					double ry = r[1];
					double rz = r[2];
					blackjack.packDiller[1].initCard_1(rx, ry, rz);
				}else if(i == 1 && blackjack.packPlayer.size() != 0){
					vector<double> r;
					r = blackjack.posDiferPatterns(3, 1);
					double rx = r[0];
					double ry = r[1];
					double rz = r[2];
					blackjack.packPlayer[0].initCard_1(rx, ry, rz);
				}
				break;
			}
			blackjack.packDiller[i].x = blackjack.packDiller[i].x -blackjack.packDiller[i].delta_x;
			blackjack.packDiller[i].y =blackjack.packDiller[i].y - blackjack.packDiller[i].delta_y;
			blackjack.packDiller[i].z =blackjack.packDiller[i].z - blackjack.packDiller[i].delta_z;
		case FINISH:

			j++;
			break;
		}
	}


	j = 0;
	for(int i = 0; i< blackjack.packPlayer.size(); i++){
		switch(blackjack.packPlayer[i].st){
		case WAIT:
			break;
		case MOVE_1:
			if(blackjack.packPlayer[i].it > Card::n_iterations*(1-(float)(Card::per_it/100.0))){
				blackjack.packPlayer[i].it--;
				blackjack.packPlayer[i].x = blackjack.packPlayer[i].x -blackjack.packPlayer[i].delta_x;
				break;
			}else{
				blackjack.packPlayer[i].initCard_2(j);
				break;
			}
		case MOVE_2:
			blackjack.packPlayer[i].it--;
			if(blackjack.packPlayer[i].it <= 0){
				blackjack.packPlayer[i].st = FINISH;
				blackjack.packPlayer[i].x = Card::x_init+((Card::comp+5)*j);
				blackjack.packPlayer[i].y = 0;
				blackjack.packPlayer[i].z = 0;
				if(i == 0 && blackjack.packPlayer.size() == 2){
					vector<double> r;
					r = blackjack.posDiferPatterns(3, 1);
					double rx = r[0];
					double ry = r[1];
					double rz = r[2];
					blackjack.packPlayer[1].initCard_1(rx, ry, rz);
				}
				break;
			}
			blackjack.packPlayer[i].x = blackjack.packPlayer[i].x -blackjack.packPlayer[i].delta_x;
			blackjack.packPlayer[i].y =blackjack.packPlayer[i].y - blackjack.packPlayer[i].delta_y;
			blackjack.packPlayer[i].z =blackjack.packPlayer[i].z - blackjack.packPlayer[i].delta_z;
		case FINISH:

			j++;
			break;
		}
	}

	glutTimerFunc(temp, myTransformations, 0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	init();
	
    arVideoCapStart();
	glutTimerFunc(temp, myTransformations, 0);
    argMainLoop( NULL, keyEvent, mainLoop );
	return (0);
}

static void   keyEvent( unsigned char key, int x, int y)
{
    /* quit if the ESC key is pressed */
    if( key == 0x1b ) {
       /* printf("*** %f (frame/sec)\n", (double)_count/arUtilTimer());
        cleanup();
        exit(0);*/
		blackjack.initGame();
    }else if(key == GLUT_KEY_F1){
		blackjack.initGame();
	}
}

/* main loop */
static void mainLoop(void)
{
    ARUint8         *dataPtr;
    ARMarkerInfo    *marker_info;
    int             marker_num;
    int             j, k;
	double          err;

    /* grab a vide frame */
    if( (dataPtr = (ARUint8 *)arVideoGetImage()) == NULL ) {
        arUtilSleep(2);
        return;
    }
    if( _count == 0 ) arUtilTimerReset();
    _count++;

    argDrawMode2D();
    argDispImage( dataPtr, 0,0 );

    /* detect the markers in the video frame */
    if( arDetectMarker(dataPtr, thresh, &marker_info, &marker_num) < 0 ) {
        cleanup();
        exit(0);
    }

    arVideoCapNext();

	if( (err=arMultiGetTransMat(marker_info, marker_num, blackjack.config)) >= 0 && err <100 ) {
		draw(2);
	}

	for(int i = 0; i < blackjack.getPatts().size(); i++){
		 /* check for object visibility */
		k = -1;
		for( j = 0; j < marker_num; j++ ) {
			if( blackjack.getPatts()[i].id == marker_info[j].id ) {
				if( k == -1 ) k = j;
				else if( marker_info[k].cf < marker_info[j].cf ) k = j;
			}
		}
		if( k == -1 ) {
			//argSwapBuffers();
			continue;
		}

		/* get the transformation between the marker and the real camera */
		arGetTransMat(&marker_info[k], blackjack.getPatts()[i].center, blackjack.getPatts()[i].width, blackjack.getPatts()[i].trans);

		 draw(i);
	}
 

    argSwapBuffers();


}

static void init( void )
{
    ARParam  wparam;


	
    /* open the video path */
    if( arVideoOpen( vconf ) < 0 ) exit(0);
    /* find the size of the window */
    if( arVideoInqSize(&xsize, &ysize) < 0 ) exit(0);
    printf("Image size (x,y) = (%d,%d)\n", xsize, ysize);

    /* set the initial camera parameters */
    if( arParamLoad(cparam_name, 1, &wparam) < 0 ) {
        printf("Camera parameter load error !!\n");
        exit(0);
    }

	
    arParamChangeSize( &wparam, xsize, ysize, &cparam );
    arInitCparam( &cparam );
    printf("*** Camera Parameter ***\n");
    arParamDisp( &cparam );

	for(int i = 0; i < blackjack.getPatts().size(); i++){
		if(blackjack.getPatts()[i].type=="simple")
		{
			int id;
			char *name = blackjack.getPatts()[i].name;
			if( (id = arLoadPatt(name)) < 0 ) {
				printf("pattern load error !!\n");
				exit(0);
			}
			blackjack.getPatts()[i].id = id;
		}
		else
		{
			if( (blackjack.config = arMultiReadConfigFile(blackjack.getPatts()[i].name)) == NULL ) {
				printf("config data load error !!\n");
				exit(0);
			}
		}
	}

    /* open the graphics window */
    argInit( &cparam, 1.0, 0, 0, 0, 0 );

	/*
	pixmap.readBMPFile("cards/2_of_clubs.bmp");
	pixmap.setTexture(3);
	*/


	//load cards

	blackjack.loadCards();
	//blackjack.initGame();



}

/* cleanup function called when program exits */
static void cleanup(void)
{
    arVideoCapStop();
    arVideoClose();
    argCleanup();
}

static void draw(int i )
{
		//printf("draw!!!!");
	//glCullFace(GL_FRONT);
    double    gl_para[16];
    GLfloat   mat_ambient[]     = {1.0, 1.0, 1.0, 1.0};
    GLfloat   mat_flash[]       = {1.0, 1.0, 1.0, 1.0};
    GLfloat   mat_flash_shiny[] = {50.0};
    GLfloat   light_position[]  = {100.0,-200.0,200.0,0.0};
    GLfloat   ambi[]            = {0.7, 0.7, 0.7, 0.1};
    GLfloat   lightZeroColor[]  = {1.0, 1.0, 1.0, 0.1};


    argDrawMode3D();
    argDraw3dCamera( 0, 0 );
    glClearDepth( 1.0 );
    glClear(GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);


    
    /* load the camera transformation matrix */
	argConvGlpara(blackjack.getPatts()[i].trans, gl_para);
  
	glMatrixMode(GL_MODELVIEW);
    glLoadMatrixd( gl_para );

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambi);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightZeroColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_flash);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_flash_shiny);	
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMatrixMode(GL_MODELVIEW);
/*
	double *r;
	r = blackjack.posDiferPatterns(0, 1);
	*/
    
	switch(i){
	case 0:
		blackjack.drawPackDiller();
		break;
	case 1:
		blackjack.drawDispenser();
		break;
	case 2:
		blackjack.drawButton();
		break;
	case 3:
		blackjack.drawPackPlayer();
		break;
	}


	
    glDisable( GL_LIGHTING );

    glDisable( GL_DEPTH_TEST );
}


