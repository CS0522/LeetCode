/*给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
示例 1:
输入: prices = [7,1,5,3,6,4]
输出: 7
在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Stockbesttime
{
    private:
        vector<int>Prices;
        int MaxProfit;
    public:
        void get_prices();
        void max_profit();
};
void Stockbesttime::get_prices()
{
    cout<<"Input the prices(Input 0 to stop): "<<endl;
    int Temp;
    cin>>Temp;
    while(Temp)
    {
        Prices.push_back(Temp);
        MaxProfit=0;
        cin>>Temp;
    }
    return;
}
void Stockbesttime::max_profit()
{
    vector<int>Time;
    for (int i=0;i<Prices.size();i++)
    {
        if (Prices[i+1]>Prices[i])
        {
            MaxProfit=MaxProfit+Prices[i+1]-Prices[i];
        }
        else
        {
            Time.push_back(i);
        }
    }
    cout<<"The max profit is: "<<MaxProfit<<endl;
}
int main()
{
    Stockbesttime Obj;
    Obj.get_prices();
    Obj.max_profit();
    system("pause");
    return 0;
}