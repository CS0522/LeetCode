#include <iostream>
using namespace std;

class Solution{
    public:
        void function();    
};

void Solution::function()
{
    for (int i = 1;i<10;i++)
    {
        for (int j = 1;j<=i;j++)
        {
            cout<<i<<" * "<<j<<" = "<<i*j<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Solution obj;
    obj.function();
    system("pause");
    return 0;
}