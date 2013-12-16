#include "Detector.h"

using namespace cv;

/** @function main */
int main( int argc, char** argv )
{
	String ext, mat;
	cout << "Press 1: SurfDescriptorExtractor" << endl << "Press 2: SiftDescriptorExtractor" << endl;
	cin >> ext;
	cout << "Press 1: FlannBasedMatcher" << endl << "Press 2: BFMatcher" << endl;
	cin >> mat;



	Detector det = Detector("scenesy50r.png");
	int i = 0;


	while(i < det.objects.size()){


		//det.getMatches_SIFT(i);
		if(ext == "1" && ext == "1"){
			det.getMatches(SurfDescriptorExtractor(),FlannBasedMatcher(),i);
		}else if(ext == "1" && ext == "2"){
			det.getMatches(SurfDescriptorExtractor(),BFMatcher(),i);
		}else if(ext == "2" && ext == "1"){
			det.getMatches(SiftDescriptorExtractor(),FlannBasedMatcher(),i);
		}else{
			det.getMatches(SiftDescriptorExtractor(),BFMatcher(),i);
		}
	
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