#include <stdio.h>
#include <math.h>

unsigned int off_cal(unsigned int base, unsigned int offset, unsigned int shift, unsigned int *val) {
	unsigned int interval = base << shift;
	if(offset < interval)
		return offset;

	*val += interval;
	printf("val=%d",*val);
	offset = offset - interval;
	return offset;
}
int main()
{
	unsigned int m = 31;
	unsigned int base = 4;
	unsigned int val=0;
	unsigned int shift = 0;
	unsigned int offset = m;
	
	shift = log2(m) - log2(base);
	
	while(offset >= base) {
		offset = off_cal(base,offset,shift,&val);
        if( offset < base<<shift)
			shift--;
	}
	printf("m=%d base=%d val=%d\n",m,base,val);
}
