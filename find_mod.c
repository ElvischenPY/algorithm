#include <stdio.h>

const static int refer_Value[]={	2403,2449,2493,2535,2575,
									2612,2651,2687,2721,2756,
									2786,2818,2846,2875,2903,
									2933,2957,2982,3007,3033,
};
const static int refer_ADC_Value[] = {	2045,2090,2135,2181,2226,
										2273,2317,2362,2408,2452,
										2499,2543,2590,2635,2680,
										2723,2770,2815,2860,2903,
};
int BinSearch(const int sSource[], int array_size, int key)  
{     
    int low = 0, high = array_size - 1, mid;
     // printf(" array_size=%d\n",array_size );
    while (low <= high)  
    {         
        mid = (low + high) / 2;//获取中间的位置  
          
        if ((sSource[mid] <= key) && (sSource[mid+1] >= key))              
            return mid; //找到则返回相应的位置  
        if (sSource[mid+1] < key)     
        	low = mid + 1;  //如果比key小，则往高的位置查找             
        else  
            high = mid - 1; //如果比key大，则往低的位置查找
    }     
    return -1;    
}

int ADC_to_Value(int getValue)
{
	int index = 0;
	int Value_V = 0;
	int len = sizeof(refer_ADC_Value)/sizeof(int);
		
//	printf("len=%d   getValue=%d\n",len-1,getValue);
	if(getValue <= refer_ADC_Value[0]){
		Value_V = refer_Value[0];
		printf("index=%d   getValue=%d    Value_V= %d \n",0,getValue,Value_V);
	}else if (getValue >= refer_ADC_Value[len-1]){
		Value_V = refer_Value[len-1];
		printf("index=%d   getValue=%d    Value_V= %d \n",len-1,getValue,Value_V);
	}else{
		index = BinSearch(refer_ADC_Value,len,getValue);
		//printf("ADC  %d <=  %d  <= %d \n",refer_ADC_Value[index],getValue,refer_ADC_Value[index+1]);
		//printf("Value_V %d <=  %d  <= %d \n",refer_Value[index],(refer_Value[index]+refer_Value[index+1]+1)/2,refer_Value[index+1]);
		//temp1 = ((2 * (refer_Value[index+1] - refer_Value[index]) * (getValue - refer_ADC_Value[index])) / (refer_ADC_Value[index+1] - refer_ADC_Value[index])+1)/2;
		Value_V = ((2 * (refer_Value[index+1] - refer_Value[index]) * (getValue - refer_ADC_Value[index])) / (refer_ADC_Value[index+1] - refer_ADC_Value[index])+1)/2 + refer_Value[index];
		printf("index=%d   getValue=%d    Value_V= %d \n",index,getValue,Value_V);
	}
	return Value_V;

}

int main(void)
{

	int i = 2040;
	for(;i<2910;i++){
		ADC_to_Value(i);
	}
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



