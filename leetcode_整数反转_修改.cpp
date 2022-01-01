#include <iostream>
#include <math.h>
using namespace std;
int x;
void get_x()
{
run:cout<<"Input the value: ";
    cout<<"x = ";
	cin>>x;
	if(x<-pow(2,31) || x>pow(2,31)-1)
	{
		cout<<"Error!"<<endl;
		goto run;
	}
	else
	{
		return;
	}
}
void reverse(int x)
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
		cout<<"Reverse x = -"<<sum<<endl;
	}
	else
	{
		cout<<"Reverse x = "<<sum<<endl;
	}
}
int main()
{
	get_x();
	reverse(x);
	return 0;
}
