//
//  main.cpp
//  TermiteTracker
//
//  Created by Niklas on 9/23/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#include "main.h"
#include <opencv2/opencv.hpp>

char key;
using namespace std;

void trackVideo(){
    
    CvCapture *video = cvCreateFileCapture("/Users/Niklas/Developer/TermiteTracker/Media/MyreTrack.mov");
    
    Mat frame;
    frame = cvQueryFrame(video);
    
    while(true){
        
//        int input[3];
//        Mat blob;
//        
//        vector<KeyPoint> points = ColorDetection(frame, Scalar(0,170,140), Scalar(60,210,210), 3.0, 1, input); //Detect green
//        
//        //KeyPoint keypoint = KeyPoint(input[0], input[1], input[2]);
//        
//        //points.push_back(keypoint);
//        
//        drawKeypoints(frame, points, blob, CV_RGB(255,0,0));
//        
//        imshow("Green color detection", blob);
//        
//        frame = cvQueryFrame(video);
//        
//        waitKey(1);
    }
    
}

void trackImage(){
    
    int input[3];
    
    CvCapture *video = cvCreateFileCapture("/Users/Niklas/Developer/TermiteTracker/Media/MyreTrack.mov");
    
    Mat frame;
    int i = 0;
    while(i<50){
        frame = cvQueryFrame(video);
        i++;
    }
    
    Mat img = frame;
    Mat blob;
    
//    vector<KeyPoint> points = ColorDetection(img, Scalar(0,170,140), Scalar(60,210,210), 3.0, 1, input); //Detect green
//    
//    //KeyPoint keypoint = KeyPoint(input[0], input[1], input[2]);
//    
//    //points.push_back(keypoint);
//    
//    drawKeypoints(img, points, blob, CV_RGB(255,0,0));
//    
//    imshow("Green color detection", blob);
//    waitKey(0);
    
}

int main(int argc, const char * argv[])
{
    //trackVideo();
    //testTrackImage();
    //trackImage();
    
    //detectDevices();
    
    return 0;
}