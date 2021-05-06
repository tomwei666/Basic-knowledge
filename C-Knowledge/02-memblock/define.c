#include <stdio.h>
struct memblock_region { 
    int base;
    int size;
};
struct memblock_type {
	unsigned long cnt;	/* number of regions */
	unsigned long max;	/* size of the allocated array */
	struct memblock_region *regions;
	char *name;
};
#define INIT_MEMBLOCK_REGIONS   128

struct memblock {
	struct memblock_type memory;
	struct memblock_type reserved;
};
#define for_each_memblock(memblock_type, region)					\
	for (region = memblock.memblock_type.regions;					\
	     region < (memblock.memblock_type.regions + memblock.memblock_type.cnt);	\
	     region++)

#define for_each_memblock_type(memblock_type, rgn)			\
	for (idx = 0, rgn = &memblock_type->regions[0];			\
	     idx < memblock_type->cnt;					\
	     idx++, rgn = &memblock_type->regions[idx])

static struct memblock_region memblock_memory_init_regions[INIT_MEMBLOCK_REGIONS];
static struct memblock_region memblock_reserved_init_regions[INIT_MEMBLOCK_REGIONS];

 struct memblock memblock = {
	.memory.regions         = memblock_memory_init_regions,
	.memory.cnt             = 1,  
	.memory.name            = "memory",
	.reserved.regions       = memblock_reserved_init_regions,
	.reserved.cnt           = 1,  
	.reserved.name          = "reserved",
    };

int main()
{
    memblock.memory.cnt = 2;
    memblock.memory.regions[0].base = 0x100;
    memblock.memory.regions[0].size = 0x100;
    memblock.memory.regions[1].base = 0x200;
    memblock.memory.regions[1].size = 0x100;
    struct memblock_region *reg;
    for_each_memblock(memory, reg) {
	printf("tom memory base=%x size=%x\n",reg->base,reg->size);
    }
   
    printf("tom here\n");
}
