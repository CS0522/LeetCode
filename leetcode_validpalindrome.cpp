/*给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:
输入: "race a car"
输出: false*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Palindrome
{
    private:
        string str_palindrome;
        vector<char>temp_palindrome;
    public:
        Palindrome(string temp_str)
        {
            this->str_palindrome=temp_str;
        }
        void palindrome_func();
};
void Palindrome::palindrome_func()
{
    for (int i=0;i<str_palindrome.size();i++)
    {
        if (str_palindrome[i]>='a' && str_palindrome[i]<='z')
        {
            temp_palindrome.push_back(str_palindrome[i]);
        }
        if (str_palindrome[i]>='0' && str_palindrome[i]<='9')
        {
            temp_palindrome.push_back(str_palindrome[i]);
        }
        if (str_palindrome[i]>='A' && str_palindrome[i]<='Z')
        {
            char temp=str_palindrome[i];
            temp+=32;
            temp_palindrome.push_back(temp);
        }
        else
        {
            continue;
        }
    }
    vector<char>reverse_temp(temp_palindrome);
    reverse(reverse_temp.begin(), reverse_temp.end());
    int index=1;
    for (int i=0;i<reverse_temp.size();i++)
    {
        if (reverse_temp[i]!=temp_palindrome[i])
        {
            index=0;
        }
    }
    if (index)
    {
        cout<<"True."<<endl;
    }
    else
    {
        cout<<"False."<<endl;
    }
}
int main()
{
    string str_val;
    cout<<"Input the string that you want to check if it is a valid palindrome: "<<endl;
    cin>>str_val;
    Palindrome obj(str_val);
    obj.palindrome_func();
    system("pause");
    return 0;
}