#include <iostream>
using namespace std;
struct list
{
	int num;
	struct list *pnext;
};
struct list *create()
{
	struct list *head=0,*temp,*tail=0;
	int num_temp;
	cout<<"Input numbers by ascending order: (Input -1 to stop)"<<endl;
	cin>>num_temp;
	while(num_temp>0)
	{
		temp=new struct list[sizeof(struct list)];
		temp->num=num_temp;
		temp->pnext=0;
		if (!head)
		{
			head=temp=tail;
		}
		else
		{
			tail->pnext=temp;
			tail=temp;
		}
		cin>>num_temp;
	}
	cout<<"Input end. "<<endl;
	return head;
}
void get_list(struct list *head)
{
	while(head)
	{
		cout<<head->num<<" ";
		head=head->pnext;
	}
}
int main()
{
	struct list *head;
	head=create();
	get_list(head);
	return 0;
}
