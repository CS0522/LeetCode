#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
class stringcollection
{
	private:
		vector<string>string_album;
	public:
		void input_string();
		void function();
};
void stringcollection::input_string()
{
	string temp;
	cout<<"Input a string(input 0 to stop): "<<endl;
	temp="1";
	string stop_string="0";
	while(temp!=stop_string)
	{
	    cin>>temp;
	    if (temp==stop_string)
	    {
	    	break;
		}
	    string_album.push_back(temp);
	}
}
void stringcollection::function()
{
	int i,j;
	int index=1;
	int count=0;
	for (i=0;i<string_album[0].size();i++)
	{
		char temp;
		temp=string_album[0][i];
		for (j=0;j<string_album.size();j++)
		{
			if (temp!=string_album[j][i])
			{
				index=0;
				break;
			}
		}
		if (index==0)
		{
			break;
		}
		count++;
	}
    for (i=0;i<count;i++)
	{
		cout<<string_album[0][i];
	}
	cout<<endl;
}
int main()
{
	stringcollection obj;
	obj.input_string();
	obj.function();
	return 0;
}
