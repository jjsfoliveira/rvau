#include "Detector.h"

using namespace cv;

/** @function main */
int main( int argc, char** argv )
{ 
	String mode[14][3] = {{"FAST","SURF","FlannBased"},
							{"SURF","SURF","FlannBased"},
							{"FAST","SIFT","FlannBased"},
							{"SIFT","SIFT","FlannBased"},
							{"SIFT","SURF","FlannBased"},
							{"SURF","SIFT","FlannBased"},
							{"SURF","BRIEF","FlannBased"},
							{"FAST","ORB","Bruteforce"},
							{"ORB","ORB","Bruteforce"},
							{"FAST","BRIEF","Bruteforce"},
							{"ORB","BRIEF","Bruteforce"},
							{"FAST","FREAK","Bruteforce"},
							{"SURF","FREAK","Bruteforce"},
							{"SURF","SURF","Bruteforce"}
							};
	String op;
	cout << "Feature Detectors / Decriptor Extractors / Matchers types" << endl;
	for(int i = 0; i < 14; i++){
		cout << (i+1) << " - "<< mode[i][0] << " / " << mode[i][1] << " / " << mode[i][2] << endl;
	}
	cin >> op;
	int o = atoi(op.c_str());
	o= o-1;
	Detector det;
	String imag = "scenes/scenesy20r.png";
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
		OrbFeatureDetector feature(1500);
		det = Detector(imag, feature);
	}

	int i = 0;


	while(i < det.objects.size()){
		switch (o){
		case 0:
			det.getMatches(SurfDescriptorExtractor(),FlannBasedMatcher(),i);
			break;
		case 1:
			det.getMatches(SurfDescriptorExtractor(),FlannBasedMatcher(),i);
			break;
		case 2:
			det.getMatches(SiftDescriptorExtractor(),FlannBasedMatcher(),i);
			break;
		case 3:
			det.getMatches(SiftDescriptorExtractor(),FlannBasedMatcher(),i);
			break;
		case 4:
			det.getMatches(OrbDescriptorExtractor(),BFMatcher(),i);
			break;
		case 5:
			det.getMatches(OrbDescriptorExtractor(),BFMatcher(),i);
			break;
		case 6:
			det.getMatches(BriefDescriptorExtractor(),BFMatcher(),i);
			break;
		case 7:
			det.getMatches(BriefDescriptorExtractor(),BFMatcher(),i);
			break;
		case 8:
			det.getMatches(FREAK(),BFMatcher(),i);
			break;
		case 9:
			det.getMatches(FREAK(),BFMatcher(),i);
			break;
		case 10:
			det.getMatches(SurfDescriptorExtractor(),FlannBasedMatcher(),i);
			break;
		case 11:
			det.getMatches(SiftDescriptorExtractor(),FlannBasedMatcher(),i);
			break;
		case 12:
			det.getMatches(BriefDescriptorExtractor(),FlannBasedMatcher(),i);
			break;
		case 13:
			det.getMatches(SurfDescriptorExtractor(),BFMatcher(),i);
			break;
		default:
			break;
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