#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
    private:
        vector<int>array1;
        vector<int>array2;
        int size1;
        int size2;
    public:
        solution(int size1, int size2)
        {
            this->size1=size1;
            this->size2=size2;
            vector<int>array1(size1+size2);
            vector<int>array2(size2);
            
        }
        void get_array();
        void sort_array();
        void merge_array();
        void print_array();
};
void solution::get_array()
{
    cout<<"Input "<<size1<<" values for array1: "<<endl;
    int temp_val;
    int i;
    for (i=0;i<size1;i++)
    {
        cin>>temp_val;
        array1.push_back(temp_val);
    }
    cout<<"Input "<<size2<<" values for array2: "<<endl;
    for (i=0;i<size2;i++)
    {
        cin>>temp_val;
        array2.push_back(temp_val);
    }
    return;
}
void solution::print_array()
{
    int i;
    cout<<"array1: "<<endl;
    for (i=0;i<size1;i++)
    {
        cout<<array1[i]<<" ";
    }
    cout<<endl;
    for (i=0;i<size2;i++)
    {
        cout<<array2[i]<<" ";
    }
    cout<<endl;
}
void solution::merge_array()
{
    int i;
    for (i=0;i<size2;i++)
    {
        array1.push_back(array2[i]);
    }
}
void solution::sort_array()
{
    vector<int>::iterator iter;
    cout<<"Starting to sort the merged array......"<<endl;
    int i;
    int j;
    for (i=0;i<array1.size()-1;i++)
    {
        for (j=0;j<array1.size()-i-1;j++)
        {
            if (array1[j]>array1[j+1])
            {
                int temp;
                temp=array1[j+1];
                array1[j+1]=array1[j];
                array1[j]=temp;
            }
        }
    }
    for (iter=array1.begin();iter!=array1.end();iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
}
int main()
{
    cout<<"Input size1, and size2: "<<endl;
    int size1;
    int size2;
    cin>>size1;
    cin>>size2;
    solution obj(size1,size2);
    obj.get_array();
    //obj.print_array();
    obj.merge_array();
    obj.sort_array();
    system("pause");
    return 0;
}