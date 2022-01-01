#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
    private:
        int n;
    public:
        solution(int n)
        {
            this->n=n;
        }
        void climbstair();
};
void solution::climbstair()//the algorithm is: f(n)=f(n-1)+f(n-2)
{
    //while being at the n floor, can take 1 step from n-1 floor, or take 2 steps from n-2 floor, so:
    int i;
    vector<int>method;
    for (i=1;i<=n;i++)
    {
        if (i==1)
        {
            method.push_back(1);
        }
        else if (i==2)
        {
            method.push_back(2);
        }
        else
        {
            method.push_back(method[i-3]+method[i-2]);
        }
    }
    cout<<"The methods to climbing "<<n<<" floors is: "<<method[n-1]<<endl;
}
int main()
{
    int n;
    cout<<"Input the number of the floor you want to climb: "<<endl;
    cin>>n;
    solution obj(n);
    obj.climbstair();
    system("pause");
    return 0;
}