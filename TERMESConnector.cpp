#include "TERMESConnector.h"
#include "ColorDetector.h"
#include <stdio.h>
#include <iostream>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

VideoCapture capture;
Mat latestImage;

JNIEXPORT jintArray JNICALL Java_TERMESConnector_getKeypoints (JNIEnv *env, jclass)
{
    jint input[3];
    
    jint res = ColorDetection(latestImage, Scalar(100,250,100), Scalar(200,255,200), 3.0, 100, input);
    
    jintArray newArr = env->NewIntArray(3);
    env->SetIntArrayRegion(newArr, 0, 3, input);
    return newArr;
}

JNIEXPORT jbyteArray JNICALL Java_TERMESConnector_getNextFrame (JNIEnv *env, jclass)
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

JNIEXPORT jbyteArray JNICALL Java_TERMESConnector_getNextOverheadFrame (JNIEnv *env, jclass)
{
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

JNIEXPORT jbyteArray JNICALL Java_TERMESConnector_getNextThresholdFrame (JNIEnv *env, jclass)
{
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
    //string filename = "/Users/Nikolaj/Developer/TermiteTracker/Media/myrevideo2.mp4";
    string filename = "C:\\Users\\hfl.DELEGATE\\Desktop\\Github\\TermiteTracker\\Media\\myrevideo2.mp4";
    
    capture.open(filename);
    waitKey(2000);
    
    if (!capture.isOpened()) {
        cout << "Cannot open file/device!" << endl;
    }
}

JNIEXPORT void JNICALL Java_TERMESConnector_releaseCamera (JNIEnv *, jclass)
{
    capture.release();
}

JNIEXPORT void JNICALL Java_TERMESConnector_setLowerThresholdR (JNIEnv *, jclass, jint R)
{
    cout << "Lower Threshold R is now set to " << R << endl;
}

JNIEXPORT void JNICALL Java_TERMESConnector_setLowerThresholdG (JNIEnv *, jclass, jint G)
{
    cout << "Lower Threshold G is now set to " << G << endl;
}

JNIEXPORT void JNICALL Java_TERMESConnector_setLowerThresholdB (JNIEnv *, jclass, jint B)
{
    cout << "Lower Threshold B is now set to " << B << endl;
}

JNIEXPORT jint JNICALL Java_TERMESConnector_getLowerThresholdR (JNIEnv *, jclass)
{
    return 10;
}

JNIEXPORT jint JNICALL Java_TERMESConnector_getLowerThresholdG (JNIEnv *, jclass)
{
    return 20;
}

JNIEXPORT jint JNICALL Java_TERMESConnector_getLowerThresholdB (JNIEnv *, jclass)
{
    return 30;
}

JNIEXPORT void JNICALL Java_TERMESConnector_setUpperThresholdR (JNIEnv *, jclass, jint R)
{
    cout << "Upper Threshold R is now set to " << R << endl;
}

JNIEXPORT void JNICALL Java_TERMESConnector_setUpperThresholdG (JNIEnv *, jclass, jint G)
{
    cout << "Upper Threshold G is now set to " << G << endl;
}

JNIEXPORT void JNICALL Java_TERMESConnector_setUpperThresholdB (JNIEnv *, jclass, jint B)
{
    cout << "Upper Threshold B is now set to " << B << endl;
}

JNIEXPORT jint JNICALL Java_TERMESConnector_getUpperThresholdR (JNIEnv *, jclass)
{
    return 40;
}

JNIEXPORT jint JNICALL Java_TERMESConnector_getUpperThresholdG (JNIEnv *, jclass)
{
    return 50;
}

JNIEXPORT jint JNICALL Java_TERMESConnector_getUpperThresholdB (JNIEnv *, jclass)
{
    return 60;
}

