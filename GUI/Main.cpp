#include "Main.h"

JNIEXPORT jstring JNICALL Java_Main_test  (JNIEnv *env, jclass)
{
	return env->NewStringUTF("LOOK MOM, I DID IT!!");
}
