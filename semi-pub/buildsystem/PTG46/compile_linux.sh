#!/bin/bash
CUR_PATH=$(cd `dirname $0`; pwd)
KERNEL_CONFIG_SRC="${CUR_PATH}/kernel/arch/arm64/configs/x9_ref_defconfig ${CUR_PATH}/device/semidrive/common/overlay_configs/gpu_non_vz.cfg"
KERNEL_ARCH=arm64
KERNEL_PATH=${CUR_PATH}/kernel
KERNEL_CROSS_COMPILE=${CUR_PATH}/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-androidkernel-
KERNEL_MAKE_TOOL=${CUR_PATH}/prebuilts/build-tools/linux-x86/bin/make
PATH_LZ4=${CUR_PATH}/prebuilts/misc/linux-x86/lz4
PATH_CLANG=${CUR_PATH}/prebuilts/clang/host/linux-x86/clang-r416183b/bin

#PATH_DEFCONFIG=${CUR_PATH}/prebuilts/build-tools/linux-x86/bin:/usr/bin:$PATH:${CUR_PATH}/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin
PATH=/home/tom/work1/PTG-4.6/buildsystem/android12/prebuilts/build-tools/linux-x86/bin:/usr/bin:${PATH}:/home/tom/work1/PTG-4.6/buildsystem/android12/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin
LLVM_ARGS="LD=ld.lld LLVM=1 LD=ld.lld LLVM=1"
KERNEL_MERGE_CONFIG=${CUR_PATH}/device/semidrive/common/tools/mergeconfig.sh

TARGET_KERNEL_SRC=kernel
KERNEL_CONFIG_SRC="${CUR_PATH}/kernel/arch/arm64/configs/x9sp_ref_ap1_defconfig ${CUR_PATH}/device/semidrive/common/overlay_configs/gpu_non_vz.cfg \
	${CUR_PATH}/kernel/arch/arm64/configs/sdrv_dbg.fragment ${CUR_PATH}/device/semidrive/common/overlay_configs/hacks.cfg" 
KERNEL_OUT=${CUR_PATH}/out_kernel
KERNEL_ARCH=arm64 

# 1. make defconfig
# $(KERNEL_CONFIG): $(KERNEL_CONFIG_SRC) | $(KERNEL_OUT)
#  $(hide) PATH=$(KERNEL_MAKE_TOOL_PATH):$(HOST_BIN_PATH):$$PATH:$(KERNEL_TOOLCHAIN_ABS) $(LLVM_ARGS) \ 
#  $(KERNEL_MERGE_CONFIG) $(TARGET_KERNEL_SRC) $(realpath $(KERNEL_OUT)) \
#  $(KERNEL_ARCH) $(KERNEL_CONFIG_SRC)
echo "make defconfig begin"
LD=ld.lld LLVM=1 LD=ld.lld LLVM=1 ${KERNEL_MERGE_CONFIG} ${TARGET_KERNEL_SRC} ${KERNEL_OUT} ${KERNEL_ARCH} ${KERNEL_CONFIG_SRC}
#${PATH} ${LLVM_ARGS} ${KERNEL_MERGE_CONFIG} ${TARGET_KERNEL_SRC} ${KERNEL_OUT} ${KERNEL_ARCH} ${KERNEL_CONFIG_SRC}
#${LLVM_ARGS} ${KERNEL_MERGE_CONFIG} ${TARGET_KERNEL_SRC} ${KERNEL_OUT} ${KERNEL_ARCH} ${KERNEL_CONFIG_SRC}

echo "make defconfig end"




# 2. mrproper source
#echo "make mrproper"
#cd ..
#PATH=/usr/bin:$PATH ${KERNEL_MAKE_TOOL} -C kernel mrproper -j8

# 3. compile Image
# PATH=/home/tom/work1/PTG-4.6/buildsystem/android12/prebuilts/misc/linux-x86/lz4:/home/tom/work1/PTG-4.6/buildsystem/android12/prebuilts/clang/host/linux-x86/clang-r416183b/bin:/usr/bin:$PATH \
# LD=ld.lld LLVM=1 LD=ld.lld LLVM=1 CCACHE_NODIRECT=true /home/tom/work1/PTG-4.6/buildsystem/android12/prebuilts/build-tools/linux-x86/bin/make -C kernel  \
#  O=/home/tom/work1/PTG-4.6/buildsystem/android12/out_kernel ARCH=arm64 CROSS_COMPILE=/home/tom/work1/PTG-4.6/buildsystem/android12/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-androidkernel- \
 #CC=clang KCFLAGS="-Wno-incompatible-pointer-types -Wno-parentheses-equality -fno-stack-protector" KAFLAGS="" \
 #GPUNONVZ=true IPCC_RPC_RPROC_MP=true SDRV_NEW_PROPERTY=true GPUNONVZ=true IPCC_RPC_RPROC_MP=true SDRV_NEW_PROPERTY=true -j8 Image
 
