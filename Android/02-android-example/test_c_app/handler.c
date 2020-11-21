#include <stdio.h>
#include <cutils/log.h>
#include <utils/Log.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include <sys/types.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <unistd.h>
#include <asm/types.h>
#include "handler.h"                                                                
void handler(int signo)
{
	printf("signo = %d\n", signo);
}
