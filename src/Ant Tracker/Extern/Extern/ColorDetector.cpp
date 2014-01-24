//
//  ColorDetector.cpp
//  TermiteTracker
//
//  Created by Niklas on 10/01/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#include "ColorDetector.h"
#include <time.h>
#include "opencv2\gpu\gpu.hpp"

using namespace cv;
using namespace std;

Mat imgThresh;

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

int ColorDetection(Mat img, int threshold, double alpha, int beta, int result[]) {
    imgThresh.release();
    
	//Thresholding on GPU
	gpu::GpuMat src, gray, dst;
	src.upload(img);

	gpu::cvtColor(src, gray, CV_BGR2GRAY);
	gpu::threshold(gray, dst, threshold, 255.0, 0);
	dst.download(imgThresh);

    //Blobdetection - Set SimpleBlobDetector parameters
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
    
    vector<KeyPoint> keypoints;
	blobDetector.detect(imgThresh, keypoints);

	//Find largest blob
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

Mat getThresholdImage(){
    return imgThresh;
}