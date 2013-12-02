#include "ImgObject.h"


ImgObject::ImgObject(String _path,int _value, bool _front)
{
	path = _path;
	value = _value;
	front = _front;
	readImage();
	detectKeyPoint();
	//filterImg();
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

void ImgObject::filterImg(){
	if(front){
		vector<KeyPoint> aux;
		switch(value){
		case 5:
			

			for(int i = 0; i < keypoints.size(); i++){
				if((keypoints[i].pt.x >= 5 && keypoints[i].pt.y >= 100 && keypoints[i].pt.x <= 80 && keypoints[i].pt.y <= 135 ) || 
					(keypoints[i].pt.x >= 5 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 35 && keypoints[i].pt.y <= 25 ) ||
					(keypoints[i].pt.x >= 170 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 230 && keypoints[i].pt.y <= 70 ) ||
					(keypoints[i].pt.x >= 170 && keypoints[i].pt.y >= 90 && keypoints[i].pt.x <= 240 && keypoints[i].pt.y <= 120 ) ||
					(keypoints[i].pt.x >= 30 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 70 && keypoints[i].pt.y <= 50 )){
						aux.push_back(keypoints[i]);
				}
			}
			keypoints = aux;
			break;
		case 10:

			for(int i = 0; i < keypoints.size(); i++){
				if((keypoints[i].pt.x >= 0 && keypoints[i].pt.y >= 100 && keypoints[i].pt.x <= 90 && keypoints[i].pt.y <= 135 ) || 
					(keypoints[i].pt.x >= 160 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 230 && keypoints[i].pt.y <= 60 ) ||
					(keypoints[i].pt.x >= 120 && keypoints[i].pt.y >= 80 && keypoints[i].pt.x <= 180 && keypoints[i].pt.y <= 130 ) ||
					(keypoints[i].pt.x >= 180 && keypoints[i].pt.y >= 85 && keypoints[i].pt.x <= 220 && keypoints[i].pt.y <= 110 ) ||
					(keypoints[i].pt.x >= 20 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 70 && keypoints[i].pt.y <= 50 )){
						aux.push_back(keypoints[i]);
				}
			}
			keypoints = aux;
			break;

		case 20:
			for(int i = 0; i < keypoints.size(); i++){
				if((keypoints[i].pt.x >= 0 && keypoints[i].pt.y >= 100 && keypoints[i].pt.x <= 90 && keypoints[i].pt.y <= 135 ) || 
					(keypoints[i].pt.x >= 140 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 220 && keypoints[i].pt.y <= 50 ) ||
					(keypoints[i].pt.x >= 120 && keypoints[i].pt.y >= 60 && keypoints[i].pt.x <= 155 && keypoints[i].pt.y <= 95 ) ||
					(keypoints[i].pt.x >= 5 && keypoints[i].pt.y >= 0 && keypoints[i].pt.x <= 65 && keypoints[i].pt.y <= 40 )){
						aux.push_back(keypoints[i]);
				}
			}
			keypoints = aux;
			break;

		case 50:
			for(int i = 0; i < keypoints.size(); i++){
				if((keypoints[i].pt.x >= 10 && keypoints[i].pt.y >= 10 && keypoints[i].pt.x <= 60 && keypoints[i].pt.y <= 40 ) || 
					(keypoints[i].pt.x >= 10 && keypoints[i].pt.y >= 100 && keypoints[i].pt.x <= 65 && keypoints[i].pt.y <= 125 ) ||
					(keypoints[i].pt.x >= 200 && keypoints[i].pt.y >= 70 && keypoints[i].pt.x <= 260 && keypoints[i].pt.y <= 110 ) ||
					(keypoints[i].pt.x >= 130 && keypoints[i].pt.y >= 40 && keypoints[i].pt.x <= 160 && keypoints[i].pt.y <= 70) ||
					(keypoints[i].pt.x >= 160 && keypoints[i].pt.y >= 0 && keypoints[i].pt.x <= 200 && keypoints[i].pt.y <= 50)
					){
						aux.push_back(keypoints[i]);
				}
			}
			keypoints = aux;
			break;
		}
	}else{
		vector<KeyPoint> aux;
		switch(value){
		case 5:
			for(int i = 0; i < keypoints.size(); i++){
				if((keypoints[i].pt.x >= 235 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 250 && keypoints[i].pt.y <= 30 ) || 
					(keypoints[i].pt.x >= 10 && keypoints[i].pt.y >= 100 && keypoints[i].pt.x <= 60 && keypoints[i].pt.y <= 125 ) ||
					(keypoints[i].pt.x >= 10 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 30 && keypoints[i].pt.y <= 25 ) ||
					(keypoints[i].pt.x >= 30 && keypoints[i].pt.y >= 20 && keypoints[i].pt.x <= 140 && keypoints[i].pt.y <= 80 ) ||
					(keypoints[i].pt.x >= 210 && keypoints[i].pt.y >= 100 && keypoints[i].pt.x <= 255 && keypoints[i].pt.y <= 125 )){
						aux.push_back(keypoints[i]);
				}
			}
			keypoints = aux;
			break;
		}

	}
}