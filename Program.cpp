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

int runProgram() 
{
	    const char      * windowNormal = "Normal",
						* windowBlob = "Blob",
                        * windowThresh = "Theshold",
                            * filename = "/Users/Niklas/Developer/TermiteTracker/Media/myrevideo2.mp4";
		
		namedWindow(windowNormal, CV_WINDOW_AUTOSIZE);
        moveWindow(windowNormal, 0, 0);
		namedWindow(windowBlob, CV_WINDOW_AUTOSIZE);
        moveWindow(windowThresh, 300, 0);
        namedWindow(windowThresh, CV_WINDOW_AUTOSIZE);
        moveWindow(windowBlob, 600, 0);

		VideoCapture capture;
		capture.open(filename);

		if (!capture.isOpened()) {
			cout << "Cannot open file!" << endl;
			return -1;
		}

		SimpleBlobDetector::Params params;
		params.filterByArea = true;
		params.filterByCircularity = false;
		params.filterByConvexity = false;
		params.filterByInertia = false;
		params.filterByColor = true;
		params.blobColor = 0;
        params.minArea = 100;
        params.maxArea = 10000;

		SimpleBlobDetector blobDetector(params);
		blobDetector.create("SimpleBlob");

		Mat frame;
		while(true) 
		{
			capture >> frame;
			if (frame.empty())
				break;
            
            Mat original = frame.clone();
            Mat thresh;
            Mat blob;

			vector<KeyPoint> keyPoints;
            
            cvtColor(frame, thresh, CV_RGB2GRAY);
            
            threshold(thresh, thresh, 80, 255, 0);
            
			blobDetector.detect(thresh, keyPoints);
			drawKeypoints(original, keyPoints, blob, CV_RGB(0,255,0), DrawMatchesFlags::DEFAULT);
        
            imshow(windowNormal, original);
            imshow(windowThresh, thresh);
			imshow(windowBlob, blob);
			waitKey(50);
		}
		
		return 0;
}