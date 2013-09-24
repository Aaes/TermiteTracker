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
	    const char      * windowNormal = "Normal",
						* windowBlob = "Thresholded blob",
                            * filename = "C:\\Users\\hfl\\Desktop\\Private\\Harvard Project\\OpenCV_TestProject5\\x64\\Release\\Megamind.avi";
		
		namedWindow(windowNormal, CV_WINDOW_AUTOSIZE);
		namedWindow(windowBlob, CV_WINDOW_AUTOSIZE);
		moveWindow(windowNormal, 900, 100);

		VideoCapture capture;
		capture.open(filename);

		if (!capture.isOpened()) {
			cout << "Cannot open file!" << endl;
			return -1;
		}

		SimpleBlobDetector::Params params;
		params.filterByArea = false;
		params.filterByCircularity = false;
		params.filterByConvexity = false;
		params.filterByInertia = false;
		params.filterByColor = true;
		params.blobColor = 0;

		SimpleBlobDetector blobDetector(params);
		blobDetector.create("SimpleBlob");

		Mat frame;
		while(true) 
		{
			capture >> frame;
			if (frame.empty())
				break;

			imshow(windowNormal, frame);

			vector<KeyPoint> keyPoints;

			blobDetector.detect(frame, keyPoints);
			//drawKeypoints(frame, keyPoints, frame, CV_RGB(0,255,0), DrawMatchesFlags::DEFAULT);

			//cout << "Keypoints " << keyPoints.size() << endl;
        
			imshow(windowBlob, frame);
			waitKey(0);

			//if (waitKey(0) == 'q')
			//	break;
		}
		
		return 0;
}