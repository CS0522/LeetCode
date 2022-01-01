#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
	private:
		string haystack;
		string needle;
	public:
		void get_string();
		void function();
};
void solution::get_string()
{
	cout<<"Input the haystack string: "<<endl;
	cin>>haystack;
	cout<<"Input the needle string: "<<endl;
	cin>>needle;
}
void solution::function()
{
	vector<int>index;
	vector<int>result;
	int needle_size=needle.size();
	int judge_index=1;
	int i;
	int temp=0;
	for (i=0;i<haystack.size();i++)
	{
		if (needle[0]==haystack[i])
		{
			index.push_back(i);
		}
	}
	for (i=0;i<index.size();i++)
	{
		int j;
		for (j=index[i];j<index[i]+needle.size();j++)
		{
			if (haystack[j]!=needle[j-index[i]])
			{
				judge_index=0;
			}
			else
			{
				judge_index=1;
			}
		}
		if (judge_index==1)
		{
			result.push_back(index[i]);
		}
	}
	if (result.empty())
	{
		cout<<"-1"<<endl;
	}
	else
	{
		cout<<result[0]<<endl;
	}
}
int main()
{
	solution obj;
	obj.get_string();
	obj.function();
	return 0;
}
