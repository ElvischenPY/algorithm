#include <stdio.h>

unsigned int func(void)
{
	static unsigned int buf = 22;
	printf("%s-%d  the buf is %x\n",__func__,__LINE__,buf);
	return 0;
}

int main()
{
	func();
	printf("the p is \n");
	return 0;

}




