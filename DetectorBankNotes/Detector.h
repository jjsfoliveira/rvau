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

	vector<ImgObject> objects;

	vector<vector<Point2f>> corners;

	void getMatches_FLANN(int i);
	bool getCorners(int i);
	void removeGoodMatches();
	void createImage(int i);
	
private:
	string path;
	void readImage();
	void detectKeyPoint();
	void loadObjects();
};

