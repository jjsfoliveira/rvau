#include "Detector.h"

using namespace cv;

/** @function main */
int main( int argc, char** argv )
{
	Detector det = Detector("5-euro-banknote-320c2f.jpg");
	int i = 0;
	while(true){
	det.getMatches_FLANN(i);
	det.getCorners(i);

	det.createImage(i);

	char s = waitKey(0);
	if(s=='a')
		break;
	else if(s == 's')
		i++;
	else
		det.removeGoodMatches();
	}
	return 0;
}