/*给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例 1：
输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
示例 2：
输入：numbers = [2,3,4], target = 6
输出：[1,3]
示例 3：
输入：numbers = [-1,0], target = -1
输出：[1,2]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class TwoSum
{
    private:
        vector<int>num_array;
        int target;
    public:
        TwoSum()
        {
            cout<<"Input the target: "<<endl;
            cin>>target;
            cout<<"Input values to initialize the number array:(Input 0 to stop) "<<endl;
            int temp;
            cin>>temp;
            while(temp)
            {
                num_array.push_back(temp);
                cin>>temp;
            }
        }
        void bubblesort();
        void function();
};
void TwoSum::bubblesort()
{
    for (int i=0;i<num_array.size()-1;i++)
    {
        for (int j=0;j<num_array.size()-i-1;j++)
        {
            if (num_array[j]>num_array[j+1])
            {
                int num_temp;
                num_temp=num_array[j];
                num_array[j]=num_array[j+1];
                num_array[j+1]=num_temp;
            }
        }
    }
    cout<<"The array after sorted. "<<endl;
    for (int i=0;i<num_array.size();i++)
    {
        cout<<num_array[i]<<" ";
    }
    cout<<endl;
}
void TwoSum::function()
{
    //two pointer
    int left,right;
    left=0;
    right=num_array.size()-1;
    if (left>right)
    {
        cout<<"Error!"<<endl;
        return;
    }

    while(left<right)
    {
        if (num_array[left]+num_array[right]<target)
        {
            left++;
        }
        else if (num_array[left]+num_array[right]>target)
        {
            right--;
        }
        else
        {
            int index1=left+1;
            int index2=right+1;
            cout<<"Found. "<<endl<<"Index1 = "<<index1<<endl;
            cout<<"Index2 = "<<index2<<endl;
            break;
        }
    }
}
int main()
{
    TwoSum obj;
    obj.bubblesort();
    obj.function();
    system("pause");
    return 0;
}
