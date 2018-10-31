#include<iostream>
using namespace std;
class node
{
	int data;
	node *next;
	public:
	
	node(int n)
	{
		data=n;
		next=NULL;
	}
	friend class cll;
	
}*temp;
class cll
{

	node *listptr,*first,*end;
	public:
	cll()
	{
		listptr=NULL;
	}
	void create();
	void display();
	void insert(int k);
	void delet(int k);
	void concat(cll l);
    void reverse();
    void sort();
    void addnode(int element);
    void copy(cll l);
};
void cll::create()
{
	int n,value;
	cout<<"enter the no of nodes u want to create\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter the data\n";
		cin>>value;
		node *newnode=new node(value);
		if(listptr==NULL)
		{
			first=listptr=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=temp->next;
			end=temp;
			
		}
		temp->next=listptr;
	}
}
void cll::display()
{

    node *temp;
	temp=listptr;
	while(temp->next!=listptr)
	{
		cout<<temp->data<<"->";
		temp=temp->next;	
	}
	cout<<temp->data;
	cout<<"->"<<temp->next->data<<endl;
}

void cll::sort()
{
	node *temp=first;
	for(temp=listptr; temp->next!=listptr; temp=temp->next)
	{
		node *p=temp;
		for(p=listptr; p->next!=listptr; p=p->next)
		{
			if(p->data > (p->next)->data)
			{
				int t;
				t=p->data;
				p->data=(p->next)->data;
				(p->next)->data=t;
			}
		}
	}
}
void cll::addnode(int element)
{

		node *newnode=new node(element);
		if(listptr==NULL)
		{
			first=listptr=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=temp->next;
			end=temp;
			
		}
		temp->next=listptr;
	
}
void cll::copy(cll l)
{
	node *temp2=first;
	while(temp2->next!=first)
	{
		l.addnode(temp2->data);
		temp2=temp2->next;
	}
	l.addnode(temp2->data);
}

void cll::reverse()
{
	node *curr,*forward,*back;
	curr=end;
	forward=listptr;
    while(forward->next!=listptr)
	{
		back=curr;
		curr=forward;
		forward=forward->next;
		curr->next=back;
	}
	end->next=back;
	listptr=end;
}
void cll::delet(int k)
{
	node *temp1;
	temp=listptr;
	if(k==1)
	{
		listptr=listptr->next;
		end->next=listptr;
	}
	else if(k==2)
	{
		while(temp->next->next!=listptr)
		{
			temp=temp->next;
		}
	    temp1=temp->next;
	    temp->next=listptr;
		delete temp1;	
	}
	else if(k==3)
	{
		int x=1,pos;
		cout<<"enter the pos to delete the value\n";
		cin>>pos;
		while(x!=(pos-1))
		{
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=temp1->next;
		delete temp1;
	}
}
void cll::insert(int k)
{
	int i;
	cout<<"enter the value to insert\n";
	cin>>i;
    node *newnode=new node(i);
	if(k==1)
	{
		temp=listptr;
		while(temp->next!=listptr)
		{
			temp=temp->next;
		}
		newnode->next=listptr;
		temp->next=newnode;
		listptr=newnode;
	}
	if(k==2)
	{
		temp=listptr;
		while(temp->next!=listptr)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=listptr;
	}
	if(k==3)
	{
		int x=1,pos;
		cout<<"enter the pos to insert the value\n";
		cin>>pos;
		temp=listptr;
		while(x!=(pos-1))
		{
			temp=temp->next;
	    }
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
void cll::concat(cll l)
{
	temp=listptr;
	while(temp->next!=listptr)
	{
		temp=temp->next;
	}
	temp->next=l.listptr;
	end=l.end;
	end->next=listptr;
}
int main()
{
	cll c,l;
	int d,k;
	do
	{
		cout<<"enter the operation u want to perform\n";
		cout<<"1.create\n2.display\n3.delete\n4.insert\n5.concate\n6.reverse\n7.sort\n8.copy list\n";
		cin>>d;
		switch(d)
		{
			case 1:cout<<"creation of cll\n";
			       c.create();
			       break;
			case 2:cout<<"display the data";
			       c.display();
			       break;
			case 3:cout<<"1.delete at front\n2.delete at end\n3.delete at a pos\n";
			       cin>>k;
			       c.delet(k);
			       break;
			case 4:cout<<"1 insert at front\n2.insert at end\n3.insert at a pos\n";
			       cin>>k;
			       c.insert(k);
			       break;
			case 5:cout<<"concatenation is:\n";
			       l.create();
			       c.concat(l);
			       break;
			case 6:cout<<"reverse of the linked list is:\n";
			       c.reverse();
			       break;
			case 7:cout<<"sort:";
			       c.sort();
			       break;
			case 8:cout<<"copy data";
			       c.copy(l);
			       l.display();
			       break;
		}
	}while(d!=9);


}

