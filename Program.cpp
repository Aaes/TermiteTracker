#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include "ColorDetector.h"

using namespace std;
using namespace cv;

void getBlob(Mat src);

int runProgram() 
{
        //Window and file names
	    string filename = "/Users/Niklas/Developer/TermiteTracker/Media/myrevideo2.mp4";

        //Create video capture
		VideoCapture capture;
		capture.open(0);
        waitKey(50);
    
        //Check if file is found
		if (!capture.isOpened()) {
			cout << "Cannot open file!" << endl;
			return -1;
		}
    
        Mat blob;
        //vector<KeyPoint> trackingPoints;
    
		Mat frame;
		while(true)
		{
			capture >> frame;
			if (frame.empty())
				break;
            
            Scalar colorMin(10,10,100);
            Scalar colorMax(50,50,170);
            
            //blob = ColorDetection(frame, colorMin, colorMax, 1.0, 50);
            
//            for(int i = 0; i<keyPoints.size(); i++){
//                trackingPoints.push_back(keyPoints[i]);
//            }
//            drawKeypoints(original, trackingPoints, blob, CV_RGB(0,0,255), DrawMatchesFlags::DEFAULT);
		}
		
		return 0;
}