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
	    string windowNormal = "Normal",
                windowBlob = "Blob",
                windowThresh = "Theshold",
                filename = "/Users/Nikolaj/Developer/TermiteTracker/Media/myrevideo2.mp4";
		
		namedWindow(windowNormal, CV_WINDOW_AUTOSIZE);
        moveWindow(windowNormal, 0, 0);
		namedWindow(windowBlob, CV_WINDOW_AUTOSIZE);
        moveWindow(windowThresh, 300, 0);
        namedWindow(windowThresh, CV_WINDOW_AUTOSIZE);
        moveWindow(windowBlob, 600, 0);

		VideoCapture capture;
		capture.open(0);
        waitKey(0);

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
        params.minArea = 10;
        params.maxArea = 100;

		SimpleBlobDetector blobDetector(params);
		blobDetector.create("SimpleBlob");

        Mat original;
        Mat thresh;
        Mat blob;
        vector<KeyPoint> trackingPoints;
    
		Mat frame;
		while(true)
		{
			capture >> frame;
			if (frame.empty())
				break;
            
            original = frame.clone();
            if(blob.empty()){
                blob = frame.clone();
            }

			vector<KeyPoint> keyPoints;
            
            Scalar colorMin(20,20,20);
            Scalar colorMax(70,70,70);
            
            inRange(frame, colorMin, colorMax, thresh);
            
            GaussianBlur(thresh, thresh, Size(3,3), 0);
            
			blobDetector.detect(thresh, keyPoints);
            
            for(int i = 0; i<keyPoints.size(); i++){
                trackingPoints.push_back(keyPoints[i]);
            }
            drawKeypoints(original, trackingPoints, blob, CV_RGB(0,0,255), DrawMatchesFlags::DEFAULT);
        
            imshow(windowNormal, original);
            imshow(windowThresh, thresh);
			imshow(windowBlob, blob);
			waitKey(50);
		}
		
		return 0;
}