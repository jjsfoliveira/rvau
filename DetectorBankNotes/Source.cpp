#include "Detector.h"

using namespace cv;

/** @function main */
int main( int argc, char** argv )
{

	Detector det = Detector("all.png");
	int i = 0;
	while(i < det.objects.size()){


		//det.getMatches_SIFT(i);

		det.getMatches_FLANN(i);
	
		if(det.getCorners(i)==false){
			if(i+1 == det.objects.size()){
				break;
			}else{
				i++;
			}
		
		
		}else{
			det.removeGoodMatches();
		}

		/*det.createImage(i);

		char s = waitKey(0);
		if(s=='a')
			break;
		else if(s == 's'){
			if(det.getCorners(i)!=false)
			det.removeGoodMatches();
			else
				i++;

		}
		else
			det.removeGoodMatches();*/
	}
	det.createImage(i);
	char s = waitKey(0);
	return 0;
}