#include <iostream>
#define N 20
using namespace std;
class solution
{
	private:
		int array[N];
		int size;
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
		void func_delete(solution &obj);
};
void solution::func_delete(solution &obj)
{
	int i,j;
	int temp;
	int count=0;
	for (i=0;i<size;i++)
	{
		if (obj.array[i]==-1)
		{
			continue;
		}
		else
		{
			temp=obj.array[i];
		    for (j=i+1;j<size;j++)
		    {
			    if (obj.array[j]==temp)
			    {
				    obj.array[j]=-1;
				    count++;
			    }
		    }
		}
	}
	cout<<size<<endl;
	cout<<count<<endl;
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
	obj.func_delete(obj);
	return 0;
}
