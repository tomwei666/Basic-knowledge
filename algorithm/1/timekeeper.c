/*
 * 比如：一个时钟是1Hz.
 * timekeeper结构体:
 * cycle_interval 是 一个时间单位的number of clock cycle.
 * raw_interval   是 一个时间单位有多少ms.
 *
 * 例子：
 * 如果时钟频率是1Hz,如果cycle_interval = 3,这个单位时间内有3个clock cycle, raw_interval = 3000ms.
 * 
 * 需求是：
 * 在M个时钟周期中，把基于N的以2为底的指数的倍数的，更新到cycle_last中，同时把相应的时间更新到raw_sec中。
 * 
 * 例子：
 * 在21个始终周期里，cycle_interval = 4,显然: 31 = 16 + 8 + 4 +3
 * 应该cycle_last = 28
 * raw_interval = 3000(2^2+2^1+2^0)= 3000×7 = 21000
 */

#include <stdio.h>
#include <math.h>
struct timekeeper { 
	unsigned long cycle_interval;
	unsigned long raw_interval;
	unsigned long raw_sec;
	unsigned long cycle_last;
};

unsigned long off_cal(struct timekeeper * tkeeper, unsigned long offset, unsigned long shift) {
	unsigned long interval = tkeeper->cycle_interval << shift;
	 printf("tom %ld\n",shift);
	if(offset < interval)
		return offset;

	 offset -= tkeeper->cycle_interval << shift;
     tkeeper->cycle_last += interval;
	 tkeeper->raw_sec += tkeeper->raw_interval << shift;

	return offset;
}
int main()
{
	struct timekeeper timekeeper;
	struct timekeeper *timekeeper_p = &timekeeper;

	timekeeper_p->cycle_interval = 4;
	timekeeper_p->raw_interval = 3000;
	timekeeper_p->cycle_last = 0;
	timekeeper_p->raw_sec = 0;
	
	
	unsigned long m = 31;
	unsigned long val=0;
	unsigned long shift = 0;
	unsigned long offset = m;
	shift = log2(m) - log2(timekeeper_p->cycle_interval);
	
	while(offset >= timekeeper_p->cycle_interval) {
		offset = off_cal(timekeeper_p,offset,shift);
        if( offset < timekeeper_p->cycle_interval<<shift)
			shift--;
	}
	printf("tom shift=%ld %ld %ld\n",shift,timekeeper_p->raw_sec,timekeeper_p->cycle_last);
}
