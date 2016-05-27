#include <stdio.h>

typedef unsigned char uint8_t ;
typedef unsigned long uint32_t;


void arry_rank(uint32_t arry[],uint8_t length)
{
	uint8_t i, j;

	for(i=1;i<length-1;i++)
    {
        for(j=0;j<length-i;j++)
        {
            if(arry[j]>arry[j+1])
            {
                arry[j] = arry[j+1] + arry[j] - (arry[j+1] = arry[j]);
            }
        } 
    }

}


int main(void)
{
	uint32_t arry_a[] = { 12 , 3, 44,1,99,3333,0,23};
	uint8_t len = sizeof(arry_a)/sizeof(uint32_t);
	int i=0;
	printf("before : ");
	for(i=0;i<len;i++)
		printf("%lu \t\t",arry_a[i]);
	printf("\n");

	arry_rank(arry_a,len);

	printf("after : ");
	for(i=0;i<len;i++)
		printf("%lu\t\t",arry_a[i]);
	printf("\n");
	
	return 0;
}



