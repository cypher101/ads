#include<iostream>
#include<cstring>
#define max 15
using namespace std;
typedef struct treenode
{
	string name;
	treenode *left;
	treenode *right;
};
typedef struct que
{
	treenode* q[max];
	int f,r;
};
class book
{
	treenode *root;
public:
	book()
{
		root=NULL;
}
	void create();
	void delete_tree(treenode *root);
	void deletew();
	void preorder(treenode *root);
	void display();
	void display_bfs();
};
void book::display_bfs()
{
	treenode *lnode,*lnode2;
	que *b;
	b->f=0;
	b->r=-1;
	cout<<endl<<"Book name ->"<<root->name<<endl;
	cout<<endl<<"Chapters =>";
	lnode=root->left;
	while(lnode!=NULL)
	{
		cout<<lnode->name<<"\t";        //to display all chapters
		lnode2=lnode->left;
		while(lnode2!=NULL)
		{
			b->q[++b->r]=lnode2;          //push all sections of all chapters in queue
			lnode2=lnode2->right;
		}
		lnode=lnode->right;
	}
	cout<<endl<<"Sections =>"<<endl;
	while(b->f<=b->r)
	{
		cout<<b->q[b->f]->name<<"\t";           // pop all sections and display all
		b->f++;
	}
}

void book::delete_tree(treenode *root)
{
	if(root!=NULL)
		{
			delete_tree(root->left);
			delete_tree(root->right);
			delete root;
		}
}

void book::deletew()
{
	if(root!=NULL)
	{
		delete_tree(root);
	root=NULL;
	cout<<endl<<"Tree has been deleted";
	}
	else
		cout<<endl<<"Tree already empty";
}

void book::preorder(treenode *root)
{
	if(root!=NULL)
	{
		cout<<root->name<<",";
		preorder(root->left);
		preorder(root->right);
	}
}

void book::display()
{
	if(root!=NULL)
	{
		cout<<endl<<"Book details are as follows"<<endl;
	preorder(root);
	}
}

void book::create()
{
	int noc,nos,nosb,i,j,k;
	string name;
	treenode *nnode,*lnode,*lnode2,*lnode3;

	root=new treenode;
	root->right=NULL;
	cout<<endl<<"Enter name of the book";
		cin>>name;
root->name=name;

	cout<<endl<<"How many chapters?";
	cin>>noc;
	for(i=0;i<noc;i++)
	{
		cout<<endl<<"Enter chapter "<<i+1<<"th name";
		cin>>name;
		nnode=new treenode;
		nnode->name=name;
		nnode->left=NULL;
		nnode->right=NULL;

		if(i==0)
		{
			root->left=nnode;
        }
		else
		{
			lnode->right=nnode;
		}
		lnode=nnode;
		cout<<endl<<"How many sections?";
		cin>>nos;
		for(int j=0;j<nos;j++)
		{
			nnode=new treenode;
			cout<<endl<<"Enter section "<<j+1<<"th name";
			cin>>name;
			nnode->name=name;
			nnode->left=NULL;
			nnode->right=NULL;
			if(j==0)
			{
				lnode->left=nnode;

			}
			else
			{
				lnode2->right=nnode;
				//lnode2=lnode->right;
			}
			lnode2=nnode;

	    }
}
}
int main()
{
	int ans;
	book T;
	//struct tree node *root=NULL;

	do
	{
		cout<<"\nMenu"
				"\n1.create binary tree"
				"\n2.traverse tree"
				"\n3.exit"
				"\nEnter your choice";
		cin>>ans;
		switch(ans)
		{
		case 1:
			T.create();
			break;
		case 2:
			T.display();
			T.display_bfs();
			break;
		case 3:
			T.deletew();
			break;
		default:
			cout<<endl<<"Please enter valid option";
		}
	}while(ans!=3);
	return 0;
}
