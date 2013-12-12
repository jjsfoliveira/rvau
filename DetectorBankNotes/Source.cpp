#include "Detector.h"

using namespace cv;

/** @function main */
int main( int argc, char** argv )
{
	Detector det = Detector("all.png");
	int i = 0;
	while(i < det.objects.size()){
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
	char s = waitKey(0);
	return 0;
}