#!/bin/bash
CUR_PATH=$(cd `dirname $0`; pwd)
KERNEL_CONFIG_SRC="${CUR_PATH}/kernel/arch/arm64/configs/x9_ref_defconfig ${CUR_PATH}/device/semidrive/common/overlay_configs/gpu_non_vz.cfg"
KERNEL_ARCH=arm64
KERNEL_PATH=${CUR_PATH}/kernel
KERNEL_OUT=${CUR_PATH}/out_kernel
KERNEL_CROSS_COMPILE=${CUR_PATH}/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-androidkernel-
KERNEL_MAKE_TOOL=${CUR_PATH}/prebuilts/build-tools/linux-x86/bin/make
PATH_LZ4=${CUR_PATH}/prebuilts/misc/linux-x86/lz4
PATH_CLANG=/work1/PTG-4.3/buildsystem/android10/prebuilts/clang/host/linux-x86/clang-r349610/bin

echo ${KERNEL_PATH}
echo ${KERNEL_OUT}
cd ${KERNEL_PATH}
# 1. make defconfig
echo "make defconfig"
ARCH=${KERNEL_ARCH} CROSS_COMPILE=${KERNEL_CROSS_COMPILE} ./scripts/kconfig/merge_config.sh -O ${KERNEL_OUT} ${KERNEL_CONFIG_SRC} 

# 2. mrproper source
echo "make mrproper"
cd ..
PATH=/usr/bin:$PATH ${KERNEL_MAKE_TOOL} -C kernel mrproper -j8

# 3. compile Image
echo "compile Image"
cd ${KERNEL_PATH}
#PATH=${PATH_LZ4}:${PATH_CLANG}:/usr/bin:${PATH} CCACHE_NODIRECT=true ${KERNEL_MAKE_TOOL} \
#O=${KERNEL_OUT} ARCH=${KERNEL_ARCH} CROSS_COMPILE=${KERNEL_CROSS_COMPILE} CC=clang \
#KCFLAGS="-Wno-incompatible-pointer-types -Wno-parentheses-equality" KAFLAGS="" -j8 Image

# 3.1 generate the compile json
PATH=${PATH_LZ4}:${PATH_CLANG}:/usr/bin:${PATH} CCACHE_NODIRECT=true
bear make CCACHE_NODIRECT=true O=${KERNEL_OUT} ARCH=${KERNEL_ARCH} CROSS_COMPILE=${KERNEL_CROSS_COMPILE} CC=clang \
KCFLAGS="-Wno-incompatible-pointer-types -Wno-parentheses-equality" KAFLAGS=""

# 4. compile modules

