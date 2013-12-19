#include "Detector.h"
#include <time.h>
using namespace cv;

/** @function main */
int main( int argc, char** argv )
{ 
	/*String mode[13][3] = {{"FAST","SURF","FlannBased"},
							{"SURF","SURF","FlannBased"},
							{"FAST","SIFT","FlannBased"},
							{"SIFT","SIFT","FlannBased"},
							{"SIFT","SURF","FlannBased"},
							{"SURF","SIFT","FlannBased"},
							{"FAST","ORB","Bruteforce"},
							{"ORB","ORB","Bruteforce"},
							{"FAST","BRIEF","Bruteforce"},
							{"ORB","BRIEF","Bruteforce"},
							{"FAST","FREAK","Bruteforce"},
							{"SURF","FREAK","Bruteforce"},
							{"SURF","SURF","Bruteforce"}
							};*/

	String mode[18][3] ={{"FAST","SURF","FlannBased"},
						{"FAST","SIFT","FlannBased"},
						{"SURF","SURF","FlannBased"},
						{"SURF","SIFT","FlannBased"},
						{"SIFT","SURF","FlannBased"},
						{"SIFT","SIFT","FlannBased"},

						{"FAST","SURF","Bruteforce"},
						{"FAST","SIFT","Bruteforce"},
						{"FAST","BRIEF","Bruteforce"},
						{"FAST","FREAK","Bruteforce"},
						{"SURF","SURF","Bruteforce"},
						{"SURF","SIFT","Bruteforce"},
						{"SURF","BRIEF","Bruteforce"},
						{"SURF","FREAK","Bruteforce"},
						{"SIFT","SURF","Bruteforce"},
						{"SIFT","SIFT","Bruteforce"},
						{"SIFT","BRIEF","Bruteforce"},
						{"SIFT","FREAK","Bruteforce"}
						};
	String op;
	cout << "Feature Detectors / Decriptor Extractors / Matchers types" << endl;
	for(int i = 0; i < 18 ; i++){
		cout << (i+1) << " - "<< mode[i][0] << " / " << mode[i][1] << " / " << mode[i][2] << endl;
	}
	cin >> op;
	int o = atoi(op.c_str());
	o= o-1;
	Detector det;
	String imag = "scenes/scenes.png";
	if(mode[o][0] == "FAST"){
		FastFeatureDetector feature(15);
		det = Detector(imag, feature);
	}else if(mode[o][0] == "SURF"){
		SurfFeatureDetector feature(400);
		det = Detector(imag, feature);
	}else if(mode[o][0] == "SIFT"){
		SiftFeatureDetector feature = SiftFeatureDetector();
		det = Detector(imag, feature);
	}else if(mode[o][0] == "ORB"){
		OrbFeatureDetector feature(500,1.2f,8,14,0,2,0,14);
		det = Detector(imag, feature);
	}

	int i = 0;

	time_t now;
	time(&now);

	while(i < det.objects.size()){


		if(mode[o][1] == "SURF"){
			det.getDescriptor(SurfDescriptorExtractor(), i);
		}else if(mode[o][1] == "SIFT"){
			det.getDescriptor(SiftDescriptorExtractor(), i);
		}else if(mode[o][1] == "BRIEF"){
			det.getDescriptor(BriefDescriptorExtractor(), i);
		}else if(mode[o][1] == "ORB"){
			det.getDescriptor(OrbDescriptorExtractor(), i);
		}else if(mode[o][1] == "FREAK"){
			det.getDescriptor(FREAK(), i);
		}

		if(mode[o][2] == "FlannBased"){
			det.getMatches(FlannBasedMatcher(), i);
		}else if(mode[o][2] == "Bruteforce"){
			det.getMatches(BFMatcher(), i);
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
	time_t end;
	time(&end);
	double seconds  = difftime(end, now);
	cout << "Time " << seconds << endl;
	det.createImage(i);
	char s = waitKey(0);
	return 0;
}