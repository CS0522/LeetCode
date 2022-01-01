/*Employee 表包含所有员工，他们的经理也属于员工。每个员工都有一个 Id，此外还有一列对应员工的经理的 Id。
+----+-------+--------+-----------+
| Id | Name  | Salary | ManagerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | NULL      |
| 4  | Max   | 90000  | NULL      |
+----+-------+--------+-----------+
给定 Employee 表，编写一个 SQL 查询，该查询可以获取收入超过他们经理的员工的姓名。在上面的表格中，Joe 是唯一一个收入超过他的经理的员工。
+----------+
| Employee |
+----------+
| Joe      |
+----------+
*/
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
class EmployeeEarning
{
    private:
        int Id;
        int ManagerId;
        string Name;
        int Salary;
    public:
        EmployeeEarning()
        {
            cout<<"Input the employee's Id, name, salary, and his manager's Id(If no manager, input 0): "<<endl;
            cout<<"Id: ";
            cin>>Id;
            cout<<"Name: ";
            cin>>Name;
            cout<<"Salary: ";
            cin>>Salary;
            cout<<"ManagerId: ";
            cin>>ManagerId;
        }
        int get_Id()
        {
            return Id;
        }
        int get_ManagerId()
        {
            return ManagerId;
        }
        string get_Name()
        {
            return Name;
        }
        int get_Salary()
        {
            return Salary;
        }
};
class Solution
{
    private:
        map<int,EmployeeEarning>Table;
    public:
        void initial_table();
        void salary_cmp();
};
void Solution::initial_table()
{
    cout<<"Input the number of the employees: ";
    int n;
    cin>>n;
    while(n>0)
    {
        EmployeeEarning Temp;
        Table.insert(pair<int,EmployeeEarning>(Temp.get_Id(),Temp));
        n--;
    }
}
void Solution::salary_cmp()
{
    int index=0;
    map<int,EmployeeEarning>::iterator iter;
    for (iter=Table.begin();iter!=Table.end();iter++)
    {
        if (iter->second.get_ManagerId()==0)
        {
            continue;
        }
        else
        {
            if (iter->second.get_Salary()>Table[iter->second.get_ManagerId()].get_Salary())
            {
                cout<<iter->second.get_Name()<<"'s salary is more than his manager. "<<endl;
                index=1;
            }
            else
            {
                continue;
            }
        }
    }
    if (index==0)
    {
        cout<<"No employee's salary is more than his manager's. "<<endl;
    }
}
int main()
{
    Solution obj;
    obj.initial_table();
    obj.salary_cmp();
    system("pause");
    return 0;
}