#include <iostream>
#include <cstring>
using namespace std;
class solution
{
    private:
        string s;
        int size;
    public:
        solution(string _s)
        {
            this->s=_s;
            size=s.size();
        }
        void function();
};
void solution::function()
{
    int i;
    int last_word_index;
    char blank_char=' ';
    for (i=0;i<size;i++)
    {
        if (s[i]==blank_char)
        {
            last_word_index=i;
        }
    }
    cout<<"The length of the last word is: "<<endl;
    cout<<size-last_word_index-1<<endl;
}
int main()
{
    /*string solution_str;
    cout<<"Input the string: ";
    cin>>solution_str;*/
    solution obj("hello world");
    obj.function();
    system("pause");
    return 0;
}