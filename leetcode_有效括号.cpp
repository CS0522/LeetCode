#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
class solution
{
	private:
		map<char,int>bracket;
	public:
		void get_bracket();
		void function();
		int traverse(char bracket_char);
};
void solution::get_bracket()
{
	bracket.insert(map<char,int>::value_type('(',1));
	bracket.insert(map<char,int>::value_type('[',2));
	bracket.insert(map<char,int>::value_type('{',3));
	bracket.insert(map<char,int>::value_type(')',4));
	bracket.insert(map<char,int>::value_type(']',5));
	bracket.insert(map<char,int>::value_type('}',6));
}
int solution::traverse(char bracket_char)
{
	map<char,int>::iterator bracket_iter;
	for (bracket_iter=bracket.begin();bracket_iter!=bracket.end();bracket_iter++)
	{
		if (bracket_iter->first==bracket_char)
		{
			return bracket_iter->second;
			break;
		}
	}
}
void solution::function()
{
	cout<<"Input the brackets: "<<endl;
	char bracket_string[6];
	cin>>bracket_string;
	char a;
	int i;
	int index[6];
	int count=0;
	for (i=0;a!='\0';i++)
	{
		a=bracket_string[i];
		count++;
	}
	//cout<<count<<endl;
	for (i=0;i<count-1;i++)
	{
		index[i]=traverse(bracket_string[i]);
    }
	/*for (i=0;i<count-1;i++)
	{
		cout<<index[i]<<endl;
	}*/
	int temp=0;
	for (i=0;i<count-1;i++)
	{
		if (abs(index[count-i-2]-index[i])==3)
		{
			temp=1;
		}
		else
		{
			temp=0;
		}
	}
	if (temp==1 && (count-1)%2==0)
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
	solution obj;
	obj.get_bracket();
	obj.function();
	return 0;
}
