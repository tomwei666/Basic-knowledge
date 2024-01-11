CXX=/work1/PTG-4.5/buildsystem/yocto/yocto-tool/sdcast/recipe-sysroot-native/usr/bin/aarch64-sdrv-linux/aarch64-sdrv-linux-g++
INCLUDE := -I ./include
INCLUDE += -I/usr/include/libdrm
INCLUDE += -I/work1/PTG-4.5/buildsystem/yocto/yocto-tool/sdcast/recipe-sysroot/usr/include
INCLUDE += -I/work1/PTG-4.5/buildsystem/yocto/yocto-tool/sdcast/recipe-sysroot/usr/include/c++/7.3.0
INCLUDE += -I/work1/PTG-4.5/buildsystem/yocto/yocto-tool/sdcast/recipe-sysroot/usr/include/c++/7.3.0/bits
INCLUDE += -I/work1/PTG-4.5/buildsystem/yocto/yocto-tool/sdcast/recipe-sysroot/usr/include/c++/7.3.0/aarch64-sdrv-linux
INCLUDE += -I${PWD}/../../libhwconverter/1.0-r0/include
LDFLAGS = -L/work1/PTG-4.5/buildsystem/yocto/yocto-tool/sdcast/recipe-sysroot/usr/lib -L/work1/PTG-4.5/buildsystem/yocto/yocto-tool/sdcast/recipe-sysroot-native/usr/lib


# LIBDRM_CFLAGS = $(shell pkg-config --cflags libdrm)
# LIBDRM_LIBS = $(shell pkg-config --libs libdrm)

CFLAGS = -g -O -Wall -fPIC  -Werror -Wno-poison-system-directories \
		-Wno-unused-variable

LDFLAGS = -fPIC -ldrm -lpthread -lhwconverter -ldrmdisplay

TARGET := libSdCast.so sdcast_test

SRCS = $(wildcard src/*.cpp)
OBJS := $(SRCS:%.cpp=%.o)

all: $(TARGET)
	$(info build all)

sdcast_test: test/main.o libSdCast.so
	$(CXX) $^ $(INCLUDE) $(LDFLAGS) -o $@ -std=c++14 --sysroot=/work1/PTG-4.5/buildsystem/yocto/yocto-tool/sdcast/recipe-sysroot

test/main.o:test/main.cpp
	$(CXX) -c $(CFLAGS) -lSdCast $(LDFLAGS) -o $@ $^ $(INCLUDE) -std=c++14 --sysroot=/work1/PTG-4.5/buildsystem/yocto/yocto-tool/sdcast/recipe-sysroot

libSdCast.so: $(OBJS)
	$(CXX) -shared $(LDFLAGS) -lEGL -lGLES_CM -o $@ $(OBJS) $(INCLUDE) -std=c++14 --sysroot=/work1/PTG-4.5/buildsystem/yocto/yocto-tool/sdcast/recipe-sysroot

%.o:%.cpp
	$(CXX) -c $(CFLAGS)  -lEGL -lGLES_CM -o $@ $^ $(INCLUDE) -std=c++14 --sysroot=/work1/PTG-4.5/buildsystem/yocto/yocto-tool/sdcast/recipe-sysroot

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
