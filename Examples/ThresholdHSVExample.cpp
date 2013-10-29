//
//  ThresholdHSVExample.cpp
//  Termite
//
//  Created by Nikolaj Aaes on 30/09/13.
//  Copyright (c) 2013 Nikolaj Aaes. All rights reserved.
//

#include "ThresholdHSVExample.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;


int runThresholdHSVExample()
{
    Mat img;
    img = imread("/Users/Nikolaj/Developer/TermiteTracker/Media/TestBlobsRed.png");
    
    cvtColor(img, img, CV_RGB2HSV);
    imshow("Threshold HSV Example", img);
    
    //split image into the three channels
    vector<Mat> mats(img.channels());
    //mats[0] = H, mats[1] = S, mats[2] = V
    cv::split(img, mats);
    
    imshow("H", mats[0]);
    imshow("S", mats[1]);
    imshow("V", mats[2]);
    /*
    img = cv2.imread('sof.jpg')
    
    ORANGE_MIN = np.array([5, 50, 50],np.uint8)
    ORANGE_MAX = np.array([15, 255, 255],np.uint8)
    
    hsv_img = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
    
    frame_threshed = cv2.inRange(hsv_img, ORANGE_MIN, ORANGE_MAX)
    cv2.imwrite('output2.jpg', frame_threshed)
    */
    waitKey(0);
    return 0;
}
