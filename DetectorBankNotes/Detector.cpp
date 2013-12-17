#include "Detector.h"


Detector::Detector(string _path, FeatureDetector & detector)
{

	path = _path;
	readImage();
	detectKeyPoint(detector);
	loadObjects(detector);
}


Detector::~Detector(void)
{
}

void Detector::readImage(){
	scene = imread(path, CV_LOAD_IMAGE_GRAYSCALE);
}

void Detector::detectKeyPoint(FeatureDetector & detector){
	detector.detect( scene, keypoints);
	cout << "Scene - KeyPoint: "<< keypoints.size() << endl;
}

void Detector::loadObjects(FeatureDetector & detector){
	objects.push_back(ImgObject("bancknotes/5_front.jpg", 5, true, detector));
	objects.push_back(ImgObject("bancknotes/5_back.jpg", 5, false, detector));
	objects.push_back(ImgObject("bancknotes/10_front.jpg", 10, true, detector));
	objects.push_back(ImgObject("bancknotes/10_back.jpg", 10, false, detector));
	objects.push_back(ImgObject("bancknotes/20_front.jpg",20, true, detector));
	objects.push_back(ImgObject("bancknotes/20_back.jpg", 20, false, detector));
	objects.push_back(ImgObject("bancknotes/50_front.jpg", 50, true, detector));
	objects.push_back(ImgObject("bancknotes/50_back.jpg", 50, false, detector));
}

void Detector::getDescriptor(DescriptorExtractor& extractor, int i){
	extractor.compute( objects[i].object, objects[i].keypoints, descriptors_object );
	extractor.compute( scene, keypoints, descriptors_scene );
}

void Detector::getMatches(DescriptorMatcher& matcher,  int i){
	//-- Step 3: Matching descriptor vectors using FLANN matcher
	//FlannBasedMatcher matcher;
	std::vector< DMatch > matches;
	matcher.match( descriptors_object, descriptors_scene, matches );
	double max_dist = 0; double min_dist = 100;

	//-- Quick calculation of max and min distances between keypoints
	for( int i = 0; i < descriptors_object.rows; i++ )
	{ double dist = matches[i].distance;
	if( dist < min_dist ) min_dist = dist;
	if( dist > max_dist ) max_dist = dist;
	}

	//-- Draw only "good" matches (i.e. whose distance is less than 3*min_dist )


	goodMatches.clear();
	for( int i = 0; i < descriptors_object.rows; i++ )
	{ if( matches[i].distance < 3*min_dist )
		{ goodMatches.push_back( matches[i]); }
	}
	goodMatches = matches;

	
}

bool Detector::getCorners(int i){
	 std::vector<Point2f> obj;
	  std::vector<Point2f> scene;

	  for( int j = 0; j < goodMatches.size(); j++ )
	  {
		//-- Get the keypoints from the good matches
		obj.push_back( objects[i].keypoints[ goodMatches[j].queryIdx ].pt );
		scene.push_back( keypoints[ goodMatches[j].trainIdx ].pt );
	  }



	  if(goodMatches.size()<4){
		  return false;
	  }

	//while(true){
	  Mat mat;
	  Mat H = findHomography( obj, scene,mat, CV_RANSAC, 3);


	  vector<DMatch> aux;
	  for(int j = 0; j < goodMatches.size() ; j++){
		  if((int)mat.at<uchar>(j,0) == 1){
			  aux.push_back(goodMatches[j]);
		  }
	  }

	


	  //-- Get the corners from the image_1 ( the object to be "detected" )
	  std::vector<Point2f> obj_corners(4);
	  obj_corners[0] = cvPoint(0,0); 
	  obj_corners[1] = cvPoint( objects[i].object.cols, 0 );
	  obj_corners[2] = cvPoint( objects[i].object.cols, objects[i].object.rows );
	  obj_corners[3] = cvPoint( 0, objects[i].object.rows );
	  std::vector<Point2f> scene_corners(4);

		
	  perspectiveTransform( obj_corners, scene_corners, H);
	  for(int j = 0; j < aux.size(); j++){
		if(pointPolygonTest(scene_corners, keypoints[ aux[j].trainIdx ].pt , false) < 0){
			return false;
		}
	  }
	goodMatches = aux;
	corners.push_back(scene_corners);
	//cout << objects[i].value << endl;
	values.push_back(objects[i].value);
	cout << "Good Matches: " << goodMatches.size() << endl;
	return true;
}

