#include <iostream>
#include <cstring>
using namespace std;
char rome_number[15];
void get_rome()
{
	cout<<"Input a Rome Number: "<<endl;
	cin>>rome_number;
}
void translate()
{
	int count_I=0;
	int count_V=0;
	int count_X=0;
	int count_L=0;
	int count_C=0;
	int count_D=0;
	int count_M=0;
	char *p_rome=rome_number;
	for (;*p_rome!='\0';p_rome++)
	{
		if (*p_rome=='I')
		{
			count_I++;
		}
		else if (*p_rome=='V')
		{
			count_V++;
		}
		else if (*p_rome=='X')
		{
			count_X++;
		}
		else if (*p_rome=='L')
		{
			count_L++;
		}
		else if (*p_rome=='C')
		{
			count_C++;
		}
		else if (*p_rome=='D')
		{
			count_D++;
		}
		else if (*p_rome=='M')
		{
			count_M++;
		} 
		if (*p_rome=='I' && *(p_rome+1)=='V')
		{
			count_I+=3;
			count_V--;
		}
		if (*p_rome=='I' && *(p_rome+1)=='X')
		{
			count_I+=8;
			count_X--;
		}
		if (*p_rome=='X' && *(p_rome+1)=='L')
		{
			count_X+=3;
			count_L--;
		}
		if (*p_rome=='X' && *(p_rome+1)=='C')
		{
			count_X+=8;
			count_C--;
		}
		if (*p_rome=='C' && *(p_rome+1)=='D')
		{
			count_C+=3;
			count_D--;
		}
		if (*p_rome=='C' && *(p_rome+1)=='M')
		{
			count_C+=8;
			count_M--;
		}
	}
	int sum;
	sum=count_I*1+count_V*5+count_X*10+count_L*50+count_C*100+count_D*500+count_M*1000;
	if (sum<=1 || sum>=3999)
	{
		cout<<"Error! Input again! "<<endl;
		get_rome();
	}
	else 
	{
		cout<<sum<<endl;
	}
}
int main()
{
	get_rome();
	translate();
	return 0;
}
