#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include <opencv/highgui.h>
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

class ImgObject
{
public:
	Mat object;
	vector<KeyPoint> keypoints;
	int value;
	bool front;
	

	ImgObject(String _path, int _value,bool _front);
	ImgObject();
	~ImgObject(void);

private: 
	string path;
	void readImage();
	void detectKeyPoint();
	void filterImg();
};

