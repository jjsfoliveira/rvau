#include "Detector.h"


Detector::Detector(string _path)
{
	path = _path;
	readImage();
	detectKeyPoint();
	loadObjects();
}


Detector::~Detector(void)
{
}

void Detector::readImage(){
	scene = imread(path, CV_LOAD_IMAGE_GRAYSCALE);
}

void Detector::detectKeyPoint(){
	int minHessian = 400;
	SurfFeatureDetector detector( minHessian );
	detector.detect( scene, keypoints);
}

void Detector::loadObjects(){
	object = ImgObject("bancknotes/5_front.png", 5, true);
}

void Detector::getMatches_FLANN(){
	SurfDescriptorExtractor extractor;

	Mat descriptors_object, descriptors_scene;

	extractor.compute( object.object, object.keypoints, descriptors_object );
	extractor.compute( scene, keypoints, descriptors_scene );

	//-- Step 3: Matching descriptor vectors using FLANN matcher
	FlannBasedMatcher matcher;
	std::vector< DMatch > matches;
	matcher.match( descriptors_object, descriptors_scene, matches );
	double max_dist = 0; double min_dist = 100;

	//-- Quick calculation of max and min distances between keypoints
	for( int i = 0; i < descriptors_object.rows; i++ )
	{ double dist = matches[i].distance;
	if( dist < min_dist ) min_dist = dist;
	if( dist > max_dist ) max_dist = dist;
	}

	printf("-- Max dist : %f \n", max_dist );
	printf("-- Min dist : %f \n", min_dist );

	//-- Draw only "good" matches (i.e. whose distance is less than 3*min_dist )


	goodMatches.clear();
	for( int i = 0; i < descriptors_object.rows; i++ )
	{ if( matches[i].distance < 3*min_dist )
		{ goodMatches.push_back( matches[i]); }
	}
}

void Detector::getCorners(){
	 std::vector<Point2f> obj;
	  std::vector<Point2f> scene;

	  for( int i = 0; i < goodMatches.size(); i++ )
	  {
		//-- Get the keypoints from the good matches
		obj.push_back( object.keypoints[ goodMatches[i].queryIdx ].pt );
		scene.push_back( keypoints[ goodMatches[i].trainIdx ].pt );
	  }

	//while(true){
	  Mat mat;
	  Mat H = findHomography( obj, scene, CV_RANSAC, 3, mat);

	  //-- Get the corners from the image_1 ( the object to be "detected" )
	  std::vector<Point2f> obj_corners(4);
	  obj_corners[0] = cvPoint(0,0); 
	  obj_corners[1] = cvPoint( object.object.cols, 0 );
	  obj_corners[2] = cvPoint( object.object.cols, object.object.rows );
	  obj_corners[3] = cvPoint( 0, object.object.rows );
	  std::vector<Point2f> scene_corners(4);

	  perspectiveTransform( obj_corners, scene_corners, H);

	  corners = scene_corners;
}

void Detector::removeGoodMatches(){

	for(int i = 0; i < keypoints.size(); i++){
		if(pointPolygonTest(corners, keypoints[i].pt, false) >= 0){
			keypoints.erase(keypoints.begin() + i);
		}
	}
	for(int i = 0; i < keypoints.size(); i++){
		if(pointPolygonTest(corners, keypoints[i].pt, false) >= 0){
			keypoints.erase(keypoints.begin() + i);
		}
	}
}

void Detector::createImage(){
	Mat image_scene, image_object;
	drawMatches( object.object, object.keypoints, scene, keypoints,
		goodMatches, image, Scalar::all(-1), Scalar::all(-1),
		vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

	drawKeypoints(scene,keypoints,image_scene, Scalar::all(-1),DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );
	drawKeypoints(object.object,object.keypoints,image_object, Scalar::all(-1),DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

	line( image, corners[0]+ Point2f( object.object.cols, 0), corners[1]+ Point2f( object.object.cols, 0), Scalar(0, 255, 0), 4 );
	line( image, corners[1]+ Point2f( object.object.cols, 0), corners[2]+ Point2f( object.object.cols, 0), Scalar( 0, 255, 0), 4 );
	line( image, corners[2]+ Point2f( object.object.cols, 0), corners[3]+ Point2f( object.object.cols, 0), Scalar( 0, 255, 0), 4 );
	line( image, corners[3]+ Point2f( object.object.cols, 0), corners[0]+ Point2f( object.object.cols, 0), Scalar( 0, 255, 0), 4 );
	
	imshow( "Good Matches & Object detection", image );
	imshow( "Scene - good points", image_scene );
	imshow( "Object - good points", image_object );

}