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

//Define matrices
Mat imgContrast;
Mat imgH;
Mat imgDilate;
Mat imgErode;
Mat imgThresh;
Mat blob;

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
    
    //Deallocate memory before continueing
    imgContrast.release();
    imgH.release();
    imgDilate.release();
    imgErode.release();
    imgThresh.release();
    blob.release();
    
    clock_t start = clock();
    
    GaussianBlur(img, imgContrast, Size(0, 0), 3);
    addWeighted(img, 1.5, imgContrast, -0.5, 0, imgContrast);
    
    imgH = imgContrast * alpha;
    
    //imshow("contrast", imgH);
    
    //Threshold based on color ranges (Blue/Green/Red scalars)
    inRange(imgH, colorMin, colorMax, imgThresh); //BGR range
    
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
    
    //Try blob detection for threholded colors
    //threshold(imgBlur, imgThreshFinal, 100, 255,0);
    blobDetector.detect(imgThresh, keypoints);

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

    double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    
    cout << duration << " seconds" << endl;
    
    return 1;
}

Mat getThresholdImage(){
    return imgThresh;
}

Mat getContrastedImage(){
    return imgH;
}
