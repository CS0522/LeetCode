#include <iostream>
using namespace std;
class solution
{
    private:
        int x;
    public:
        solution(int _x)
        {
            this->x=_x;
        }
        void sqrt();
};
void solution::sqrt()
{
    int i;
    for (i=0;i<x;i++)
    {
        if (i*i<=x && (i+1)*(i+1)>=x)
        {
            cout<<"sqrt(x) = "<<i<<endl;
            break;
        }
    }
}
int main()
{
    int x;
    cout<<"Input the 'x' you want to be squared: "<<endl;
    cin>>x;
    solution obj(x);
    obj.sqrt();
    system("pause");
    return 0;
}