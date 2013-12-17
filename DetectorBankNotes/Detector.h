#include "ImgObject.h"


#pragma once
class Detector
{
public:
	Detector(string _path, FeatureDetector & detector);
	Detector(){}
	~Detector(void);

	Mat scene;
	Mat descriptors_object;
	Mat descriptors_scene;
	vector<KeyPoint> keypoints;
	vector<DMatch> goodMatches;
	Mat image;

	vector<ImgObject> objects;

	vector<vector<Point2f>> corners;
	vector<int> values;

	
	void getDescriptor(DescriptorExtractor& extractor, int i);
	void getMatches(DescriptorMatcher& matcher, int i);
	void getMatches_SIFT(int i);
	bool getCorners(int i);
	void removeGoodMatches();
	void createImage(int i);
	
private:
	string path;
	void readImage();
	void detectKeyPoint(FeatureDetector & detector);
	void loadObjects(FeatureDetector & detector);
};

