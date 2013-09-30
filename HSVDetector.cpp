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

int HSVDetection(){
    string filename = "/Users/Niklas/Desktop/redblue.png";
    
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