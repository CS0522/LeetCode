#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Stockbesttime
{
    private:
        vector<int>Stock;
        int MaxProfit;
    public:
        void get_stock();
        void function();
};
void Stockbesttime::get_stock()
{
    MaxProfit=0;
    cout<<"Input the stock(Input 0 to stop): "<<endl;
    int temp;
    cin>>temp;
    while (temp)
    {
        Stock.push_back(temp);
        cin>>temp;
    }
    return;
}
void Stockbesttime::function()
{
    int i,j;
    int Index_Buy=0,Index_Sell=0;
    for (i=0;i<Stock.size();i++)
    {
        for (j=i+1;j<Stock.size();j++)
        {
            if (Stock[j]>Stock[i] && Stock[j]-Stock[i]>MaxProfit)
            {
                MaxProfit=Stock[j]-Stock[i];
                Index_Buy=i+1;
                Index_Sell=j+1;
            }
        }
    }
    cout<<"The max profit is: "<<MaxProfit<<endl;
    cout<<"Buy at the "<<Index_Buy<<" day, and sell it at the "<<Index_Sell<<" day. "<<endl;
}
int main()
{
    Stockbesttime Obj;
    Obj.get_stock();
    Obj.function();
    system("pause");
    return 0;
}
