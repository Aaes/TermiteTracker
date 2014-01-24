
#include <opencv2\opencv.hpp>
#include "plotter.h"
#include "Thresholding.h"
#include "ColorDetector.h"
#include <time.h>
#include <Windows.h>

using namespace std;
using namespace cv;

int plotterYDiffFromPixelX(int xPixels);
int plotterXDiffFromPixelY(int yPixels);
Point findAnt(Mat image);
void UpdateHeatMap(int map[5][5], Point p);
void adjustPlotter(int mobileX, int mobileY);
int plotterYFromMobileX(int mobileX);
int plotterXFromMobileY(int mobileY);

VideoCapture mobile;
VideoCapture overhead;

Mat frame;
Mat thresholdFrame;
Mat overheadFrame;

KeyPoint keyPoint;
vector<KeyPoint> keyPoints;

//cameras
int mobileWidth = 640;
int mobileHeight = 480;

//---- Plotter -----
int firstKnownX = 258;			//Plotter X dimension
int firstKnownY = 147;			//Plotter Y dimension

int arenaDimX = 500;			//500 units in plotter X dimension
int arenaDimY = 350;			//350 units in plotter Y dimension

//---- Statistics ----
int frameCount = 0;				//How many frames have been pulled from each of the cameras 
//int antFrameCount = 0;			//How many frames have ants in them
//int trackFrameCount = 0;		//How many frames have been eligible for tracking (tracking boolean is true=
int totalProcessingTime = 0;	//How much time have we spent on processing (excluding querying the frame, bookkeeping etc. - image processing only)

//int speedSum = 0;				//Sum of all computed speeds of the ants
//int speedCount = 0;				//Number of elements in the sum

clock_t programStart;			//When was the program started
clock_t programEnd;				//When was the program terminated
clock_t trackingStart;			//When was the last tracking started
clock_t trackingEnd;			//When was the last tracking terminated
//clock_t newAntFound;			//When was the most recent ant found?
//clock_t lastAntFound;			//When was the 2nd latest ant found?

int isTracking = 0;
int isScanning = 0;

//Heatmap
int heatmapDim = 20;
int heatmap[20][20];

//Average speed
//Etc..


//################# DLL Functions ##############################

extern "C" __declspec(dllexport) void GetHeatMap(int* map)
{

	memcpy(map, heatmap, 400 * sizeof(int));
}

extern "C" __declspec(dllexport) void GetKeyPoints(int* xs, int* ys, int count)
{
	int number = count < keyPoints.size() ? count : keyPoints.size();
	int firstIndex = keyPoints.size() - number;

	for(int i = firstIndex; i < keyPoints.size(); i++) {
		KeyPoint kp = keyPoints[i];
		xs[i - firstIndex] = kp.pt.x;
		ys[i - firstIndex] = kp.pt.y;
	}
}

extern "C" __declspec(dllexport) void StartUp()
{
	programStart = clock();

	if(!mobile.isOpened()) {
		mobile.open(1);
	}

	if(!overhead.isOpened()) {
		overhead.open(0);
	}
}

extern "C" __declspec(dllexport) void ShutDown()
{
	if(mobile.isOpened()) {
		mobile.release();
	}

	if(overhead.isOpened()) {
		overhead.release();
	}

	frame.release();
	thresholdFrame.release();
	overheadFrame.release();

	programEnd = clock();
}

extern "C" __declspec(dllexport) void StartTracking()
{
	isTracking = 1;
	trackingStart = clock();
}

extern "C" __declspec(dllexport) void StopScanning()
{
	isScanning = 0;
}

extern "C" __declspec(dllexport) void StopTracking()
{
	isTracking = 0;
	trackingEnd = clock();

	//Save statistics
	ofstream File("Statistics.txt");
	File << "------------------------ TERMES Termite Tracker Statistics File ---------------------------" << "\n";
	File << "Elapsed time: " << ((trackingEnd - trackingStart) / (double)CLOCKS_PER_SEC) << " seconds" <<  "\n";
	File << "Frames Processed: " << frameCount << "\n";
	File << "Total processing time: " << (totalProcessingTime / 1000) << " seconds" << "\n";
	File << "Ticks per second: " << (double)CLOCKS_PER_SEC << "\n\n";

	frameCount = 0;
	totalProcessingTime = 0;	

	File << "# Heatmap" << "\n";
	for (int x = 0; x < heatmapDim; x++) {
		for(int y = 0; y < heatmapDim; y++) {
			File<< heatmap[x][y] << ", ";
			heatmap[x][y] = 0;
		}
		File<<"\n";
	}
	File << "\n\n";

	File << "# KeyPoints (x, y)" << "\n";
	for(int i=0; i<keyPoints.size(); i++) {
		File << keyPoints[i].pt.x << ", " << keyPoints[i].pt.y << ", " << keyPoints[i].size << "\n";
	}
	keyPoints.clear();
	File << "\n\n";
	
	File << "------------------------ TERMES Termite Tracker Statistics File ---------------------------" << "\n";
}


