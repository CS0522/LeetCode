#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
class rometoint
{
	private:
		string rome_num;
	public:
		void input_string();
		void translate();
};
void rometoint::input_string()
{
	cout<<"Input the Rome Number: "<<endl;
	cin>>this->rome_num;
}
void rometoint::translate()
{
	int sum=0;
	map<char,int>rome;
	rome.insert(make_pair('I',1));
	rome.insert(make_pair('V',5));
	rome.insert(make_pair('X',10));
	rome.insert(make_pair('L',50));
	rome.insert(make_pair('C',100));
	rome.insert(make_pair('D',500));
	rome.insert(make_pair('M',1000));
	int i;
	for (i=0;i<rome_num.size();i++)
	{
		int temp;
		temp=rome[rome_num[i]];
		if (i==rome_num.size()-1 || rome[rome_num[i+1]]<=rome[rome_num[i]])
		{
			sum+=temp;
		}
		else
		{
			sum-=temp;
		}
	}
	if (sum<=1 || sum>=3999)
	{
		cout<<"Error! Input again! "<<endl;
		input_string();
		translate();
	}
	else 
	{
		cout<<sum<<endl;
	}
}
int main()
{
	rometoint obj;
	obj.input_string();
	obj.translate();
	return 0;
}
