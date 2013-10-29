#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

///// Global variables
int threshold_value = 61;
int threshold_type = 0;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;

int redFrom = 200;	int redTo = 255;
int greenFrom = 0;	int greenTo = 50;
int blueFrom = 0;	int blueTo = 50;

Mat frame;
string window_name = "Demo";
string window_name2 = "Thresholded Demo";

string trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
string trackbar_value = "Value";

///// Function headers
void Threshold_Demo(int, void*);
void salt(Mat img, int n);
void showValue(Mat img);

int runExample1(int argc, char** argv)
{
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	namedWindow(window_name2, CV_WINDOW_AUTOSIZE);

    VideoCapture capture;
	
	// Create Trackbar to choose type of Threshold
	createTrackbar( trackbar_type,
					window_name, &threshold_type,
					max_type, Threshold_Demo );

	createTrackbar( trackbar_value,
					window_name, &threshold_value,
					max_value, Threshold_Demo );

    if (argc == 2)
        capture.open(argv[1]);  // Open file
    else
    {
        capture.open(0);        // Open camera device
        waitKey(0);
    }
    
    //"/Users/Nikolaj/Developer/TermiteTracker/Media/myrer.mp4"


    if (!capture.isOpened())
    {
        cout << "Cannot open video device or file!" << endl;
        return -1;
    }

    while(true)
    {
        capture >> frame;
        if (frame.empty())
            break;

		Threshold_Demo(0, 0);

        if (waitKey(30) == 'q')
            break;
    }

    return 0;
}

void Threshold_Demo(int, void*)
{
  /* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
   */
	
	imshow(window_name, frame);
	threshold(frame, frame, threshold_value, max_BINARY_value, threshold_type);
	showValue(frame);

	imshow(window_name2, frame);
}

void salt(Mat img, int n) {
	for (int k = 0; k < n; k++) {
		int i = rand() % img.cols;
		int j = rand() % img.rows;
		
		if(img.channels() ==  1) {
			img.at<uchar>(j, i) = 255;
		} else {
			img.at<cv::Vec3b>(j, i)[0] = 255;
			img.at<cv::Vec3b>(j, i)[1] = 255;
			img.at<cv::Vec3b>(j, i)[2] = 255;
		}
	}
}

void showValue(Mat img) {
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++)  {
			int r = img.at<cv::Vec3b>(i, j)[2];
			int g = img.at<cv::Vec3b>(i, j)[1];
			int b = img.at<cv::Vec3b>(i, j)[0];

			if((r >= redFrom) && (r <= redTo) &&
			   (g >= greenFrom) && (g <= greenTo) &&
			   (b >= blueFrom) && (b <= blueTo)) {
				   r = 0;
				   g = 0;
				   b = 0;
			} else {
					r = 255;
					g = 255;
					b = 255;
					//cout << "rgb(" << r << ", " << g << ", " << b << ")" << endl;
			}
					
			img.at<cv::Vec3b>(i, j)[2] = r;
			img.at<cv::Vec3b>(i, j)[1] = g;
			img.at<cv::Vec3b>(i, j)[0] = b;
		}
	}
}