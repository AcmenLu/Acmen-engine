LOCAL_PATH := $(call my-dir) 
include $(CLEAR_VARS)

LOCAL_MODULE := Acmen
NDK_APP_DST_DIR := ../../Mobile/Android/libs/$(TARGET_ARCH_ABI)
LOCAL_SRC_FILES := ../../../Mobile/Android/jni/acmenjni.cpp
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)