#include "ImgObject.h"


ImgObject::ImgObject(string _path,int _value, bool _front)
{
	path = _path;
	value = _value;
	front = _front;
	readImage();
	detectKeyPoint();
	filterImg();
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
				if((keypoints[i].pt.x >= 3 && keypoints[i].pt.y >= 98 && keypoints[i].pt.x <= 30 && keypoints[i].pt.y <= 133 ) || 
					(keypoints[i].pt.x >= 2 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 28 && keypoints[i].pt.y <= 34 ) ||
					(keypoints[i].pt.x >= 125 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 227 && keypoints[i].pt.y <= 107 )){
						aux.push_back(keypoints[i]);
				}
			}
			keypoints = aux;
			break;
		case 10:

			for(int i = 0; i < keypoints.size(); i++){
				if((keypoints[i].pt.x >= 2 && keypoints[i].pt.y >= 2 && keypoints[i].pt.x <= 27 && keypoints[i].pt.y <= 28 ) || 
					(keypoints[i].pt.x >= 5 && keypoints[i].pt.y >= 100 && keypoints[i].pt.x <= 37 && keypoints[i].pt.y <= 132 ) ||
					(keypoints[i].pt.x >= 123 && keypoints[i].pt.y >= 2 && keypoints[i].pt.x <= 227 && keypoints[i].pt.y <= 129 )){
						aux.push_back(keypoints[i]);
				}
			}
			keypoints = aux;
			break;

		case 20:
			for(int i = 0; i < keypoints.size(); i++){
				if((keypoints[i].pt.x >= 2 && keypoints[i].pt.y >= 6 && keypoints[i].pt.x <= 23 && keypoints[i].pt.y <= 34 ) || 
					(keypoints[i].pt.x >= 5 && keypoints[i].pt.y >= 109 && keypoints[i].pt.x <= 35 && keypoints[i].pt.y <= 135 ) ||
					(keypoints[i].pt.x >= 3 && keypoints[i].pt.y >= 123 && keypoints[i].pt.x <= 223 && keypoints[i].pt.y <= 133 )){
						aux.push_back(keypoints[i]);
				}
			}
			keypoints = aux;
			break;

		case 50:
			for(int i = 0; i < keypoints.size(); i++){
				if((keypoints[i].pt.x >= 1 && keypoints[i].pt.y >= 105 && keypoints[i].pt.x <= 32 && keypoints[i].pt.y <= 131 ) || 
					(keypoints[i].pt.x >= 4 && keypoints[i].pt.y >= 2 && keypoints[i].pt.x <= 25 && keypoints[i].pt.y <= 27 ) ||
					(keypoints[i].pt.x >= 130 && keypoints[i].pt.y >= 3 && keypoints[i].pt.x <= 227 && keypoints[i].pt.y <= 121 )){
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
				if((keypoints[i].pt.x >= 8 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 150 && keypoints[i].pt.y <= 71 ) || 
					(keypoints[i].pt.x >= 6 && keypoints[i].pt.y >= 100 && keypoints[i].pt.x <= 24 && keypoints[i].pt.y <= 130 ) ||
					(keypoints[i].pt.x >= 235 && keypoints[i].pt.y >= 104 && keypoints[i].pt.x <= 260 && keypoints[i].pt.y <= 130 ) ||
					(keypoints[i].pt.x >= 232 && keypoints[i].pt.y >= 4 && keypoints[i].pt.x <= 257 && keypoints[i].pt.y <= 27 )){
						aux.push_back(keypoints[i]);
				}
			}
			keypoints = aux;
			break;
		case 10:
			for(int i = 0; i < keypoints.size(); i++){
				if((keypoints[i].pt.x >= 6 && keypoints[i].pt.y >= 8 && keypoints[i].pt.x <= 155 && keypoints[i].pt.y <= 74 ) || 
					(keypoints[i].pt.x >= 8 && keypoints[i].pt.y >= 106 && keypoints[i].pt.x <= 35 && keypoints[i].pt.y <= 130 ) ||
					(keypoints[i].pt.x >= 235 && keypoints[i].pt.y >= 111 && keypoints[i].pt.x <= 260 && keypoints[i].pt.y <= 130 ) ||
					(keypoints[i].pt.x >= 232 && keypoints[i].pt.y >= 4 && keypoints[i].pt.x <= 257 && keypoints[i].pt.y <= 27 )){
						aux.push_back(keypoints[i]);
				}
			}
			keypoints = aux;
			break;
		case 20:
			for(int i = 0; i < keypoints.size(); i++){
				if((keypoints[i].pt.x >= 6 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 170 && keypoints[i].pt.y <= 61 ) || 
					(keypoints[i].pt.x >= 8 && keypoints[i].pt.y >= 114 && keypoints[i].pt.x <= 35 && keypoints[i].pt.y <= 146 ) ||
					(keypoints[i].pt.x >= 231 && keypoints[i].pt.y >= 111 && keypoints[i].pt.x <= 266 && keypoints[i].pt.y <= 137 ) ||
					(keypoints[i].pt.x >= 232 && keypoints[i].pt.y >= 4 && keypoints[i].pt.x <= 260 && keypoints[i].pt.y <= 27 )){
						aux.push_back(keypoints[i]);
				}
			}
			keypoints = aux;
			break;
		case 50:
			for(int i = 0; i < keypoints.size(); i++){
				if((keypoints[i].pt.x >= 6 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 170 && keypoints[i].pt.y <= 71 ) || 
					(keypoints[i].pt.x >= 8 && keypoints[i].pt.y >= 109 && keypoints[i].pt.x <= 44 && keypoints[i].pt.y <= 146 ) ||
					(keypoints[i].pt.x >= 215 && keypoints[i].pt.y >= 111 && keypoints[i].pt.x <= 266 && keypoints[i].pt.y <= 137 ) ||
					(keypoints[i].pt.x >= 232 && keypoints[i].pt.y >= 4 && keypoints[i].pt.x <= 260 && keypoints[i].pt.y <= 27 )){
						aux.push_back(keypoints[i]);
				}
			}
			keypoints = aux;
			break;
		}

	}
}