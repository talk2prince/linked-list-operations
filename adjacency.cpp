#include<iostream>
using namespace std;
#define MAX 15
class listgraph;
class graphnode{
	int vertex;
	graphnode *next;
	graphnode(int n=0)
	{
		vertex=n;
		next = NULL;
	}
	friend class listgraph;
};
class listgraph
{
	graphnode *list[MAX];
	int n;
	public:
	listgraph(int nov=0)
	{
		n=nov;
		for(int j=0;j<n;j++)
		{
			list[j]=NULL;
		}
	}
	void create();
	void display();
};
void listgraph::create()
{
	int i,j;
	graphnode *temp,*newnode;
	char ans;
	cout<<"enter the no of vertex of the graph\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"Is there an edge between "<<"v"<<i+1<<"and"<<"v"<<j+1;
			cin>>ans;
			if(ans=='y')
			{
				newnode = new graphnode(j+1);
				if(list[i]==NULL)
				list[i]=temp=newnode;
				else
				{
					temp->next=newnode;
					temp=newnode;	
				}
			}
		}
	}
}
void listgraph::display()
{

	graphnode *temp;
	int i;
	for(int i=0;i<n;i++)
	{
		cout<<endl;
		cout<<"vertex"<<i+1<<"=";
		temp=list[i];
		
		while(temp->next!=NULL)
		{
			cout<<"v"<<temp->vertex<<"->";
			temp=temp->next;
		}
		cout<<"v"<<temp->vertex<<"->";
		cout<<"NULL";
		
	}
}
int main()
{
	listgraph l;
	l.create();
	l.display();
	return 0;
}
