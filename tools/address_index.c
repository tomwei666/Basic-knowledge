#include <stdio.h>
#include <stdlib.h>
#define PGDIR_MASK   0xffffff8000000000
#define PUD_MASK     0xffffffffc0000000
#define PMD_MASK     0xffffffffffe00000
#define PTE_MASK     0xfffffffffffff000

#define VA_BITS       48
#define PGDIR_SHIFT   39
#define PUD_SHIFT     30
#define PMD_SHIFT     21
#define PAGE_SHIFT    12

//#define PGDIR_SIZE          1<< PGDIR_SHIFT
//
#define PTRS_PER_PGD        (1 << (VA_BITS - PGDIR_SHIFT))
#define PGDIR_SIZE_1        PTRS_PER_PGD-1

#define PTRS_PER_PUD        (1 << (PGDIR_SHIFT - PUD_SHIFT))
#define PUD_SIZE_1          PTRS_PER_PUD-1


#define PTRS_PER_PMD        (1 << (PUD_SHIFT - PMD_SHIFT))
#define PMD_SIZE_1          PTRS_PER_PMD-1

#define PTRS_PER_PTE        (1 << (PMD_SHIFT - PAGE_SHIFT))
#define PTE_SIZE_1          PTRS_PER_PTE-1

int tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 'a' - 'A';
    }
    else
    {
        return c;
    }
}
long int htoi(char s[])  
{  
    long int i;  
    long int n = 0;  
    if (s[0] == '0' && (s[1]=='x' || s[1]=='X'))  
    {  
        i = 2;  
    }  
    else  
    {  
        i = 0;  
    }  
    for (; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >='A' && s[i] <= 'Z');++i)  
    {  
        if (tolower(s[i]) > '9')  
        {  
            n = 16 * n + (10 + tolower(s[i]) - 'a');  
        }  
        else  
        {  
            n = 16 * n + (tolower(s[i]) - '0');  
        }  
    }  
    return n;  
}  

#define PTRS_PER_PGD        (1 << (VA_BITS - PGDIR_SHIFT))
#define PGDIR_SIZE_1       PTRS_PER_PGD-1

int main(int argc,char *argv[])
{
	long  int i;
	long  int k;
	long  int k1;
	long int pgd_index,pud_index,pmd_index,pte_index;
	if(argc != 2) {
		printf("The address translate bin usage: ./test 0x1234\n");
		return 0;
	}
	k = htoi(argv[1]);

	pgd_index = ((k&PGDIR_MASK)>>PGDIR_SHIFT)&PGDIR_SIZE_1;
	pud_index = ((k&PUD_MASK)>>PUD_SHIFT)&PUD_SIZE_1;
	pmd_index = ((k&PMD_MASK)>>PMD_SHIFT)&PMD_SIZE_1;
	pte_index = ((k&PTE_MASK)>>PAGE_SHIFT)&PTE_SIZE_1;

	printf("address=%lx\n",k);
	printf("pgd_index=0x%lx pud_index=0x%lx pmd_index=%lx pte_index=%lx\n",pgd_index,pud_index,pmd_index,pte_index);


}
