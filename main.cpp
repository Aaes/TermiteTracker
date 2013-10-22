//
//  main.cpp
//  TermiteTracker
//
//  Created by Niklas on 9/23/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[])
{
    int input[3];
    
    Mat img = imread("/Users/Niklas/Developer/TermiteTracker/Media/4.jpg");
    Mat blob;
    
    ColorDetection(img, Scalar(100,250,100), Scalar(200,255,200), 3.0, 100, input);
    
    KeyPoint keypoint = KeyPoint(input[0], input[1], input[2]);
    
    vector<KeyPoint> points;
    
    points.push_back(keypoint);
    
    drawKeypoints(img, points, blob, CV_RGB(255,255,0));
    
    imshow("Red and Green color detection", blob);
    waitKey(0);
    return 0;
}


