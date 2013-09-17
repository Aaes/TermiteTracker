#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include "opencv/cv.h"
#include "opencv/highgui.h"

using namespace std;
using namespace cv;

int runVideoCapture2(int argc, char *argv[]) {
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);

	CvCapture *capture = cvCreateFileCapture(argv[1]);
	IplImage *frame;

	while(1) {
		frame = cvQueryFrame(capture);
		if(!frame) break;

		cvShowImage("Example1", frame);

		char c = cvWaitKey(33);
		if( c == 27 ) break;
	}

	cvReleaseCapture( &capture );
	cvDestroyWindow( "Example1" );

	return 0;
}