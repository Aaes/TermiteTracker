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
        params.minArea = 80;
        params.maxArea = 200;

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
            
            cvtColor(frame, thresh, CV_BGR2HSV);
            
            /* 
             For myrer - giver sort skærm :(
            //RGB 82 76 76
            Scalar colorMin(0,7,32);
            //RGB 37 37 41
            Scalar colorMax(240,10,16);
             */
            
            /*
            //for blå baggrund - giver sort skærm
            //RGB 16 27 48
            Scalar colorMin(89,85,11);
            //RGB 48 58 89
            Scalar colorMax(225,46,35);
             */
            
            /*
             For myrer - converter 2 - sort skærm
             //RGB 82 76 76
             Scalar colorMin(0,0,0);
             //RGB 37 37 41
             Scalar colorMax(240,0,0);
             */
            
             /*
             //for blå baggrund - converter 2 - sort skærm
             //RGB 16 27 48
             Scalar colorMin(219,1,0);
             //RGB 48 58 89
             Scalar colorMax(225,0,0);
            */
            
            /*
             //for blå baggrund - converter 3 - sort skærm
             //RGB 16 27 48
             Scalar colorMin(219,67,19);
             //RGB 48 58 89
             Scalar colorMax(225,46,35);
            */
            
            /*
            //Farven rød - converter 3 - sort skærm
            //RGB 162, 136, 104
            Scalar colorMin(33,36,63);
            //RGB 109 76 51
            Scalar colorMax(26,53,43);
            */
            
            Scalar colorMin(0,0,0);
            Scalar colorMax(179,256,256);
            
            inRange(thresh, colorMin, colorMax, thresh);
            
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