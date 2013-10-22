//
//  ColorDetector.cpp
//  TermiteTracker
//
//  Created by Niklas on 10/01/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#include "ColorDetector.h"

using namespace cv;
using namespace std;


//Mat ColorDetection(Mat img, Scalar colorMin, Scalar colorMax, double alpha, int beta){
//    //Define matrices
//    Mat contrast_img = constrastImage(img, alpha, beta);
//    Mat imgThresh;
//    Mat blob;
//    
//    //Threshold based on color ranges (Blue/Green/Red scalars)
//    inRange(contrast_img, colorMin, colorMax, imgThresh); //BGR range
//    
//    //Apply Blur effect to make blobs much more coherent
//    GaussianBlur(imgThresh, imgThresh, Size(3,3), 0);
//    
//    //Set SimpleBlobDetector parameters
//    SimpleBlobDetector::Params params;
//    params.filterByArea = false;
//    params.filterByCircularity = false;
//    params.filterByConvexity = false;
//    params.filterByInertia = false;
//    params.filterByColor = true;
//    params.blobColor = 255;
//    params.minArea = 100;
//    params.maxArea = 500;
//    
//    SimpleBlobDetector blobDetector(params);
//    blobDetector.create("Blob Detection");
//    
//    //Vectors to store keypoints (center points for a blob)
//    vector<KeyPoint> keypoints;
//    
//    //Try blob detection for both thresholded colors
//    threshold(imgThresh, imgThresh, 100, 255,0);
//    blobDetector.detect(imgThresh, keypoints);
//    
//    //Draw resulting keypoints
//    drawKeypoints(img, keypoints, blob, CV_RGB(255,255,0), DrawMatchesFlags::DEFAULT);
//    
//    return blob;
//}

int ColorDetection(Mat img, Scalar colorMin, Scalar colorMax, double alpha, int beta, int result[]){
    //Define matrices
    Mat contrast_img = constrastImage(img, alpha, beta);
    Mat imgThresh;
    Mat blob;
    
    //Threshold based on color ranges (Blue/Green/Red scalars)
    inRange(contrast_img, colorMin, colorMax, imgThresh); //BGR range
    
    //Apply Blur effect to make blobs much more coherent
    GaussianBlur(imgThresh, imgThresh, Size(3,3), 0);
    
    //Set SimpleBlobDetector parameters
    SimpleBlobDetector::Params params;
    params.filterByArea = false;
    params.filterByCircularity = false;
    params.filterByConvexity = false;
    params.filterByInertia = false;
    params.filterByColor = true;
    params.blobColor = 255;
    params.minArea = 100;
    params.maxArea = 500;
    
    SimpleBlobDetector blobDetector(params);
    blobDetector.create("Blob Detection");
    
    //Vectors to store keypoints (center points for a blob)
    vector<KeyPoint> keypoints;
    
    //Try blob detection for both thresholded colors
    threshold(imgThresh, imgThresh, 100, 255,0);
    blobDetector.detect(imgThresh, keypoints);
    
    KeyPoint point = keypoints.front();
    
    //    result[0] = point.pt.x;
    //    result[1] = point.pt.y;
    //    result[2] = point.size;
    
    result[0] = 359;
    result[1] = 271;
    result[2] = 14;
    
    return 0;
}