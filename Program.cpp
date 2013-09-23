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

int getBlob(Mat src);

int runProgram(int argc, char *argv[]) 
{
    const char      * wndName = "Source image",
                            * wndNameGray = "Gray img", 
                            * wndNameOut = "Out",
                            * filename = "blob.jpg";

    Mat src, out;
	src = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
	int a = getBlob(src);

	//namedWindow(wndNameOut, CV_GUI_NORMAL);
	//imshow(wndNameOut, out);

	return 0;
}

int getBlob(Mat src)
{
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

	//Mat out;
	//drawKeypoints(src, keyPoints, out, CV_RGB(0,255,0), DrawMatchesFlags::DEFAULT);

	//cout << "Keypoints " << keyPoints.size() << endl;

	//return out;

	return 0;
}