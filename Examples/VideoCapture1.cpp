#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include "opencv/cv.h"
#include "opencv/highgui.h"

using namespace std;
using namespace cv;

int runVideoCapture1(int argc, char *argv[]) {
	VideoCapture capture(argv[1]);

	if(!capture.isOpened()) {
		cout << "Video not opened" << endl;
	}

	namedWindow("window1", CV_WINDOW_AUTOSIZE);
	
	Mat frameReference;

	while(1) {
		capture.read(frameReference);
		//capture >> frameReference;
		if(frameReference.empty())
			break;

		imshow("window1", frameReference);
		
		int key = waitKey(33);
		if(key == 27)
			break;
	}

	return 0;
}