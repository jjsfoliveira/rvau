#include "Detector.h"

using namespace cv;

/** @function main */
int main( int argc, char** argv )
{
	Detector det = Detector("euro_notes.jpg");
	int i = 0;
	while(true){
	det.getMatches_FLANN(i);
	if(det.getCorners(i)==false)
	{
		i++;
		continue;
	}

	det.createImage(i);

	char s = waitKey(0);
	if(s=='a')
		break;
	else if(s == 's'){
		det.removeGoodMatches();
		i++;
	}
	else
		det.removeGoodMatches();
	}
	return 0;
}