void Detector::removeGoodMatches(){
	
	for(int i = 0; i < keypoints.size();){
		if(pointPolygonTest(corners[corners.size()-1], keypoints[i].pt, false) >= 0){
			keypoints.erase(keypoints.begin() + i);
		}
		else
			i++;
	}
	
}

void Detector::createImage(int i){
	Mat image_scene, image_object;
	drawMatches( objects[i].object, objects[i].keypoints, scene, keypoints,
		goodMatches, image, Scalar::all(-1), Scalar::all(-1),
		vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

	drawKeypoints(scene,keypoints,image_scene, Scalar::all(-1),DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );
	drawKeypoints(objects[i].object,objects[i].keypoints,image_object, Scalar::all(-1),DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

	/*for(int j = 0; j < corners.size(); j++){
		line( image, corners[j][0]+ Point2f( objects[i].object.cols, 0), corners[j][1]+ Point2f( objects[i].object.cols, 0), Scalar( 0, 255, 0), 4 );
		line( image, corners[j][1]+ Point2f( objects[i].object.cols, 0), corners[j][2]+ Point2f( objects[i].object.cols, 0), Scalar( 0, 255, 0), 4 );
		line( image, corners[j][2]+ Point2f( objects[i].object.cols, 0), corners[j][3]+ Point2f( objects[i].object.cols, 0), Scalar( 0, 255, 0), 4 );
		line( image, corners[j][3]+ Point2f( objects[i].object.cols, 0), corners[j][0]+ Point2f( objects[i].object.cols, 0), Scalar( 0, 255, 0), 4 );
		
		float x = (Point2f( objects[i].object.cols, 0).x + corners[j][0].x +(corners[j][1]-corners[j][0]).x/2);
		float y = (Point2f( objects[i].object.cols, 0).y + corners[j][1].y +(corners[j][2]-corners[j][1]).y/2);

		string Result;   
		ostringstream convert;
		convert << values[j];   
		string text = convert.str();

		putText( image, text , Point2f( x,y), CV_FONT_HERSHEY_SIMPLEX,2,Scalar(0,0,0));
	}*/

	for(int j = 0; j < corners.size(); j++){
		line( image_scene, corners[j][0], corners[j][1], Scalar( 0, 255, 0), 4 );
		line( image_scene, corners[j][1], corners[j][2], Scalar( 0, 255, 0), 4 );
		line( image_scene, corners[j][2], corners[j][3], Scalar( 0, 255, 0), 4 );
		line( image_scene, corners[j][3], corners[j][0], Scalar( 0, 255, 0), 4 );
		
		float x = (corners[j][0].x +(corners[j][1]-corners[j][0]).x/2);
		float y = (corners[j][1].y +(corners[j][2]-corners[j][1]).y/2);

		string Result;   
		ostringstream convert;
		convert << values[j];   
		string text = convert.str();

		putText( image_scene, text , Point2f( x,y), CV_FONT_HERSHEY_SIMPLEX,2,Scalar(255,0,0), 4);
	}

	int total=0;
	for(int k=0; k < values.size(); k++)
	{
		total+= values[k];
	}
	ostringstream convert;
	convert << total;
	string text = convert.str();
	putText( image_scene, text , Point2f( 50,50), CV_FONT_HERSHEY_SIMPLEX,2,Scalar(255,0,0), 4);
	
	imshow( "Good Matches & Object detection", image );
	imshow( "Scene - good points", image_scene );
	imshow( "Object - good points", image_object );

}