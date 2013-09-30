//
//  HSVDetector.cpp
//  TermiteTracker
//
//  Created by Niklas on 9/30/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include "HSVDetector.h"

using namespace cv;
using namespace std;

void HSVDetectionWithSplit();

int HSVDetection(){
    
    string filename = "/Users/Nikolaj/Developer/TermiteTracker/Media/redblue.png";
    
    Mat img = imread(filename);
    
    Mat HSVimg;
    Mat imgThreshRed;
    Mat imgThreshBlue;
    
    
    cvtColor(img, HSVimg, CV_BGR2HSV);
    inRange(HSVimg, Scalar(0,100,51), Scalar(0,256,256), imgThreshRed);
    inRange(HSVimg, Scalar(120,100,40), Scalar(120,256,256), imgThreshBlue);
    
    imshow("Red Threshhold", imgThreshRed);
    imshow("Blue Threshhold", imgThreshBlue);
    
    waitKey(0);
    
    return 0;
}

void runThrough(Mat mat)
{
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; mat.cols; j++) {
            cout << "(" <<(int)mat.at<Vec3b>(i,j)[0]  << ", "
            << (int)mat.at<Vec3b>(i,j)[1]  << ", "
            << (int)mat.at<Vec3b>(i,j)[2] << ") ";
        }
        cout << endl;
    }
}

void HSVDetectionWithSplit()
{
    string filename = "/Users/Nikolaj/Developer/TermiteTracker/Media/redblue.png";
    
    Mat img = imread(filename);
    
    imshow("Original",img);
    
    vector<Mat> splitMats(3);
    cv::split(img, splitMats);
    
    imshow("H", splitMats[0]);
    imshow("S", splitMats[1]);
    imshow("V", splitMats[2]);
    
    runThrough(splitMats[0]);
    
    cout << (img.at<Vec3b>(10,10)[2] == splitMats[2].at<Vec3b>(10,10)[2]) << endl;
    
    waitKey(0);
}