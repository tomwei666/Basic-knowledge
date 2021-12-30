#include <stdio.h>
#include <math.h>
int global_accumulation = 0;


/* 需求: 
 * M=2^M1 N=2^N1 K=M/N K=2^K1
 * 需要把M中是N倍数的数都累积到accumulation中.
 * 分析:
 * K=M/N,则 2^K1= 2^M1/2^N1 <=====> 2^K1 = 2^(M1-N1) <===> K1=M1-N1
 * 1. K1 = M1 -N1
 * 2. M = N*(2^K1)+ N*(2^(K1-1))+......+ N*2
 * 当然: N*(2^(K1-1))不一定存在，可以通过下面语句判断:
 *  int interval = interval_tmp << shift;
 *  if(offset<interval)
 *  	return offset. 
 *
 * 步骤:
 * 1. 计算出 M/N 倍数的指数shift = log2(M) -log2(N)
 * 2. 先把 N* 2^shift 累积到accumulation中。
 * 3. 依次次轮询 offset -=M-N*2^(shift-i)，判断offset是否大于N*2^(shift-i-1),
 *    如果是，则accumulation累积N*2^(shift-i-1).
 * 举例:
 * M=252 N=8
 * log2(252)-log2(8)
 * log2(252)-log2(8) = log2(128)-log2(8)=4: 
 *  显然252-128=124,则124在8*2^(4-1),8*2^(4-2),8*2^(4-3)中。
 *
 */
int logarithmic_accumulation(int offset,int shift,int interval_tmp)
{
    int interval = interval_tmp << shift;

    if(offset<interval)
	return offset;
    offset -= interval;
    global_accumulation += interval;
    printf("tom offset=%d tmp=%d global_accumulation=%d\n",offset,interval,global_accumulation);

    return offset;
}
int update_value(int offset, int interval)
{
	int shift;	

	shift = (int)log2(offset) - (int)log2(interval);
	while(offset>=interval){
	    offset = logarithmic_accumulation(offset,shift,interval);
	    if(offset<interval<<shift)
		shift--;
	}
}
int main()
{
    update_value(272,8);
}
