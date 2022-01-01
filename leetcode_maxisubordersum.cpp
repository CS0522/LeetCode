#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
    private:
        vector<int>array;
    public:
        void get_array();
        void print_vector();
        void function();
};
void solution::get_array()
{
    cout<<"Input the value:(Input -1 to stop) "<<endl;
    int temp=0;
    int i;
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
void solution::print_vector()
{
    vector<int>::iterator iter;
    for (iter=array.begin();iter!=array.end();iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
}
void solution::function()
{
    int i,j,m;
    int sum;
    int max=0;
    for (i=1;i<array.size();i++)//the lenth of the son array
    {
        for (j=0;j<array.size();j++)//the start index of the son array
        {
            sum=0;
            for (m=0;m<i;m++)//for circle to accumlate the addition
            {
                if (j+m<=array.size()-1)//check if the 'j+m' is larger than the array's size
                {
                    sum=sum+array[j+m];
                }
                else
                {
                    break;
                }
            }
            if (sum>max)
            {
                max=sum;
            }
        }
    }
    int temp;
    temp=max>sum?max:sum;
    cout<<temp<<endl;    
}
int main()
{
    solution obj;
    obj.get_array();
    obj.print_vector();
    obj.function();
    system("pause");
    return 0;
}
