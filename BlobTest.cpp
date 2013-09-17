#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int runBlobTest(int argc, char *argv[]) {
	Mat img = imread("blob.jpg"); 
	cvtColor( img, img, CV_BGR2GRAY );

	//set up the parameters (check the defaults in opencv's code in blobdetector.cpp)
	cv::SimpleBlobDetector::Params params;
	//params.minThreshold = 0;
	//params.maxThreshold = 120;
	//params.thresholdStep = 5;
	//params.minDistBetweenBlobs = 10.0f;

    //params.minArea = 5; 
    //params.maxArea = 8000;
    //params.minConvexity = 0.3f;
    //params.minInertiaRatio = 0.01f;

    //params.maxConvexity = 10;

	//params.filterByColor = true;
	//params.blobColor = 0;
	//params.filterByCircularity = false;
	//params.filterByArea = true;
	//params.filterByConvexity = false;
	//params.filterByInertia = false;
	// ... any other params you don't want default value

	// set up and create the detector using the parameters
	//cv::Ptr<cv::FeatureDetector> blob_detector = new cv::SimpleBlobDetector(params);
	//blob_detector->create("SimpleBlob");

	SimpleBlobDetector blobDetector(params);
	blobDetector.create("SimpleBlob");

	// detect!

	vector<cv::KeyPoint> keypoints;
	blobDetector.detect(img, keypoints);

	cout << keypoints.size() << endl;

	
	Mat blobImg;
	drawKeypoints(img, keypoints, blobImg);
	imshow("Blobs", blobImg);

	waitKey(10000);

	// extract the x y coordinates of the keypoints: 

	//for (int i=0; i<keypoints.size(); i++){
		//float X=keypoints[i].pt.x; 
		//float Y=keypoints[i].pt.y;

		//drawKeypoints(frame, keypoints, frame, CV_RGB(0,255,0), DrawMatchesFlags::DEFAULT);

		//cout << "KEYPOINT BITCH" << endl;
		//cout << X << endl;
		//cout << Y << endl;
	//}

	return 0;
}