PATH=/home/tom/work1/PTG-4.6/buildsystem/android12/prebuilts/misc/linux-x86/lz4:/home/tom/work1/PTG-4.6/buildsystem/android12/prebuilts/clang/host/linux-x86/clang-r416183b/bin:/usr/bin:$PATH \
LD=ld.lld LLVM=1 LD=ld.lld LLVM=1 CCACHE_NODIRECT=true /home/tom/work1/PTG-4.6/buildsystem/android12/prebuilts/build-tools/linux-x86/bin/make -C kernel  \
 O=/home/tom/work1/PTG-4.6/buildsystem/android12/out_kernel ARCH=arm64 CROSS_COMPILE=/home/tom/work1/PTG-4.6/buildsystem/android12/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-androidkernel- \
CC=clang KCFLAGS="-Wno-incompatible-pointer-types -Wno-parentheses-equality -fno-stack-protector" KAFLAGS="" \
GPUNONVZ=true IPCC_RPC_RPROC_MP=true SDRV_NEW_PROPERTY=true GPUNONVZ=true IPCC_RPC_RPROC_MP=true SDRV_NEW_PROPERTY=true -j8 Image

echo "compile Image"
#cd ${KERNEL_PATH}
#PATH=${PATH_LZ4}:${PATH_CLANG}:/usr/bin:${PATH} CCACHE_NODIRECT=true ${KERNEL_MAKE_TOOL} \
#O=${KERNEL_OUT} ARCH=${KERNEL_ARCH} CROSS_COMPILE=${KERNEL_CROSS_COMPILE} CC=clang \
#KCFLAGS="-Wno-incompatible-pointer-types -Wno-parentheses-equality -fno-stack-protector" KAFLAGS="" \
#GPUNONVZ=true IPCC_RPC_RPROC_MP=true SDRV_NEW_PROPERTY=true GPUNONVZ=true IPCC_RPC_RPROC_MP=true SDRV_NEW_PROPERTY=true-j8 Image

# 3.1 generate the compile json
#PATH=${PATH_LZ4}:${PATH_CLANG}:/usr/bin:${PATH} CCACHE_NODIRECT=true \
#bear make CCACHE_NODIRECT=true O=${KERNEL_OUT} ARCH=${KERNEL_ARCH} CROSS_COMPILE=${KERNEL_CROSS_COMPILE} CC=clang \
#KCFLAGS="-Wno-incompatible-pointer-types -Wno-parentheses-equality" KAFLAGS=""
# 4. compile modules

# 4. bear产生json
PATH=/home/tom/work1/PTG-4.6/buildsystem/android12/prebuilts/misc/linux-x86/lz4:/home/tom/work1/PTG-4.6/buildsystem/android12/prebuilts/clang/host/linux-x86/clang-r416183b/bin:/usr/bin:$PATH
LD=ld.lld LLVM=1 LD=ld.lld LLVM=1 CCACHE_NODIRECT=true
bear make O=/home/tom/work1/PTG-4.6/buildsystem/android12/out_kernel ARCH=arm64 CROSS_COMPILE=/home/tom/work1/PTG-4.6/buildsystem/android12/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-androidkernel- \
 CC=clang KCFLAGS="-Wno-incompatible-pointer-types -Wno-parentheses-equality -fno-stack-protector" KAFLAGS="" \
 GPUNONVZ=true IPCC_RPC_RPROC_MP=true SDRV_NEW_PROPERTY=true GPUNONVZ=true IPCC_RPC_RPROC_MP=true SDRV_NEW_PROPERTY=true -j8 Image

#5.
# %s/\"cc\"/\"\/home\/tom\/work1\/PTG-4.6\/buildsystem\/android12\/prebuilts\/gcc\/linux-x86\/aarch64\/aarch64-linux-android-4.9\/bin\/aarch64-linux-androidkernel-gcc\"/gc







