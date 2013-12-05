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
    
    CvCapture *video = cvCreateFileCapture("/Users/Niklas/Desktop/myretrack10.mov");
    
    Mat frame;
    frame = cvQueryFrame(video);
    
    while(true){
        
        int input[3];
        Mat blob;
        
        int success = ColorDetection(frame, Scalar(220,220,220), Scalar(256,256,256), 2.0, 1, input); //Detect green
        
        if(!success) cout<<"Failed to run ColorDetection"<<endl;
        
        KeyPoint keypoint = KeyPoint(input[0], input[1], input[2]);
        
        vector<KeyPoint> points = vector<KeyPoint>();
        
        points.push_back(keypoint);
        
        Mat thresh = getThresholdImage();
        
        drawKeypoints(frame, points, blob, CV_RGB(255,0,0));
        drawKeypoints(thresh, points, thresh, CV_RGB(255,0,0));
        
        imshow("Ant detection", blob);
        imshow("Thresh", thresh);
        
        frame = cvQueryFrame(video);
        
        waitKey(1000);
    }
    
}
//
//void trackImage(){
//    
//    int input[3];
//    
//    CvCapture *video = cvCreateFileCapture("/Users/Niklas/Developer/TermiteTracker/Media/MyreTrack.mov");
//    
//    Mat frame;
//    int i = 0;
//    while(i<50){
//        frame = cvQueryFrame(video);
//        i++;
//    }
//    
//    Mat img = frame;
//    Mat blob;
//    
////    vector<KeyPoint> points = ColorDetection(img, Scalar(0,170,140), Scalar(60,210,210), 3.0, 1, input); //Detect green
////    
////    //KeyPoint keypoint = KeyPoint(input[0], input[1], input[2]);
////    
////    //points.push_back(keypoint);
////    
////    drawKeypoints(img, points, blob, CV_RGB(255,0,0));
////    
////    imshow("Green color detection", blob);
////    waitKey(0);
//    
//}

int main(int argc, const char * argv[])
{
    
    trackVideo();
//    Mat img = imread("/Users/Niklas/Developer/TermiteTracker/Report/img/globe.png");
//    Mat gray;
//    cvtColor(img, gray, 0);
//    Mat imgErode = ErodeImage(gray, 0, 7);
//    Mat imgDilate = DilateImage(gray, 0, 7);
//    
//    //inRange(img, Scalar(0,100,0), Scalar(1,150,10), thr);
//    //threshold(grayscale, thr, 200, 255, 0);
//    
//    imshow("original", gray);
//    //imshow("gray", grayscale);
//    imshow("erode", imgErode);
//    imshow("dilate", imgDilate);
//    waitKey(0);
    
    return 0;
}