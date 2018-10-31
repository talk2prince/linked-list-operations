#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node *next,*prev;
    
            node(int n)
            {
                data=n;
                prev=next=NULL;
            }
};
class double_list
{
    node *first;
    public:
        double_list()
        {
            first=NULL;
        }
        
        void Create();
        void Display();
        void add(int k);
        void search(int x);
        void count();
        void del(int k);
        void reverse();
        void sort();
};
void double_list::Create()
{
    int n,num;
    node *temp;
    cout<<"enter the no of the nodes\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the nodes"<<i+1<<":";
        cin>>num;
        node *newnode=new node(num);
        if(first==NULL)
        {
            first=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=NULL;
            temp=temp->next;
        }
    }
}
void double_list::count()
{
	int m=1;
	node *temp=first;
	while(temp->next!=NULL)
	{
		++m;
		temp=temp->next;
	}
	cout<<"no of element is:"<<m<<endl;
}
void double_list::sort()
{
	node *temp=first;
	for(temp=first; temp->next!=NULL; temp=temp->next)
	{
		node *p=temp;
		for(p=first; p->next!=NULL; p=p->next)
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
void double_list::Display()
{
    int n;
    node *temp;
    temp=first;
    while(temp!=NULL)
    {
        cout<<temp->data<<"<->";
        temp=temp->next;    
    }
 cout<<"null\n";
    
}
void double_list::add(int k)
{
    
    int num;
    cout<<"enter the value to insert\n";
    cin>>num;
    if(k==1)
    {

        node *newnode=new node(num);
        newnode->next=first;
        first->prev=newnode;
        first=newnode;
        
    }
    else if(k==2)
    {
        node *temp;
        node *newnode=new node(num);
        while(temp!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
    }
    else if(k==3)
    {
        int pos,x=1;
        node *temp=first;
        node *newnode=new node(num);
        cout<<"enter the pos to insert the value\n";
        cin>>pos;
        while(x!=(pos-1))
        {
            temp=temp->next;
            x++;
        }
        newnode->next=temp->next;
        temp->next->prev=newnode;
        newnode->prev=temp;
        temp->next=newnode;
    }
}
void double_list::del(int k)
{
	node *temp=first,*temp1;
	if(k==1)
	{
		temp1=first;
		first=first->next;
		delete temp1;
	}
	if(k==2)
	{
		while((temp->next)->next!=NULL)
		{
			temp=temp->next;
		}
		temp1=temp->next->next;
		temp->next=NULL;
		delete temp1;

	}
	if(k==3)
	{
		int pos,x=1;
		cout<<"enter the pos to delete the value";
		cin>>pos;
		while(x!=(pos-1))
		{
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=temp1->next;
		temp1->next->prev=temp;
		delete temp1;
	}
	
}
void double_list::search(int x)
{
    node *temp=first;
    int c=1;
    if(first->data==x)
            {
                cout<<"position is:"<<c<<"\n";
            }
    else
    {
    temp=first->next;        
    while(temp->next!=NULL)
    {
            if(temp->data==x)
            {
            break;
            }
            c++;
            temp=temp->next;
    }
     cout<<"pos is:"<<c+1<<"\n";
    }

}

void double_list::reverse()
{
	node *forward,*curr,*back;
	forward=first;
	curr=NULL;
	while(forward!=NULL)
	{
		back=curr;
		curr=forward;
		forward=forward->next;
		curr->next=back;
		curr->prev=forward;
	}
	first = curr;
}
int main()
{
    int i,k,x;
    double_list l;
    do
    {
        cout<<"1.create\n2.display\n3.add\n4.search the element\n5.count\n6.delete\n7.reverse\n8.sort\n";
        cin>>i;
        switch(i)
        {
            case 1:l.Create();
                   break;
            case 2:l.Display();
                   break;
            case 3:cout<<"1 to add at beginning\n2.to add at end\n3.to insert at position\n";
                   cin>>k;
                   l.add(k);
                   l.Display();
                   break;
            case 4:cout<<"enter the element to search\n";
                   cin>>x;
                   l.search(x);
                   break;
            case 5:l.count();
                   break;
            case 6:cout<<"enter the pos to del\n";
                   cout<<"1.beginning\n2.At the end\n3.at any pos";
                   cin>>k;
			       l.del(k);
			       l.Display();
			       break;
			case 7:l.reverse();
			       l.Display();
			       break;
			case 8:l.sort();
			       l.Display();
			       break;
            default:cout<<"invalid inputs";
        }
    }while(i!=9);
    return 0;
}
