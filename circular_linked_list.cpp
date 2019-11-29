#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *next;

	node(int x)
	{
		data=x;
		next=NULL;
	}
};

node *insert(node *head,node **tail,int y)
{
	if(head==NULL)
	{
		node *tmp=new node(y);
		head=tmp;
		(*tail)=tmp;
		return head;
	}

	node *tmp=new node(y);
	(*tail)->next=tmp;
	(*tail)=tmp;

	return head;
	

}

void print_list(node *head,int n)
{
	node *tmp=head;

	while(n--)
	{
		cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
	cout<<endl;
}

int main()
{
	node *head=NULL,*tail=NULL;
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int y;
		cin>>y;
		head=insert(head,&tail,y);
	}

	tail->next=head;

	print_list(head,n);

	int r=(rand()%n)+1;

	node *ptr=head;

	for(int i=2;i<=n;i++)
	{
		ptr=ptr->next;
	}

	cin>>x;
	node *ptr1=ptr;
	node *ptr2=ptr->next;

	while(1)
	{
		if(ptr1->data<=x && ptr2->data >=x)break;

		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}

	node *tmp=new node(x);
	tmp->next=ptr2;
	ptr1->next=tmp;

	print_list(head,n+1);

	return 0;
}