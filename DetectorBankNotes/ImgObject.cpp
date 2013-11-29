#include "ImgObject.h"


ImgObject::ImgObject(String _path,int _value, bool _front)
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
		switch(value){
		case 5:
			vector<Point2f> vec_1(4);
			vec_1[0]= Point2f(5,100);
			vec_1[1]= Point2f(80,100);
			vec_1[2]= Point2f(80,135);
			vec_1[3]= Point2f(5,135);
			
			vector<Point2f> vec_2(4);
			vec_2[0]= Point2f(5,5);
			vec_2[1]= Point2f(35,5);
			vec_2[2]= Point2f(35,25);
			vec_2[3]= Point2f(5,25);

			vector<Point2f> vec_3(4);
			vec_3[0]= Point2f(170,5);
			vec_3[1]= Point2f(170,70);
			vec_3[2]= Point2f(230,70);
			vec_3[3]= Point2f(230,5);

			vector<Point2f> vec_4(4);
			vec_4[0]= Point2f(170,90);
			vec_4[1]= Point2f(170,110);
			vec_4[2]= Point2f(230,110);
			vec_4[3]= Point2f(230,90);

			vector<Point2f> vec_5(4);
			vec_5[0]= Point2f(30,5);
			vec_5[1]= Point2f(30,50);
			vec_5[2]= Point2f(70,50);
			vec_5[3]= Point2f(70,5);

			vector<KeyPoint> aux;

			for(int i = 0; i < keypoints.size(); i++){
				if((keypoints[i].pt.x >= 5 && keypoints[i].pt.y >= 100 && keypoints[i].pt.x <= 80 && keypoints[i].pt.y <= 135 ) || 
					(keypoints[i].pt.x >= 5 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 35 && keypoints[i].pt.y <= 25 ) ||
					(keypoints[i].pt.x >= 170 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 230 && keypoints[i].pt.y <= 70 ) ||
					(keypoints[i].pt.x >= 170 && keypoints[i].pt.y >= 90 && keypoints[i].pt.x <= 230 && keypoints[i].pt.y <= 110 ) ||
					(keypoints[i].pt.x >= 30 && keypoints[i].pt.y >= 5 && keypoints[i].pt.x <= 70 && keypoints[i].pt.y <= 50 )){
						aux.push_back(keypoints[i]);
				}
			}
			keypoints = aux;

			break;
		}
	}
}