#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
};
class list
{
	public:
		node *start,*temp,*end,*start1,*end1;
		list()
		{
			start=NULL;
	
		}
		void create();
		void create1();
		void add(int);
		void display();
		void del(int);
		void reverse();
		void concate(list n);
		void sort();
		void unionl(list p);
		void intersect(list n);
};
void list::create1()
{
	int n;
	cout<<"enter the no of the node\n";
	cin>>n;
	cout<<"enter the value\n";
	for(int i=0;i<n;i++)
	{
		node *newnode=new node;
		
		cin>>newnode->data;
		if(start1==NULL)
		{
		 	start1=temp=newnode;
		 	
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
			temp->next=NULL;
			end=temp;
			
		}
	}
	
}
void list::create()
{
	int n;
	cout<<"enter the no of the node\n";
	cin>>n;
	cout<<"enter the value\n";
	for(int i=0;i<n;i++)
	{
		node *newnode=new node;
		
		cin>>newnode->data;
		if(start==NULL)
		{
		 	start=temp=newnode;
		 	
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
			temp->next=NULL;
			end=temp;
			
		}
	}
	
}
void list::display()
{
	node *temp;
	temp=start;
	cout<<"list is \n";
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"null\n";
}
void list::add(int k)
{
	node *newnode = new node;
	cout<<"enter the data to be inserted\n";
	cin>>newnode->data;
	temp=start;
	if(k==1)
	{
		newnode->next=temp;
		start=newnode;
		
	}
	else if(k==2)
	{	
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=NULL;
		temp=newnode;
	}
	else if(k==3)
	{
		int pos;
		cout<<"enter the pos to insert\n";
		cin>>pos;
		node *newnode =new node;
		temp=start;
		int i=1;
        while(i!=pos-1)
		{
           temp=temp->next;
           i++;
		}
			newnode->next=temp->next;
			temp->next=newnode;
		
	}
	
	
}
void list::del(int k){
	node *temp;
	node *temp1;
	if(k==1)
	{
		temp=start;
		start=temp->next;
	    delete temp;
		
	}
	else if(k==2)
	{
	
		node *temp=start;
		while((temp->next)->next!=NULL)
		{
			temp=temp->next;
		}
		temp1=temp->next->next;
		temp->next=NULL;
		delete temp1;
	}
	else if(k==3)
	{
		int pos;
		node *temp;
		temp=start;
		cout<<"enter the pos to delete the node\n";
		cin>>pos;
		int i=1;
		while(i!=(pos-1))
		{
			temp=temp->next;
			i++;
		}
		temp1=temp->next;
		temp->next=temp1->next;
		delete temp1;
		
	}
}
/*void list::concate(list &l)
{
	node *t1=start,*t2=l.start,*newnode;
	while(t1->next!=NULL)
	t1=t1->next;
	while(t2!=NULL)
	{
		node *newnode=new node;
		newnode->data=t2->data;
		if(t1==NULL)
		start=t1=newnode;
		else
		{
			t1->next=newnode;
			t1=t1->next;
		}
		t2=t2->next;
	}

}*/
void list::concate(list n)
{
	end->next=n.start;
	end=n.end;
}
void list::sort()
{
	node *temp=start;
	for(temp=start; temp->next!=NULL; temp=temp->next)
	{
		node *p=temp;
		for(p=start; p->next!=NULL; p=p->next)
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
void list::unionl(list p)
{
	concate(p);
	
	node *temp=start;

	sort();

	while(temp->next!=NULL)
	{
		int x=temp->data;
		node *p=temp->next;
		while(p->data==x)
		{
			temp->next=p->next;
			p->next=NULL;
			delete p;
		}
		temp=temp->next;
	}
}
void list::intersect(list n)
{
	int x;
    node *temp=start;
	while(temp!=NULL)
	{
	 	int c=0;
	 	x=temp->data;
	 	node *temp1=n.start;
	 	while(temp1!=NULL)
	 	{
	 		if(x==temp1->data)
	 		{
	 			c++;
	 			break;
	 		
			 }
			temp1=temp1->next;
		
		 }
	   	 if(c==0)

		{

			if(start==temp)

			{

				node *tem=start;

				start=start->next;

				temp=temp->next;

				tem->next=NULL;

				delete tem;

			}

			else

			{

				node *tem=start;

				while(tem->next!=temp)

					tem=tem->next;

				tem->next=temp->next;

				tem=temp;

				temp->next=NULL;

				temp=temp->next;

				delete tem;

			}

		}

		else

			temp=temp->next;

	
	}	
	sort();	
}

void list::reverse()
{
	node *forward,*curr,*back;
	forward=start;
	curr=NULL;
	while(forward!=NULL)
	{
		back=curr;
		curr=forward;
		forward=forward->next;
		curr->next=back;
	}
	start = curr;
}

int main()
{
	int l,k;
	list m,n,p;
	do
	{
	cout<<"1 to create a list\n2.dislay the list\n3.to add\n4.to delete\n5. to reverse\n6. to concate\n7.union\n8.for intersection\n";
	cin>>l;
	switch(l)
	{
		case 1:m.create();
				break;
		case 2:m.display();
				break;
		case 3:cout<<"enter 1 insert at start\n2.insert at end\n3.insert at pos\n";
		       cin>>k;
		       m.add(k);
		       break;
		case 4:cout<<"enter 1 to delete at start\n2.delete at end\n3.delete at the pos\n";
		       cin>>k;
		       m.del(k);
		       break;
		case 5:m.reverse();	
		       m.display();
		       break;	
		case 6:cout<<"enter the second list\n";
		       n.create();
		       m.concate(n);
		       m.display();
		       break;
		 case 7:cout<<"union is:\n";
		        p.create();
		        m.unionl(p);   
		        m.display();
				break; 
		 case 8:cout<<"Intersection is:\n";
				m.create();
				n.create1();
				
				m.display();
				break;
		default:cout<<"invalid input\n";
			}
	}while(l!=9);
	return 0;
}
