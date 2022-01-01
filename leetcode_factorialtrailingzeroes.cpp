/*给定一个整数 n，返回 n! 结果尾数中零的数量。
示例 1:
输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。
示例 2:
输入: 5
输出: 1
解释: 5! = 120, 尾数中有 1 个零.
说明: 你算法的时间复杂度应为 O(log n) 。
*/
#include <iostream>
using namespace std;
class TrailingZero
{
    private:
        int n;
        int sum;
    public:
        TrailingZero(int _n):sum(1)
        {
            this->n=_n;
        }
        void factorial_func();
        void get_zero();
};
void TrailingZero::factorial_func()
{
    for (int i=n;i>0;i--)
    {
        sum*=i;
    }
    cout<<"The result is: "<<sum<<endl;
}
void TrailingZero::get_zero()
{
    int count=0;
    for (;sum%10==0;count++)
    {
        sum=sum/10;
    }
    cout<<"The number of zero in the result is: "<<count<<endl;
}
int main()
{
    cout<<"Input the 'n': ";
    int n;
    cin>>n;
    TrailingZero obj(n);
    obj.factorial_func();
    obj.get_zero();
    system("pause");
    return 0;
}