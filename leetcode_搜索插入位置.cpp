#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
	private:
		vector<int>array;
		int val;
		int index;
	public:
		void get_array();
		void get_val();
		void bubblesort();
		void function();
		void insertsort();
		void traverse();
};
void solution::get_array()
{
	cout<<"Input the array:(-1 to stop) "<<endl;
	int i;
	int temp;
	for (i=0;;i++)
	{
		cin>>temp;
		if (temp==-1)
		{
			break;
		}
		array.push_back(temp);
	}
}
void solution::get_val()
{
	cout<<"Input the val you want to insert: "<<endl;
	cin>>val;
	array.push_back(val);
	index=0;
}
void solution::traverse()
{
	int i;
	for (i=0;i<array.size();i++)
	{
		if (array[i]==val)
		{
			index=1;
			cout<<"The index of the target value is: "<<i<<endl;
			break;
		}
	}
}
void solution::bubblesort()
{
	int i,j;
	for (i=0;i<array.size()-1;i++)
	{
		for (j=0;j<array.size()-1-i;j++)
		{
			if (array[j]>array[j+1])
			{
				int temp;
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
}
void solution::function()
{
	traverse();
	if (index==0)
	{
		insertsort();
		traverse();
	}
}
void solution::insertsort()
{
	int i,j;
	int temp;
	for (i=1;i<array.size();i++)
	{
		temp=array[i];
		for (j=i-1;j>=0;j--)
		{
			if (array[j]>temp)
			{
				array[j+1]=array[j];
			}
			else
			{
				break;
			}
	    }
		array[j+1]=temp;
	}
}
int main()
{
	solution obj;
	obj.get_array();
	obj.get_val();
	obj.bubblesort();
	obj.function();
	return 0;
}

