/*表1: Person
+-------------+---------+
| 列名         | 类型     |
+-------------+---------+
| PersonId    | int     |
| FirstName   | varchar |
| LastName    | varchar |
+-------------+---------+
PersonId 是上表主键
表2: Address
+-------------+---------+
| 列名         | 类型    |
+-------------+---------+
| AddressId   | int     |
| PersonId    | int     |
| City        | varchar |
| State       | varchar |
+-------------+---------+
AddressId 是上表主键
编写一个 SQL 查询，满足条件：无论 person 是否有地址信息，都需要基于上述两表提供 person 的以下信息：
FirstName, LastName, City, State
*/
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
class Person
{
    private:
        int PersonId;
        string FirstName;
        string SecondName;
    public:
        void initial_Person()
        {
            cout<<"Input the person's person Id and his first name and last name..."<<endl;
            cout<<"Person Id: ";
            cin>>PersonId;
            cout<<"FirstName: ";
            cin>>FirstName;
            cout<<"SecondName: ";
            cin>>SecondName;
        }
        int get_Id();
        string get_FirstName();
        string get_SecondName();
};
int Person::get_Id()
{
    return PersonId;
}
string Person::get_FirstName()
{
    return FirstName;
}
string Person::get_SecondName()
{
    return SecondName;
}
class Address
{
    private:
        int AddressId;
        int PersonId;
        string City;
        string State;
    public:
        void initial_Address()
        {
            cout<<"Input the person's address Id, person Id, city, and state..."<<endl;
            cout<<"Person Id: ";
            cin>>PersonId;
            cout<<"Adress Id: ";
            cin>>AddressId;
            cout<<"City: ";
            cin>>City;
            cout<<"State: ";
            cin>>State;
        }
        int get_AddressId();
        int get_PersonId();
        string get_City();
        string get_State();
};
int Address::get_AddressId()
{
    return AddressId;
}
int Address::get_PersonId()
{
    return PersonId;
}
string Address::get_City()
{
    return City;
}
string Address::get_State()
{
    return State;
}
class MainPanel
{
    private:
        map<int,Person>Person_map;
        map<int,Address>Address_map;
    public:
        void initial_info();
        void search_return();
};
void MainPanel::initial_info()
{
    int n;
    cout<<"Input the amount of the initializing data: ";
    cin>>n;
    cout<<"Initializing..."<<endl;
    while(n>0)
    {
        Person Temp_Person;
        Temp_Person.initial_Person();
run:    Address Temp_Address;
        Temp_Address.initial_Address();
        if (Temp_Address.get_PersonId()!=Temp_Person.get_Id())
        {
            cout<<"The Id is not correct. Please enter again. "<<endl;
            goto run;
        }
        Person_map.insert(pair<int,Person>(Temp_Person.get_Id(),Temp_Person));
        Address_map.insert(pair<int,Address>(Temp_Address.get_PersonId(),Temp_Address));
        n--;
    }
    cout<<"Initializing completed. "<<endl;
}
void MainPanel::search_return()
{
    cout<<"Input the person's Id that you want to seek for: ";
    int Id;
    cin>>Id;
    cout<<"The person's info you want to seek for is as follows: "<<endl;
    cout<<"Person Id: "<<Id<<endl;
    cout<<"Name: "<<Person_map[Id].get_FirstName()<<" ";
    cout<<Person_map[Id].get_SecondName()<<endl;
    cout<<"City: "<<Address_map[Id].get_City()<<endl;
    cout<<"State: "<<Address_map[Id].get_State()<<" "<<endl;
}
int main()
{
    cout<<"*******************SEARCH*******************"<<endl;
    MainPanel obj;
    obj.initial_info();
    obj.search_return();
    cout<<"*******************END*******************"<<endl;
    system("pause");
    return 0;
}