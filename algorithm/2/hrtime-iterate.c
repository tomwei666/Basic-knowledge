#include <stdio.h>
#include <string.h>
#include "hrtime-iterate.h"

enum  hrtimer_base_type {
	HRTIMER_BASE_MONOTONIC,
	HRTIMER_BASE_REALTIME,
	HRTIMER_BASE_BOOTTIME,
	HRTIMER_BASE_TAI,
	HRTIMER_MAX_CLOCK_BASES,
};
struct kobject {
    struct list_head list;
    char name[20];
    int len;
};

struct hrtimer_clock_base {
	int			index;
    struct list_head list;
	struct hrtimer_cpu_base *cpu_base;
};

struct hrtimer_cpu_base {
	unsigned int            active_bases;
	struct hrtimer_clock_base   clock_base[HRTIMER_MAX_CLOCK_BASES];
};
struct hrtimer {
    struct list_head list;
    char name[20];
};
struct hrtimer_cpu_base hrtimer_cpu_base1; 
void enqueue_hrtimer(struct hrtimer *hrtimer,struct  hrtimer_clock_base * base)
{
	base->cpu_base->active_bases |= 1 << base->index;
	list_add_tail(&hrtimer->list,&base->list);
}

int main()
{
    struct kobject obj1,obj2,obj3,obj4;
    struct kobject *tmp;
    struct list_head *pos;
	struct hrtimer hrtimer1,hrtimer2,hrtimer3,hrtimer4;

    INIT_LIST_HEAD(&hrtimer_cpu_base1.clock_base[HRTIMER_BASE_MONOTONIC].list);
    INIT_LIST_HEAD(&hrtimer_cpu_base1.clock_base[HRTIMER_BASE_REALTIME].list);
    INIT_LIST_HEAD(&hrtimer_cpu_base1.clock_base[HRTIMER_BASE_BOOTTIME].list);
    INIT_LIST_HEAD(&hrtimer_cpu_base1.clock_base[HRTIMER_BASE_TAI].list);
	hrtimer_cpu_base1.clock_base[HRTIMER_BASE_MONOTONIC].index=HRTIMER_BASE_MONOTONIC;
	hrtimer_cpu_base1.clock_base[HRTIMER_BASE_REALTIME].index=HRTIMER_BASE_REALTIME;
	hrtimer_cpu_base1.clock_base[HRTIMER_BASE_BOOTTIME].index=HRTIMER_BASE_BOOTTIME;
	hrtimer_cpu_base1.clock_base[HRTIMER_BASE_TAI].index=HRTIMER_BASE_TAI;
	hrtimer_cpu_base1.clock_base[HRTIMER_BASE_MONOTONIC].cpu_base=&hrtimer_cpu_base1;
	hrtimer_cpu_base1.clock_base[HRTIMER_BASE_REALTIME].cpu_base=&hrtimer_cpu_base1;
	hrtimer_cpu_base1.clock_base[HRTIMER_BASE_BOOTTIME].cpu_base=&hrtimer_cpu_base1;
	hrtimer_cpu_base1.clock_base[HRTIMER_BASE_TAI].cpu_base=&hrtimer_cpu_base1;


	memcpy(hrtimer1.name,"hrtimer1",sizeof("hrtimer1"));
	memcpy(hrtimer2.name,"hrtimer2",sizeof("hrtimer2"));
	memcpy(hrtimer3.name,"hrtimer3",sizeof("hrtimer3"));
	memcpy(hrtimer4.name,"hrtimer4",sizeof("hrtimer4"));

	enqueue_hrtimer(&hrtimer1,&hrtimer_cpu_base1.clock_base[HRTIMER_BASE_MONOTONIC]);
	enqueue_hrtimer(&hrtimer2,&hrtimer_cpu_base1.clock_base[HRTIMER_BASE_MONOTONIC]);
	enqueue_hrtimer(&hrtimer3,&hrtimer_cpu_base1.clock_base[HRTIMER_BASE_REALTIME]);
	enqueue_hrtimer(&hrtimer4,&hrtimer_cpu_base1.clock_base[HRTIMER_BASE_REALTIME]);


	printf("tom %d\n",hrtimer_cpu_base1.active_bases);
	unsigned int active = hrtimer_cpu_base1.active_bases;
	struct hrtimer_clock_base *base = hrtimer_cpu_base1.clock_base;
	for (; active; base++, active >>= 1) {
		list_for_each(pos, &base->list) {
			tmp=list_entry(pos, struct hrtimer, list);
			printf("name=%s\n",tmp->name);
		}
	}
}
