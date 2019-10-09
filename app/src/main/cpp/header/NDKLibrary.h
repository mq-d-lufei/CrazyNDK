//
// Created by feaoes on 2018/9/11.
//

#include <jni.h>

#ifndef CRAZYNDK_NDKLIBRARY_H
#define CRAZYNDK_NDKLIBRARY_H

//__cplusplus是cpp中的自定义宏，那么定义了这个宏的话表示这是一段cpp的代码
//一般我们都将函数声明放在头文件，当我们的函数有可能被C或C++使用时，
//但我们无法确定函数是在c还是cpp里面被定义（cxx都算，如苹果是mm，google是cc），
//也就无法确定是否要将函数声明在extern "C"里，所以，我们应该添加extern "C"
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL Java_com_crazy_crazyndk_ndk_NDKLibrary_getStrigFromJNI
        (JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_com_crazy_crazyndk_ndk_NDKLibrary_getStrigFromJNIStatic
        (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif

#endif //CRAZYNDK_NDKLIBRARY_H
