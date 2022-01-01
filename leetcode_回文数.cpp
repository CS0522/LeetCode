#include <iostream>
#include <math.h>
using namespace std;
int get_value()
{
	int x;
	cout<<"Input a value for x: ";
	cin>>x;
	return x;
}
int reverse(int x)
{
	int sum=0;
	int n=abs(x);
	for (;n>0;)
	{
		sum=sum*10+n%10;
		n=n/10;
	}
	if (x<0)
	{
		return -sum;
	}
	else
	{
		return sum;
	}
}
void function_judge()
{
	int n;
	n=get_value();
	if (n==reverse(n))
	{
		cout<<"True."<<endl;
	}
	else
	{
		cout<<"False."<<endl;
	}
}
int main()
{
	function_judge();
	return 0;
}
