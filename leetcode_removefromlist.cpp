#include <iostream>
using namespace std;
struct list
{
    int val;
    struct list *pnext;
};
class solution
{
    private:
        struct list *order_list;
    public:
        struct list *set_list()
        {
            struct list *head=0,*temp,*tail=0;
            int temp_val;
            cout<<"Input the val:(Input -1 to stop) ";
            cin>>temp_val;
            while(temp_val>=0)
            {
                temp=(struct list*)malloc(sizeof(struct list));
                temp->val=temp_val;
                temp->pnext=0;
                if (!head)
                {
                    head=tail=temp;
                }
                else
                {
                    tail->pnext=temp;
                    tail=temp;
                }
                cout<<"Input the val:(Input -1 to stop) ";
                cin>>temp_val;
            }
            return head;
        }
        solution()
        {
            order_list=set_list();
        }
        void sort_list();
        void traverse_list();
        void function();
};
void solution::sort_list()
{
    cout<<"Starting sort the list......"<<endl;
    struct list *i;
    struct list *j;
    for (i=order_list;i!=NULL;i=i->pnext)
    {
        for (j=i->pnext;j!=NULL;j=j->pnext)
        {
            if (j->val<i->val)
            {
                int temp;
                temp=j->val;
                j->val=i->val;
                i->val=temp;
            }
        }
    }
    cout<<"Sorting the list is completed. "<<endl;
}
void solution::traverse_list()
{
    if (!order_list)
    {
        cout<<"The list is empty. "<<endl;
        return;
    }
    while (order_list)
    {
        cout<<order_list->val<<" ";
        order_list=order_list->pnext;
    }
    cout<<endl;
}
void solution::function()
{
    cout<<"Starting delete the repeat values...... "<<endl;
    struct list *i;
    struct list *j;
    for (i=order_list;i!=NULL;i=i->pnext)
    {
        cout<<"i "<<i->val<<endl;
        for (j=i->pnext;j!=NULL;j=j->pnext)
        {
            if (i->val==j->pnext->val)
            {
                j->pnext->val=0;
                j->pnext=j->pnext->pnext;
                j->pnext=0;
                free(j->pnext);
            }
        }
    }
    //traverse_list();
    cout<<"Deleting is completed. "<<endl;
}
int main()
{
    solution obj;
    obj.sort_list();
    obj.traverse_list();
    obj.function();
    system("pause");
    return 0;
}