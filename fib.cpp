#include <iostream>

using namespace std;

int fib(int a)
{
	if(a <2 )
		return a;
	else 
		return fib(a-1)+fib(a-2);

}

int main(int argc, char const *argv[])
{
	for(int i = 0 ;i < 10; i++){
		cout<<i<<":  "<<fib(i)<<endl;
	}
	return 0;
}



