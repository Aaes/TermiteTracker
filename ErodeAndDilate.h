//
//  ErodeAndDilate.h
//  TermiteTracker
//
//  Created by Niklas on 11/11/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#ifndef __TermiteTracker__ErodeAndDilate__
#define __TermiteTracker__ErodeAndDilate__

#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

using namespace cv;

Mat ErodeImage(Mat img, int erosion_type, int erosion_size);
Mat DilateImage(Mat img, int dilate_type, int dilate_size);


#endif /* defined(__TermiteTracker__ErodeAndDilate__) */
