#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

using namespace std;
using namespace cv;

int runMasterThesis()
{
        const char      * wndName = "Source image",
                                * wndNameGray = "Gray img", 
                                * wndNameOut = "Out",
                                * filename = "blob.jpg";

        Mat src, gray, thresh, binary;
        Mat out;
        vector<KeyPoint> keyPoints;
        vector< vector <Point>> contours;
        vector< vector <Point>> approxContours;

        SimpleBlobDetector::Params params;
        params.minThreshold = 0;
        params.maxThreshold = 256;
        params.thresholdStep = 1;

        params.minArea = 0; 
        params.minConvexity = 0.0;
        params.minInertiaRatio = 0.00;

        params.maxArea = 8000;
        params.maxConvexity = 100000000;

        params.filterByColor = false;
        params.filterByCircularity = false;

        namedWindow( wndNameOut, CV_GUI_NORMAL );

        src = imread( filename, CV_LOAD_IMAGE_GRAYSCALE );
        line( src, Point(0, src.rows-1), Point( src.cols-1, src.rows-1 ), Scalar::all(255) );

        SimpleBlobDetector blobDetector( params );
        blobDetector.create("SimpleBlob");

        for(;;)
        {
                blobDetector.detect( src, keyPoints );
                //blobDetector.detectEx( src, keyPoints, contours );
                drawKeypoints( src, keyPoints, out, CV_RGB(0,255,0), DrawMatchesFlags::DEFAULT);
                approxContours.resize( contours.size() );

                for( int i = 0; i < contours.size(); ++i )
                {
                        approxPolyDP( Mat(contours[i]), approxContours[i], 4, 1 );
                        drawContours( out, contours, i, CV_RGB(rand()&255, rand()&255, rand()&255) );
                        drawContours( out, approxContours, i, CV_RGB(rand()&255, rand()&255, rand()&255) );
                }
                cout << "Keypoints " << keyPoints.size() << endl;
        
                imshow( wndNameOut, out );
                waitKey(0);
        }
}