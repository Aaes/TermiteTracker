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

int* ColorDetection(Mat img, Scalar colorMin, Scalar colorMax, double alpha, int beta, int result[]){
    //Define matrices
    Mat imgContrast = constrastImage(img, alpha, beta);
    Mat imgThresh;
    Mat imgThreshFinal;
    Mat imgBlur;
    Mat blob;
    
    imshow("contrast", imgContrast);
    
    //Threshold based on color ranges (Blue/Green/Red scalars)
    inRange(imgContrast, colorMin, colorMax, imgThresh); //BGR range
    
    imshow("Thresh", imgThresh);
    
    //Apply Blur effect to make blobs much more coherent
    GaussianBlur(imgThresh, imgBlur, Size(9,9), 0);
    
    //Set SimpleBlobDetector parameters
    SimpleBlobDetector::Params params;
    params.filterByArea = true;
    params.filterByCircularity = false;
    params.filterByConvexity = false;
    params.filterByInertia = false;
    params.filterByColor = true;
    params.blobColor = 255;
    params.minArea = 50;
    params.maxArea = 300;
    
    SimpleBlobDetector blobDetector(params);
    blobDetector.create("Blob Detection");
    
    //Vectors to store keypoints (center points for a blob)
    vector<KeyPoint> keypoints;
    
    //Try blob detection for both thresholded colors
    threshold(imgBlur, imgThreshFinal, 100, 255,0);
    blobDetector.detect(imgThreshFinal, keypoints);

    if(!keypoints.empty()){
        KeyPoint point = keypoints.front();
        
        result[0] = point.pt.x;
        result[1] = point.pt.y;
        result[2] = point.size;
    }
    else{
        result[0] = 0;
        result[1] = 0;
        result[2] = 0;
    }
    
//    result[0] = 359;
//    result[1] = 271;
//    result[2] = 14;

    return result;
}

vector<KeyPoint> TestColorDetection(Mat img, Scalar colorMin, Scalar colorMax, double alpha, int beta, int result[]){
    //Define matrices
    Mat imgContrast = constrastImage(img, alpha, beta);
    Mat imgThresh;
    Mat imgThreshFinal;
    Mat imgDilate;
    Mat imgErode;
    Mat imgBlur;
    Mat blob;
    
    //imshow("contrast", imgContrast);
    
    //Threshold based on color ranges (Blue/Green/Red scalars)
    inRange(imgContrast, colorMin, colorMax, imgThresh); //BGR range
    
    //imshow("Thresh", imgThresh);
    
    imgErode = ErodeImage(imgThresh, 0, 0);
    imgDilate = DilateImage(imgErode, 0, 3);
    
    //imshow("Erode", imgErode);
    imshow("Dilate", imgDilate);
    
    //Set SimpleBlobDetector parameters
    SimpleBlobDetector::Params params;
    params.filterByArea = false;
    params.filterByCircularity = false;
    params.filterByConvexity = false;
    params.filterByInertia = false;
    params.filterByColor = true;
    params.blobColor = 255;
    params.minArea = 50;
    params.maxArea = 300;
    
    SimpleBlobDetector blobDetector(params);
    blobDetector.create("Blob Detection");
    
    //Vectors to store keypoints (center points for a blob)
    vector<KeyPoint> keypoints;
    
    //Try blob detection for both thresholded colors
    //threshold(imgBlur, imgThreshFinal, 100, 255,0);
    blobDetector.detect(imgThresh, keypoints);
    
    if(!keypoints.empty()){
        KeyPoint point = keypoints.front();
        
        result[0] = point.pt.x;
        result[1] = point.pt.y;
        result[2] = point.size;
    }
    else{
        result[0] = 0;
        result[1] = 0;
        result[2] = 0;
    }
    
//    result[0] = 359;
//    result[1] = 271;
//    result[2] = 14;
    
    return keypoints;
}