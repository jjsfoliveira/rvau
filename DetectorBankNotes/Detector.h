#include "ImgObject.h"


#pragma once
class Detector
{
public:
	Detector(string _path);
	~Detector(void);

	Mat scene;
	vector<KeyPoint> keypoints;
	vector<DMatch> goodMatches;
	Mat image;

	ImgObject object;

	vector<Point2f> corners;

	void getMatches_FLANN();
	void getCorners();
	void removeGoodMatches();
	void createImage();
	
private:
	string path;
	void readImage();
	void detectKeyPoint();
	void loadObjects();
};

