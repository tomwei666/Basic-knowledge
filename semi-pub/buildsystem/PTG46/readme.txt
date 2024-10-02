1. mp/safety的command.json的增加.

    在rtos/ssdk下的build.sh中修改如下: 
    if [ ${CLEAR} == true ]; then
        make -C $ROOTDIR clean
    fi

    if [ ${MAKE_CONFIG} == true ]; then
        make -C $ROOTDIR make_configs
    elif [ ${TOOLCHAIN} == iar ]; then
            make -C $ROOTDIR iar
    elif [ ${TOOLCHAIN} == rapidstudio ]; then
            make -C $ROOTDIR rapidstudio
    else
         make -C $ROOTDIR -j8  ======> bear make -C $ROOTDIR -j8
    fi
	/home/tom/work1/PTG-4.6/buildsystem/rtos/ssdk/prebuilts/linux/gcc/arm/bin/arm-none-eabi-gcc

	%s/\"cc\"/\"\/home\/tom\/work1\/PTG-4.6\/buildsystem\/rtos\/ssdk\/prebuilts\/linux\/gcc\/arm\/bin\/arm-none-eabi-gcc\"/g

2. 
   
