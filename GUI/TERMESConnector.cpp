#include "TERMESConnector.h"
#include <stdio.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace std;
using namespace cv;

JNIEXPORT jstring JNICALL Java_TERMESConnector_test  (JNIEnv *env, jclass)
{
	return env->NewStringUTF("LOOK MOM, I DID IT!! 2");
}

JNIEXPORT jdoubleArray JNICALL Java_TERMESConnector_getKeypoints (JNIEnv *env, jclass, jbyteArray javaArray)
{
    std::cout << "HEJ MOR 2" << std::endl;
    jdouble arr[] = {env->GetArrayLength(javaArray)};
    
    //imshow("LOLWINDOW", imread("/Users/Nikolaj/Developer/TermiteTracker/Media/4.jpg"));
    
    jdoubleArray newArr = env->NewDoubleArray(3);
    env->SetDoubleArrayRegion(newArr, 0, 3, arr);
    return newArr;
}

JNIEXPORT jbyteArray JNICALL Java_TERMESConnector_getFrame
(JNIEnv *env, jclass)
{
    //load an image
    Mat image = imread("/Users/Nikolaj/Developer/TermiteTracker/Media/blob.jpg");
    
    //create a uchar vector
    vector<uchar> imageData;
    
    //fill it with the image as chars
    imencode(".jpg",image, imageData);
    
    //convert vector<char> to jbyteArray
    jbyte* result_e = new jbyte[imageData.size()];
    jbyteArray result = env->NewByteArray(imageData.size());
    
    for (int i = 0; i < imageData.size(); i++) {
        result_e[i] = (jbyte)imageData[i];
    }
    env->SetByteArrayRegion(result, 0, imageData.size(), result_e);
    return result;
}