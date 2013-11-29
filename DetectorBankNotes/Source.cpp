#include "Detector.h"

using namespace cv;

/** @function main */
int main( int argc, char** argv )
{
	Detector det = Detector("depositphotos_3928452-Money-euro.jpg");
	while(true){
	det.getMatches_FLANN();
	det.getCorners();

	det.createImage();

	char s = waitKey(0);
	if(s=='a')
		break;
	det.removeGoodMatches();
	}
	return 0;
}