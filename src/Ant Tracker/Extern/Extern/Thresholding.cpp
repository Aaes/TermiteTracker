
#include "Thresholding.h"
#include "opencv2\gpu\gpu.hpp"

Mat thresholdImage(Mat img, int threshold) {
	//Thresholding on GPU
	gpu::GpuMat src, gray, dst;
	src.upload(img);

	gpu::cvtColor(src, gray, CV_BGR2GRAY);
	gpu::threshold(gray, dst, threshold, 255.0, 0);

	Mat local;
	dst.download(local);

	return local;
}