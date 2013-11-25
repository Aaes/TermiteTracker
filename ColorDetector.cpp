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

KeyPoint getLargestBlob(vector<KeyPoint> input){
    
    KeyPoint largest = input.back();
    input.pop_back();
    
    
    
    while (!input.empty()) {
        KeyPoint nPoint = input.back();
        input.pop_back();
        
        if(largest.size < nPoint.size){
            largest = nPoint;
        }
    }
    
    return largest;
}

int ColorDetection(Mat img, Scalar colorMin, Scalar colorMax, double alpha, int beta, int result[]){
    //Define matrices
    Mat imgContrast = constrastImage(img, alpha, beta);
    Mat imgDilate;
    Mat imgErode;
    Mat imgThresh;
    Mat imgThreshFinal;
    Mat imgBlur;
    Mat blob;
    
    imshow("contrast", imgContrast);
    
    //Threshold based on color ranges (Blue/Green/Red scalars)
    inRange(imgContrast, colorMin, colorMax, imgThresh); //BGR range
    
    imshow("Thresh", imgThresh);
    
    //imgErode = ErodeImage(imgThresh, 0, 0);
    //imgDilate = DilateImage(imgThresh, 0, 0);
    
    //imshow("Erode", imgErode);
    //imshow("Dilate", imgDilate);
    
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
    params.minArea = 100;
    params.maxArea = 10000;
    
    SimpleBlobDetector blobDetector(params);
    blobDetector.create("Blob Detection");
    
    //Vectors to store keypoints (center points for a blob)
    vector<KeyPoint> keypoints;
    
    //Try blob detection for both thresholded colors
    threshold(imgBlur, imgThreshFinal, 100, 255,0);
    blobDetector.detect(imgThreshFinal, keypoints);

    if(!keypoints.empty()){
        KeyPoint point = getLargestBlob(keypoints);
        
        result[0] = point.pt.x;
        result[1] = point.pt.y;
        result[2] = point.size;
    }
    else{
        result[0] = 0;
        result[1] = 0;
        result[2] = 0;
    }

    return 1;
}


