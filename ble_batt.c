#include <stdio.h>


typedef unsigned char uint8_t ;
typedef unsigned long uint32_t;

const static uint32_t refer_Value[]={	2403,2449,2493,2535,2575,
									2612,2651,2687,2721,2756,
									2786,2818,2846,2875,2903,
									2933,2957,2982,3007,3033,
};
const static uint32_t refer_ADC_Value[] = {	2045,2090,2135,2181,2226,
										2273,2317,2362,2408,2452,
										2499,2543,2590,2635,2680,
										2723,2770,2815,2860,2903,
};
static uint32_t BinSearch(const uint32_t sSource[], uint8_t array_size, uint8_t key)  
{
    uint8_t low = 0, high = array_size - 1, mid;
     // printf(" array_size=%d\n",array_size );
    while (low <= high)  
    {         
        mid = (low + high) / 2;
          
        if ((sSource[mid] <= key) && (sSource[mid+1] >= key))              
            return mid; 
        if (sSource[mid+1] < key)     
        	low = mid + 1;            
        else  
            high = mid - 1;
    }     
    return -1;    
}
static uint32_t ADC_to_Value(uint32_t adcValue)
{
	uint8_t index = 0;
	uint32_t referValue = 0;
	uint32_t Value = 0;
	uint8_t len = sizeof(refer_ADC_Value)/sizeof(uint32_t);
	
	if(adcValue <= refer_ADC_Value[0]){
		referValue = refer_Value[0];
	}else if(adcValue >= refer_ADC_Value[len-1]){
		referValue = refer_Value[len-1];
	}else{
		index = BinSearch(refer_ADC_Value,len,adcValue);
		referValue = ((2 * (refer_Value[index+1] - refer_Value[index]) * (adcValue - refer_ADC_Value[index])) / (refer_ADC_Value[index+1] - refer_ADC_Value[index])+1)/2 + refer_Value[index];
	}
	Value = ((2*adcValue*referValue/0xFFF)+1)/2;
	printf("index=%d,refer_ADC_Value=%d,refer_ADC_Value_1=%d\n",index,refer_ADC_Value[index],refer_ADC_Value[index+1]);
	printf("index=%d,refer_Value=%d,refer_Value_1=%d\n",index,refer_Value[index],refer_Value[index+1]);
    printf("adc=%d,referValue=%d,Value=%d\n\n",adcValue,referValue,Value);
	return Value;	
}

int main(void)
{

	ADC_to_Value(2092);
/*
	int i = 2040;
	for(;i<2910;i++){
		ADC_to_Value(i);
	}
	*/
	/*
	int getValue = 0;
	int index = 0;
	int temp = 0;
	int temp1 = 0;
	int len = sizeof(refer_ADC_Value)/sizeof(int);
	while(1){
		printf("-------\nenter value = ");
		scanf("%d",&getValue);
		printf("len=%d   getValue=%d\n",len-1,getValue);
		if(getValue <= refer_ADC_Value[0]){
			temp = refer_Value[0];
			printf("temp1=%d  temp=%d \n",temp1,temp);
			printf(" \n----------  \n\n");
		}else if (getValue >= refer_ADC_Value[len-1]){
			temp = refer_Value[len-1];
			printf("len=%d   getValue=%d\n",len,getValue);
			printf("temp1=%d  temp=%d \n",temp1,temp);
			printf(" \n----------  \n\n");	
		}else{
			index = BinSearch(refer_ADC_Value,len,getValue);
			printf("ADC  %d <=  %d  <= %d \n",refer_ADC_Value[index],getValue,refer_ADC_Value[index+1]);
			printf("Value_V %d <=  %d  <= %d \n",refer_Value[index],(refer_Value[index]+refer_Value[index+1]+1)/2,refer_Value[index+1]);
			temp1 = ((2 * (refer_Value[index+1] - refer_Value[index]) * (getValue - refer_ADC_Value[index])) / (refer_ADC_Value[index+1] - refer_ADC_Value[index])+1)/2;
			temp = ((2 * (refer_Value[index+1] - refer_Value[index]) * (getValue - refer_ADC_Value[index])) / (refer_ADC_Value[index+1] - refer_ADC_Value[index])+1)/2 + refer_Value[index];
			printf("temp1=%d  temp=%d \n",temp1,temp);
			printf(" \n----------  \n\n");
		}
	}
	*/
	return 0;
}



