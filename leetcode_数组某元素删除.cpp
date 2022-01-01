#include <iostream>
#define N 20
using namespace std;
class solution
{
	private:
		int array[N];
		int size;
		int val;
	public:
		solution()
		{
			cout<<"Input the values: "<<endl;
			int temp;
			int i=0;
			cin>>temp;
			while (temp>0)
			{
				array[i]=temp;
				cin>>temp;
				i++;
			}
			size=i;
		}
		void get_val()
		{
			cout<<"Input the val: "<<endl<<"val = ";
			cin>>val;
		}
		void func_delete(solution &obj);
};
void solution::func_delete(solution &obj)
{
	int i;
	int count=0;
	int index=0;
	for (i=0;i<size;i++)
	{
		if (val==obj.array[i])
		{
			obj.array[i]=-1;
			count++;
			index=1;
		}
	}
	if (index==0)
	{
		cout<<"Error. No value is found. "<<endl;
		get_val();
	}
	cout<<"The size of the new array is: "<<size-count<<endl;
	for (i=0;i<size;i++)
	{
		if (obj.array[i]!=-1)
		{
			cout<<obj.array[i]<<" ";
		}
	}
	cout<<endl; 
}
int main()
{
	solution obj;
	obj.get_val();
	obj.func_delete(obj);
	return 0;
}
