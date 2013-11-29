#include "Detector.h"

using namespace cv;

/** @function main */
int main( int argc, char** argv )
{
	Detector det = Detector("10s.jpg");
	det.getMatches_FLANN();
	det.getCorners();
	//det.removeGoodMatches();
	//det.createImage();
	Mat image;
	drawMatches( det.object.object, det.object.keypoints, det.scene,det. keypoints,
		det.goodMatches, image, Scalar::all(-1), Scalar::all(-1),
		vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

	line( image, det.corners[0]+ Point2f( det.object.object.cols, 0), det.corners[1]+ Point2f( det.object.object.cols, 0), Scalar(0, 255, 0), 4 );
	line( image, det.corners[1]+ Point2f( det.object.object.cols, 0), det.corners[2]+ Point2f( det.object.object.cols, 0), Scalar( 0, 255, 0), 4 );
	line( image, det.corners[2]+ Point2f( det.object.object.cols, 0), det.corners[3]+ Point2f( det.object.object.cols, 0), Scalar( 0, 255, 0), 4 );
	line( image, det.corners[3]+ Point2f( det.object.object.cols, 0), det.corners[0]+ Point2f( det.object.object.cols, 0), Scalar( 0, 255, 0), 4 );


	imshow( "Good Matches & Object detection", image );
	waitKey(0);
	return 0;
}