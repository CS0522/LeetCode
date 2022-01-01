#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class YangHuiTriangle
{
    private:
        vector<vector<int>>Triangle;
        int RowNum;
    public:
        YangHuiTriangle(int temp_RowNum)
        {
            this->RowNum=temp_RowNum;
        }
        void triangle_func();
        void triangle_print();
        void return_row();
};
void YangHuiTriangle::triangle_print()
{
    vector<int>::iterator iter_column;
    vector<vector<int>>::iterator it_row;
    for (it_row=Triangle.begin();it_row!=Triangle.end();it_row++)
    {
        for (iter_column=(*it_row).begin();iter_column!=(*it_row).end();iter_column++)
        {
            cout<<*iter_column<<" ";
        }
        cout<<endl;
    }
}
void YangHuiTriangle::triangle_func()
{
    for (int i=1;i<=RowNum;i++)
    {
        Triangle.push_back(vector<int>(i,0));
    }
    for (int i=0;i<RowNum;i++)//'i' is the row
    {
        for (int j=0;j<=i;j++)//'j' is the column
        {
            if (j==0 || j==i)
            {
                Triangle[i][j]=1;
            }
            else
            {
                Triangle[i][j]=Triangle[i-1][j-1]+Triangle[i-1][j];
            }
        }
    }
}
void YangHuiTriangle::return_row()
{
    cout<<"Input the target row: "<<endl;
    int RowTemp;
    cin>>RowTemp;
    for (int j=0;j<Triangle[RowTemp-1].size();j++)
    {
        cout<<Triangle[RowTemp-1][j]<<" ";
    }
    cout<<endl;
}
int main()
{
    cout<<"Input the row of YangHui Triangle: "<<endl;
    int Row;
    cin>>Row;
    YangHuiTriangle Obj(Row);
    Obj.triangle_func();
    Obj.triangle_print();
    cout<<"Research a target row? "<<endl;
    cout<<"y or n: ";
    char Temp;
    cin>>Temp;
    switch (Temp)
    {
        case 'y':
        Obj.return_row();break;
        case 'n':
        break;
        default:
        break;
    }
    system("pause");
    return 0;
}