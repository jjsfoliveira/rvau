#include "ImgObject.h"


ImgObject::ImgObject(String _path,int _value)
{
	path = _path;
	value = _value;
	readImage();
	detectKeyPoint();
}

ImgObject::ImgObject()
{
}

ImgObject::~ImgObject(void)
{
}

void ImgObject::readImage(){
	object = imread(path, CV_LOAD_IMAGE_GRAYSCALE);
}

void ImgObject::detectKeyPoint(){
	int minHessian = 400;
	SurfFeatureDetector detector( minHessian );
	detector.detect( object, keypoints);
}
