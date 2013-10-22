//
//  Contrast.cpp
//  TermiteTracker
//
//  Created by Niklas on 9/30/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#include "Contrast.h"

using namespace cv;

Mat constrastImage(Mat image, double alpha, int beta)
{
    Mat new_image = Mat::zeros( image.size(), image.type() );
    
    /// Do the operation new_image(i,j) = alpha*image(i,j) + beta
    for( int y = 0; y < image.rows; y++ )
    { for( int x = 0; x < image.cols; x++ )
    { for( int c = 0; c < 3; c++ )
    {
        new_image.at<Vec3b>(y,x)[c] =
        saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
    }
    }
    }
    
    return new_image;
}