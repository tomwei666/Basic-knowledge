# Copyright 2016 The Android Open Source Project

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_CFLAGS := \
  -Wall \
  -Wno-sign-compare \
  -Wno-missing-field-initializers \
  -Wno-unused-parameter
LOCAL_SRC_FILES := \
  main.c \
  handler.c

LOCAL_CXX_STL := none

LOCAL_MODULE := test_c_app
include $(BUILD_EXECUTABLE)
#include $(BUILD_HOST_EXECUTABLE)
