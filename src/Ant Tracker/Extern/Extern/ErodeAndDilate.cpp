//
//  ErodeAndDilate.cpp
//  TermiteTracker
//
//  Created by Niklas on 11/11/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#include "ErodeAndDilate.h"

Mat ErodeImage(Mat img, int erosion_type, int erosion_size)
{
    Mat imgErode;
    
    Mat erode_element = getStructuringElement( erosion_type,
                                              Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                              Point( erosion_size, erosion_size ) );
    
    erode(img, imgErode, erode_element);
    
    return imgErode;
}

Mat DilateImage(Mat img, int dilate_type, int dilate_size)
{
    Mat imgDilate;
    
    Mat dilate_element = getStructuringElement( dilate_type,
                                               Size( 2*dilate_size + 1, 2*dilate_size+1 ),
                                               Point( dilate_size, dilate_size ) );
    
    dilate(img, imgDilate, dilate_element);
    
    return imgDilate;
}