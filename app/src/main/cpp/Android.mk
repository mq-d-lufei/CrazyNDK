LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := NDKLibrary
LOCAL_SRC_FILES := source\NDKLibrary.cpp
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)