extern "C" __declspec(dllexport) void Scan(int threshold, bool* success) {
	int x = 135;
	int y = 55;
	
	int res[3]; isScanning = 1;
	while(x <= 335 && isScanning) {
		gotoCoor(x, y);
		Sleep(400);

		mobile >> frame;
		overhead >> overheadFrame;
		
		ColorDetection(frame, threshold, 1.0, 1, res);
		if(!(res[0] == 0 && res[1] == 0 && res[2] == 0)) {
			break;
		}

		y += 20;
		if(y > 135) {
			y = 55;
			x += 30;
		}
	}

	//If the ant was found and user did not abort the scan, adjust plotter once
	//and skip a frame. 
	//
	//If this is not done, NextFrame will load a new frame and thus 
	//advance the ants position if the camera is not adjusted beforehand
	if(!(res[0] == 0 && res[1] == 0 && res[2] == 0) && isScanning) {
		int newX = plotterXFromMobileY(res[1]);
		int newY = plotterYFromMobileX(res[0]);

		gotoCoor(newX, newY);

		mobile >> frame;
		overhead >> overheadFrame;
	}

	//Report success if an ant was found and the process was not interrupted
	*success = !(res[0] == 0 && res[1] == 0 && res[2] == 0) && isScanning;
}

extern "C" __declspec(dllexport) void NextFrame(int threshold, int* frameTime, int* processingTime, int* averageProcessingTime)
{
	//Start clock
    clock_t start = clock();

	//Get a frame
	mobile >> frame;
	overhead >> overheadFrame;
	
    clock_t startProcessing = clock();

	//Locate ant
	int res[3];
	ColorDetection(frame, threshold, 1.0, 1, res);

    clock_t endProcessing = clock();

	//Log actual processing time
	//*processingTime = (( clock() - start ) / (double) CLOCKS_PER_SEC) * 1000;
	thresholdFrame = getThresholdImage();

	if(isTracking) 
	{
		//Increase number of processed frames
		frameCount++;

		//Check if ant was found
		if(res[0] != 0 || res[1] != 0 || res[2] != 0) {
			//antFrameCount++;
			//lastAntFound = newAntFound;
			//newAntFound = start;

			//Provide an ant speed if there are
			//keypoints enough to compute a speed
			if(keyPoints.size() > 1) {
				KeyPoint old = keyPoints[keyPoints.size() - 2];
				KeyPoint neww = keyPoints[keyPoints.size() - 1];
			
				//int distance = 0;
				//int time = ((double)(newAntFound - lastAntFound) / (double)CLOCKS_PER_SEC);
				//if(time > 0) {
				//	*speed = distance / time;	//mm / second
				//	speedSum += *speed;
				//	speedCount++;
				//	*average = (speedSum / speedCount);
				//}
			}

			//Save keypoint for drawing on mobile camera frame
			keyPoint = KeyPoint(res[0], res[1], res[2]);

			//Convert mobile frame coordinates to global plotter coordinates
			int newX = plotterXFromMobileY(res[1]);
			int newY = plotterYFromMobileX(res[0]);

			//Convert global ant location in plotter coordinates to overhead frame coordinates
			int overheadX = 460 - (newY * 1.041);
			int overheadY = 435 - (newX * 0.7078);

			//Save keypoint for drawing on overhead camera fram
			keyPoints.push_back(KeyPoint(overheadX, overheadY, clock()));

			//Update heatmap
			heatmap[overheadX / 32][overheadY / 24]++;

			//Adjust Plotter
			gotoCoor(newX, newY);

			//Skip blurry frames
			//mobile >> frame;
			//overhead >> overheadFrame;
			//
			mobile >> frame;
			overhead >> overheadFrame;
		
			clock_t end = clock();												
			*frameTime = ((end - start) / (double) CLOCKS_PER_SEC) * 1000;												//Frame time in milliseconds
			*processingTime = ((double)(endProcessing - startProcessing) / (double) CLOCKS_PER_SEC) * 1000;
		
			totalProcessingTime += (((double)(endProcessing - startProcessing) / (double) CLOCKS_PER_SEC) * 1000);		//Total time in milliseconds
			*averageProcessingTime = ((double)totalProcessingTime / (double)frameCount);								//Average in milliseconds
		}
	}
}

