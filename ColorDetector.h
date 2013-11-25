//
//  ColorDetector.h
//  TermiteTracker
//
//  Created by Niklas on 10/1/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#ifndef __TermiteTracker__ColorDetector__
#define __TermiteTracker__ColorDetector__

#include "Contrast.h"
#include "ErodeAndDilate.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

int ColorDetection(Mat img, Scalar colorMin, Scalar colorMax, double alpha, int beta, int result[]);
Mat getThresholdImage();

#endif /* defined(__TermiteTracker__ColorDetector__) */
