#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include <opencv/highgui.h>
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;

class ImgObject
{
public:
	Mat object;
	vector<KeyPoint> keypoints;
	int value;
	bool front;
	

	ImgObject(string _path, int _value,bool _front,FeatureDetector & detector);
	ImgObject();
	~ImgObject(void);

private: 
	string path;
	void readImage();
	void detectKeyPoint(FeatureDetector & detector);
	void filterImg();
};

