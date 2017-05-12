#include<stdlib.h>
#include<stdio.h>
#include"com_jiangwei_JniTest.h"

JNIEXPORT jstring JNICALL Java_com_jiangwei_JniTest_getStringFromC
(JNIEnv* env, jclass jclz){
    return (**env).NewStringUTF(env, "hello Java,I am C");
}