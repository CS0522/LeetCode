#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
    private:
        string a;
        string b;
        int size_a;
        int size_b;
        int length;
        char carry;
    public:
        solution(string _a, string _b)
        {
            this->a=_a;
            this->b=_b;
            size_a=a.size();
            size_b=b.size();
            carry='0';
        }
        void make_size();//make size_a equal to size_b
        void addbinary();
};
void solution::make_size()
{
    if (size_a==size_b)
    {
        length=size_a;
        return;
    }
    while (size_a<size_b)
    {
        a='0'+a;
        size_a++;
    }
    while (size_b<size_a)
    {
        b='0'+b;
        size_b++;
    }
    length=size_a;
}
void solution::addbinary()
{
    vector<char>sum;
    int i;
    for (i=length-1;i>=0;i--)
    {
        char val;
        if (a[i]+b[i]+carry>='2'+'0'+'0')
        {
            val='0';
            carry='1';
            sum.push_back(val);
            if (i==0)
            {
                sum.push_back(carry);
            }
        }
        else
        {
            val=a[i]+b[i]+carry-'0'-'0';
            carry='0';
            sum.push_back(val);
        }
    }
    reverse(sum.begin(),sum.end());
    for (i=0;i<sum.size();i++)
    {
        cout<<sum[i];
    }
    cout<<endl;
}
int main()
{
    cout<<"Input two binary numbers: "<<endl;
    string a;
    string b;
    cin>>a;
    cin>>b;
    solution obj(a,b);
    obj.make_size();
    obj.addbinary();
    system("pause");
    return 0;
}