#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

using namespace std;
using namespace cv;

void getBlob(Mat src);

int runProgram(int argc, char *argv[]) 
{
	const char *filename = "blob.jpg";
    Mat src = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);

	getBlob(src);

	return 0;
}

void getBlob(Mat src) 
{	
	const char * wndNameOut = "Out";
	Mat out;

	vector<KeyPoint> keyPoints;

	SimpleBlobDetector::Params params;
	params.filterByArea = false;
	params.filterByCircularity = false;
	params.filterByConvexity = false;
	params.filterByInertia = false;
	params.filterByColor = true;
	params.blobColor = 0;

	SimpleBlobDetector blobDetector(params);
	blobDetector.create("SimpleBlob");

	blobDetector.detect(src, keyPoints);
	cout << "Keypoints " << keyPoints.size() << endl;

	drawKeypoints(src, keyPoints, out, CV_RGB(0,255,0), DrawMatchesFlags::DEFAULT);

	namedWindow(wndNameOut, CV_GUI_NORMAL);
	imshow(wndNameOut, out);

	waitKey(0);
}