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
#include "Contrast.h"

using namespace cv;
using namespace std;

void HSVDetectionWithSplit();

int HSVDetection(){
    //File location
    string filename = "/Users/Niklas/Developer/TermiteTracker/Media/4.jpg";
    
    //Define matrices
    Mat img = imread(filename);
    Mat contrast_img = constrastImage(img);
    Mat imgThreshRed;
    Mat imgThreshGreen;
    Mat blob;
    
    //Threshold based on color ranges (Blue/Green/Red scalars)
    inRange(contrast_img, Scalar(100,100,250), Scalar(200,200,255), imgThreshRed); //RGB range
    inRange(contrast_img, Scalar(100,250,100), Scalar(200,255,200), imgThreshGreen); //RGB range

    //Apply Blur effect to make blobs much more coherent
    GaussianBlur(imgThreshRed, imgThreshRed, Size(3,3), 0);
    GaussianBlur(imgThreshGreen, imgThreshGreen, Size(3,3), 0);
    
    //Set SimpleBlobDetector parameters
    SimpleBlobDetector::Params params;
    params.filterByArea = false;
    params.filterByCircularity = false;
    params.filterByConvexity = false;
    params.filterByInertia = false;
    params.filterByColor = true;
    params.blobColor = 255;
    
    SimpleBlobDetector blobDetector(params);
    blobDetector.create("Blob Detection");
    
    //Vectors to store keypoints (center points for a blob)
    vector<KeyPoint> redKeyPoints;
    vector<KeyPoint> greenKeyPoints;
    
    //Try blob detection for both thresholded colors
    blobDetector.detect(imgThreshRed, redKeyPoints);
    blobDetector.detect(imgThreshGreen, greenKeyPoints);
    
    //Draw resulting keypoints
    drawKeypoints(img, redKeyPoints, blob, CV_RGB(255,255,0), DrawMatchesFlags::DEFAULT);
    drawKeypoints(blob, greenKeyPoints, blob, CV_RGB(249,0,255), DrawMatchesFlags::DEFAULT);
    
    //Show resulting images from program execution
    imshow("Detect Red and Green", blob);
    imshow("Green threshold", imgThreshGreen);
    imshow("Red threshold", imgThreshRed);
    imshow("Contrasted image", contrast_img);
    
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