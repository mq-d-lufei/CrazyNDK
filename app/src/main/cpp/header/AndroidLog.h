#ifndef LOG_H_
#define LOG_H_

#include "android/log.h"

#define APPNAME "ndk_log"

#define DEBUG true

#define LOGV(...) if(DEBUG) __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, __VA_ARGS__)
#define LOGD(...) if(DEBUG) __android_log_print(ANDROID_LOG_DEBUG , APPNAME, __VA_ARGS__)
#define LOGI(...) if(DEBUG) __android_log_print(ANDROID_LOG_INFO , APPNAME, __VA_ARGS__)
#define LOGW(...) if(DEBUG) __android_log_print(ANDROID_LOG_WARN , APPNAME, __VA_ARGS__)
#define LOGE(...) if(DEBUG) __android_log_print(ANDROID_LOG_ERROR , APPNAME, __VA_ARGS__)

#endif
