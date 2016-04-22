#include <iostream>

using namespace std;

void reverse(int[],int);
void output(int[],int);

int main(int argc, char const *argv[])
{
	/* code */
	int arry[] = {5 , 1 , 0 , 1 , 7 , 9 , 1 , 0};
	int length=sizeof(arry)/sizeof(int);
#if 0
	int a = 3 ,b = 5 ,c=0;

	cout<<a<<"\t\t"<<b<<"\t\t"<<c<<endl;
	a = a^b;
	cout<<a<<"\t\t"<<b<<"\t\t"<<c<<endl;
	b = a^b;
	cout<<a<<"\t\t"<<b<<"\t\t"<<c<<endl;
	a = a^b;
	cout<<a<<"\t\t"<<b<<"\t\t"<<c<<endl;

	cout<<a<<"\t\t"<<b<<"\t\t"<<c<<endl;
	a = b+a - ( b=a );
	cout<<a<<"\t\t"<<b<<"\t\t"<<c<<endl;
	c = (b = a);
	cout<<a<<"\t\t"<<b<<"\t\t"<<c<<endl;
	cout<<endl;
#endif

	output(arry,length);
	reverse(arry,length);
	output(arry,length);

	return 0;
}
void reverse(int arry[],int length)
{
	int left = 0;
	int right = length-1;
	while(left<right){

		//if(arry[left] != arry[right]){
			arry[left]  = arry[left] ^ arry[right];
			arry[right] = arry[left] ^ arry[right];
			arry[left]  = arry[left] ^ arry[right];
		//}

		//a = b+a - ( b=a );
		//arry[left] = arry[right] + arry[left] - (arry[right] = arry[left]);

		left++;
		right--;
	}
}
void output(int arry[],int length)
{
	for(int i = 0; i< length; i++){
		cout<<arry[i]<<"\t\t";
	}
	cout<<endl<<endl;
}

