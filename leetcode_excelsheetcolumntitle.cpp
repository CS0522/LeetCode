/*给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
例如：
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
示例 1：
输入：columnNumber = 1
输出："A"
示例 2：
输入：columnNumber = 28
输出："AB"
示例 3：
输入：columnNumber = 701
输出："ZY"
示例 4：
输入：columnNumber = 2147483647
输出："FXSHRXW"*/
//看成26进制，AB=1*26^1+2*26^0，ZY=26*26^1+25*26^0
#include <iostream>
#include <math.h>
#include <map>
#include <algorithm>
using namespace std;
class ExcelTitle
{
    private:
        map<char,int>excel_correspond;
        string column_title;
    public:
        ExcelTitle();
        void transform();
        void get_title();
};
ExcelTitle::ExcelTitle()//constructed successfully
{
    for (int i=0;i<26;i++)
    {
        excel_correspond.insert(pair<char,int>('A'+i,i+1));
    }
}
void ExcelTitle::get_title()
{
    cout<<"Input the excel column title: "<<endl;
    cin>>column_title;
}
void ExcelTitle::transform()
{
    int sum=0;
    for (int i=0;i<column_title.size();i++)
    {
        map<char,int>::iterator iter_temp;
        for (iter_temp=excel_correspond.begin();iter_temp!=excel_correspond.end();iter_temp++)
        {
            if (column_title[i]==iter_temp->first)
            {
                sum+=(iter_temp->second)*pow(26,column_title.size()-i-1);
            }
        }
    }
    cout<<"The correspond column number of the title is: "<<sum<<endl;
}
int main()
{
    ExcelTitle obj;
    obj.get_title();
    obj.transform();
    system("pause");
    return 0;
}