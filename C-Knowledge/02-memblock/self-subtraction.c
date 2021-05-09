#include <stdio.h>
int test(int tmp) {
	printf("F=%s tmp=%d\n",__func__,tmp);
}
int main() {
	int tmp=2;
	printf("F=%s tmp=%d\n",__func__,tmp);
	test(tmp--);
	printf("F=%s tmp=%d\n",__func__,tmp);
	test(--tmp);
	printf("F=%s tmp=%d\n",__func__,tmp);
}
