//
//  Contrast.h
//  TermiteTracker
//
//  Created by Niklas on 9/30/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#ifndef __TermiteTracker__Contrast__
#define __TermiteTracker__Contrast__

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <iostream>

using namespace cv;

Mat constrastImage(Mat image, double alpha, int beta);

#endif /* defined(__TermiteTracker__Contrast__) */
