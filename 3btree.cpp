#include<iostream>
using namespace std;
typedef struct treenode
{
	int data;
	struct treenode *left,*right;
};

class copytree
{
	struct treenode *root=NULL;
public:
	copytree()
{
		root=NULL;
}
	treenode * create(struct treenode *root);
	void create();
	void operator =(const copytree);
	treenode* copy(treenode*,treenode*);
	void display();
	    void preorder(treenode *root);
		void postorder(treenode *root);
		void inorder(treenode *root);
		void delete_tree(treenode *root);
		void deletew();
};

void copytree::create()
{
	treenode *null=NULL;
	root=create(null);
	cout<<endl<<"Binary tree has been created";
}

treenode * copytree:: create(struct treenode *root)
{
	int data;
		treenode *nnode=NULL;
						cout<<endl<<"Enter data (press '99' if no node)";
						cin>>data;
						if(data!=99)
						{
							nnode=new treenode;
							root=nnode;
							nnode->data=data;
							cout<<endl<<"For left child of "<<data;
						root->left=create(nnode);
						cout<<endl<<"For right child "<<data;
						root->right=create(nnode);
						}
						return nnode;
}

void copytree::operator =(const copytree t1)
{
	root=copy(t1.root,root);
}

treenode* copytree::copy(treenode*a,treenode*b)
{
	if(b==NULL)
	{
		if(a!=NULL)
		{
			//create root or child of second tree as of first
			b=new treenode;
			b->data=a->data;
			b->left=NULL;
			b->right=NULL;
			/*
			 * check if left child of first tree is present or not if it is then copy to left of second tree
			 * here,address of root is passed by backtracking that is by recursive order
			 * so the last left node will first get copied
			*/
			if(a->left!=NULL)
			{
				b->left=copy(a->left,b->left);
			}
			if(a->right!=NULL)
			{
				b->right=copy(a->right,b->right);
			}
		}
	}
	return b;
}

void copytree::display()
{
	if(root!=NULL)
	{
		treenode *ptr=root;
	cout<<endl<<"Preorder traversal=>";
	this->preorder(ptr);
	cout<<endl<<"Postorder traversal=>";
	this->postorder(ptr);
    cout<<endl<<"Inorder traversal=>";
    this->inorder(ptr);
	}
	else
		cout<<endl<<"Tree has been empty";
}

void copytree::preorder(treenode *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<",";
		preorder(root->left);
		preorder(root->right);
	}
}

//Non-recursive inorder traversal using stack
void copytree::inorder(treenode *root)
{
	treenode *stk[50];
	int top=-1;
	treenode *ptr=root;
	while(top!=-1||ptr!=NULL)
	{
		if(ptr!=NULL)
		{
			stk[++top]=ptr;
			ptr=ptr->left;
		}
		else if(ptr==NULL)
		{
			ptr=stk[top--];
			cout<<ptr->data<<",";
			ptr=ptr->right;
		}
	}
}

void copytree::postorder(treenode *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<",";
	}
}

void copytree::delete_tree(treenode *root)
{
	if(root!=NULL)
		{
			delete_tree(root->left);
			delete_tree(root->right);
			delete root;
		}
}

void copytree::deletew()
{
	delete_tree(root);
	root=NULL;
}


int main()
{
	int ans,data;
	copytree T1,T2;
	struct treenode *root=NULL,*root2;

	do
	{
		cout<<"\nMenu"
				"\n1.create binary tree"
				"\n2.traverse tree"
				"\n3.copy tree"
				"\n4.delete trees"
				"\n5.exit"
				"\nEnter your choice";
		cin>>ans;
		switch(ans)
		{
		case 1:
			T1.create();
			break;
		case 2:
			T1.display();
			break;
		case 3:
			T2=T1;
			cout<<endl<<"Tree has been copied as=>";
			T2.display();
			break;
		case 4:
			T1.deletew();
			cout<<endl<<"First tree has been deleted";
			T2.deletew();
			cout<<endl<<"Second tree has been deleted";
			break;
		case 5:
			break;
		default:
			cout<<endl<<"Please enter valid option";
		}
	}while(ans!=5);
	return 0;
}
