#include <iostream>
#define n 10
using namespace std;
int nums[n];
int target;
void get_nums()
{
	cout<<"Input "<<n<<" values: "<<endl;
	for (int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
}
void get_target()
{
	cout<<"Inout the target you want: target = ";
	cin>>target;
	cout<<endl;
}
void function()
{
	int i,j;
	int index=0;
	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (nums[i]+nums[j]==target)
			{
				index=1;
				cout<<"Target is found. "<<endl;
				cout<<"The index of the two value is: "<<"["<<i<<","<<j<<"]"<<endl;
				if (index==1)
				{
					break;
				}
			}
		}
		if (index==1)
		{
			break;
		}
	}
	if (index==0)
	{
		cout<<"Target has not been found. Input again. "<<endl;
		get_target();
	}
}
int main()
{
	get_nums();
	get_target();
	function();
	return 0;
}