extern "C" __declspec(dllexport) void MobileCamera(char* buffer)
{
	memcpy(buffer, frame.data, frame.total() * frame.elemSize());
	frame.release();
}

extern "C" __declspec(dllexport) void OverheadCamera(char* buffer)
{
	memcpy(buffer, overheadFrame.data, overheadFrame.total() * overheadFrame.elemSize());
	overheadFrame.release();
}

extern "C" __declspec(dllexport) void ThresholdMobileCamera(char* buffer)
{
	memcpy(buffer, thresholdFrame.data, thresholdFrame.total() * thresholdFrame.elemSize());
	thresholdFrame.release();
}

extern "C" __declspec(dllexport) void GetAntPosition(int* x, int* y, int* size)
{
	*x = keyPoint.pt.x;
	*y = keyPoint.pt.y;
	*size = keyPoint.size;
}

//########### Plotter DLL functions ####################

//Ant was found in coordinate (mobileX, mobileY) 
//In the coordinate system of the mobile camera
void adjustPlotter(int mobileX, int mobileY) {
	int centerX = frame.cols / 2;
	int centerY = frame.rows / 2;

	int pixelDeltaX = centerX - mobileX;
	int pixelDeltaY = centerY - mobileY;

	int cameraMoveX = pixelDeltaX * -1.0;
	int cameraMoveY = pixelDeltaY * -1.0;

	int plotterDeltaY = plotterYDiffFromPixelX(cameraMoveX);
	int plotterDeltaX = plotterXDiffFromPixelY(cameraMoveY);

	moveDiff(plotterDeltaX, plotterDeltaY);
}

extern "C" __declspec(dllexport) void GoToCoordinate(int* x, int* y)
{
	gotoCoor(*x, *y);
}

extern "C" __declspec(dllexport) void MovePlotter(int* deltaX, int* deltaY)
{
	moveDiff(*deltaX, *deltaY);
}

extern "C" __declspec(dllexport) void GetPlotterLocation(int* x, int* y)
{
	getPlotterLocation(x, y);
}

//############## Coordinate Conversion ###################

int plotterYDiffFromPixelX(int pixels) {
	return ((pixels * 3.0 * 20) / 640) * -1.0;					
}

int plotterXDiffFromPixelY(int pixels) {
	return ((pixels * 2.2 * 31) / 480.0) * -1.0;					
}

int plotterYFromMobileX(int mobileX) {
	int pixelDiff = (mobileWidth / 2) - mobileX;
	int cameraMoveX = pixelDiff * -1;

	int currentPlotterX = 0, currentPlotterY = 0;
	getPlotterLocation(&currentPlotterX, &currentPlotterY);

	return currentPlotterY + plotterYDiffFromPixelX(cameraMoveX);
}

int plotterXFromMobileY(int mobileY) {
	int pixelDiff = (mobileHeight / 2) - mobileY;
	int cameraMoveY = pixelDiff * -1;

	int currentPlotterX = 0, currentPlotterY = 0;
	getPlotterLocation(&currentPlotterX, &currentPlotterY);

	return currentPlotterX + plotterXDiffFromPixelY(cameraMoveY);
}

//############## Ant Detection ############################

//Simple ant detection for test purposes - actual code can be found i ColorDetector.cpp
Point findAnt(Mat image) 
{
	cvtColor(image, image, CV_RGB2GRAY);
	threshold(image, image, 40, 255, 0);
		
	int xSum = 0, ySum = 0, count = 0;
	for(int i=0; i<image.rows; i++) {
		for(int j=0; j<image.cols; j++) {
			if(((int)image.at<uchar>(i, j)) == 0) {
				xSum += j;
				ySum += i;
				count++;
			}
		}
	}

	int x = (int)(xSum / count);
	int y = (int)(ySum / count);

	return Point(x, y);
}

//############# Statistics #####################

void UpdateHeatMap(int map[5][5], Point p) {
	double xJump = arenaDimX / 5;
	double yJump = arenaDimY / 5;
	
	int xIndex = 0, yIndex = 0;
	while(xIndex * xJump + xJump < p.x) xIndex++;
	while(yIndex * yJump + yJump < p.y) yIndex++;

	cout << "Updating index (" << xIndex << ", " << yIndex << ")" << endl;

	map[xIndex][yIndex]++;
}