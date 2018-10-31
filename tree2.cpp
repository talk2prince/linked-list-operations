//Program to Perform Operations on Binary Tree
#include<iostream>
using namespace std;
class node //Node class declaratiom
{
	public:
	char a;
	node *left,*right;
	node(char data)
	{
		a=data;
		left=NULL;
		right=NULL;
	}
	friend class tree;
};
class tree //Tree class declaration
{
	public:
		node *root;
		tree()
		{
			root=NULL;
		}
		//Methods Declaration
		void create(void);
		void preorder(void);
		void inorder(void);
		void postorder(void);
		int countnodes(void);
		int countleaves(void);
		void copy(tree &t);
		void mirror(tree &t);
		//Overloaded Methods
		void preorder(node *);
		void inorder(node *);
		void postorder(node *);
		int countnodes(node *);
		int countleaves(node *);
		node *copy(node *root1,node *root2);
		node *mirror(node *root1,node *root2);
};
//Create Function Defination
void tree::create()
{
	node *temp;
	char data,choice,ans;
	do
	{
		cout<<"Enter Data ";
		cin>>data;
		node *newnode=new node(data);
		if(root==NULL)
		{
			root=newnode;
		}
		else
		{
			temp=root;
			while(1)
			{
				cout<<"Left or Right ";
				cin>>choice;
				if(choice=='L')
				{
					if(temp->left==NULL)
					{
						temp->left=newnode;
						break;
					}
					else
					{
						temp=temp->left;
					}
				}
				else if(choice=='R')
				{
					if(temp->right==NULL)
					{
						temp->right=newnode;
						break;
					}
					else
					{
						temp=temp->right;
					}
				}
			}
		}
		cout<<"PRESS 'Y' TO ADD NODES ";
		cin>>ans;
	}while(ans=='Y');
}
//Preorder Traversal Defination
void tree::preorder()
{
	cout<<"Preorder Traversal: ";
	preorder(root);
}
void tree::preorder(node *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->a;
		preorder(temp->left);
		preorder(temp->right);
	}
}
//Inorder Traversal Defination
void tree::inorder()
{
	cout<<"Inorder Traversal: ";
	inorder(root);
}
void tree::inorder(node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<temp->a;
		inorder(temp->right);
	}
}
//Postorder Traversal Defination
void tree::postorder()
{
	cout<<"Postorder Traversal: ";
	postorder(root);
}
void tree::postorder(node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->a;
	}
}
//Count Nodes Function Defination
int tree::countnodes()
{
	return(countnodes(root));
}
int tree::countnodes(node *temp)
{
	static int count;
	if(temp!=NULL)
	{
		count++;
		countnodes(temp->left);
		countnodes(temp->right);
	}
	return(count);
}
//Count Leaves Function Defination
int tree::countleaves()
{
	return(countleaves(root));
}
int tree::countleaves(node *temp)
{
	static int count;
	if(temp==NULL)
	{
		return(count);
	}
	if(temp->left==NULL&&temp->right==NULL)
	{
		return(++count);
	}
	countleaves(temp->left);
	countleaves(temp->right);
}

void tree::copy(tree &t)
{
	copy(root,t.root);
}
node *tree::copy(node *root1,node*root2)
{
	if(root1!=NULL)
	{
		node *n=new node(root1->a);
		root2=n;
		root2->left=copy(root1->left,root2->left);
		root2->right=copy(root1->right,root2->right);
		return(root2);
	}
	else
	{
		return(NULL);
	}	
}
//Mirror Function Defination
void tree::mirror(tree &t)
{
	t.root=mirror(root,t.root);
}
node *tree::mirror(node *root1,node*root2)
{
	if(root1!=NULL)
	{
		node *n=new node(root1->a);
		root2=n;
		root2->left=copy(root1->right,root2->left);
		root2->right=copy(root1->left,root2->right);
		return(root2);
	}
	else
	{
		return(NULL);
	}	
}
//Main Class Initialisation
int main()
{
	int choice,value;
	tree t1,t2;
	cout<<"Operations On Binary Tree"<<endl;
	cout<<"1.Create"<<endl;
	cout<<"2.Preorder Traversal"<<endl;
	cout<<"3.Inorder Traversal"<<endl;
	cout<<"4.Postorder Traversal"<<endl;
	cout<<"5.Count Nodes"<<endl;
	cout<<"6.Count Leaves"<<endl;
	cout<<"7.Copy Tree"<<endl;
	cout<<"8.Mirror Image"<<endl;
	do
	{
		cout<<"\n";
		cout<<"Enter Choice\t";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					t1.create();
					break;
				}
			case 2:
				{
					t1.preorder();
					break;
				}
			case 3:
				{
					t1.inorder();
					break;
				}
			case 4:
				{
					t1.postorder();
					break;
				}
			case 5:
				{
					value=t1.countnodes();
					cout<<"Total Nodes: "<<value<<endl;
					break;
				}
			case 6:
				{
					value=t1.countleaves();
					cout<<"Total Leaves: "<<value<<endl;
					break;
				}
			case 7:
				{
					t1.copy(t2);
					t2.preorder();
					break;
				}
			case 8:
				{
					t1.mirror(t2);
					t2.preorder();
					break;
				}									
			default:
				{
					cout<<"Not Valid Option"<<endl;
					break;
				}						
		}
	}while(choice<9);
}
