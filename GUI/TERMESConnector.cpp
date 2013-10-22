#include "TERMESConnector.h"
#include "ColorDetector.h"
#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace std;
using namespace cv;

VideoCapture capture;
Mat latestImage;

JNIEXPORT jstring JNICALL Java_TERMESConnector_test  (JNIEnv *env, jclass)
{
	return env->NewStringUTF("LOOK MOM, I DID IT!! 2");
}

JNIEXPORT jintArray JNICALL Java_TERMESConnector_getKeypoints (JNIEnv *env, jclass)
{
    jint input[3];
    
    jint *res = ColorDetection(latestImage, Scalar(100,250,100), Scalar(200,255,200), 3.0, 100, input);
    
    jintArray newArr = env->NewIntArray(3);
    env->SetIntArrayRegion(newArr, 0, 3, res);
    return newArr;
}

JNIEXPORT jbyteArray JNICALL Java_TERMESConnector_getNextFrame
(JNIEnv *env, jclass)
{
    capture >> latestImage;
    if (latestImage.empty())
        return NULL;
    
    //create a uchar vector
    vector<uchar> imageData;
    
    //fill it with the image as chars
    imencode(".jpg",latestImage, imageData);
    
    //convert vector<char> to jbyteArray
    jbyte* result_e = new jbyte[imageData.size()];
    jbyteArray result = env->NewByteArray(imageData.size());
    
    for (int i = 0; i < imageData.size(); i++) {
        result_e[i] = (jbyte)imageData[i];
    }
    env->SetByteArrayRegion(result, 0, imageData.size(), result_e);
    return result;
    
}

JNIEXPORT void JNICALL Java_TERMESConnector_start (JNIEnv *, jclass)
{
    string filename = "/Users/Nikolaj/Developer/TermiteTracker/Media/myrevideo2.mp4";
    
    capture.open(filename);
    waitKey(2000);
    
    if (!capture.isOpened()) {
        cout << "Cannot open file/device!" << endl;
    }
}

JNIEXPORT void JNICALL Java_TERMESConnector_releaseCamera
(JNIEnv *, jclass)
{
    capture.release();
}