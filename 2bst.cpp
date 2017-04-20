#include<iostream>
using namespace std;
typedef struct bstnode
{
	int data;
	bstnode *left,*right;
};

int max=0;
class bst
{
	bstnode *root;
public:
	bst()
{
	root=NULL;
}
	bstnode* create(struct bstnode *,bstnode *);
	void search(int val,bstnode **loc,bstnode **par);
	void insert();
	void inorder(bstnode *);
	void display();
	bstnode* copy(bstnode*a,bstnode*b);
	void copywrap(bst);
	void small();
	void MAX(bstnode* a,int counter)
	{
		if(a!=NULL)
		{
			counter++;
			this->MAX(a->left,counter);
			if(::max<counter)
			{
				::max=counter;
			}
			MAX(a->right,counter);
			counter--;
		}
	}
	void MAXwrap()
	{
		MAX(root,0);
		cout<<" maximum height \n";
				cout<<::max<<"\n";
	}
	void delete_tree(bstnode *root);
	void deletew();
};

bstnode * bst::create(bstnode *ptr,bstnode *nnode)
{
	int d;

	if(ptr==NULL)
		ptr=nnode;
	else if(ptr->data>nnode->data)
		ptr->left=create(ptr->left,nnode);
	else if(ptr->data<nnode->data)
		ptr->right=create(ptr->right,nnode);
	else
		cout<<endl<<"Duplicates are not allowed in BST";
	return ptr;

}

void bst::insert()
{
	int d,i,n=0;
	bstnode *nnode;
	cout<<endl<<"Insert one or more,if more how many?";
	cin>>n;
	for(i=0;i<n;i++)
	{
	cout<<endl<<"Enter data";
	cin>>d;
	nnode=new bstnode;
	nnode->data=d;
	nnode->left=NULL;
	nnode->right=NULL;
	root=create(root,nnode);
	}
}

void bst::inorder(bstnode *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<",";
		inorder(root->right);
	}
}
void bst::display()
{
	inorder(root);
}
void bst::search(int val,bstnode **loc,bstnode **par)
{
	bstnode *ptr=NULL,*ptrs=NULL;
	if(root==NULL)
	{
		loc=NULL;
		par=NULL;
	}
	if(root->data==val)
	{
		*loc=root;
		*par=NULL;
		return;
	}
	ptr=root;
	ptrs=root;
	if(val<ptr->data)
		ptr=ptr->left;
	else if(val>ptr->data)
		ptr=ptr->right;
	while(ptr!=NULL)
	{
		if(ptr->data==val)
		{
			*loc=ptr;
			*par=ptrs;
		}
		ptrs=ptr;
		if(val<ptr->data)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}

	if(ptr==NULL)
	{
		loc=NULL;
		par=NULL;
		return;
	}
}

bstnode* bst::copy(bstnode*a,bstnode*b)
{
	if(b==NULL)
	{
		if(a!=NULL)
		{
			b= new bstnode;
			b->data=a->data;
			b->left=NULL;
			b->right=NULL;
			if(a->left!=NULL)
			{
				b->right=copy(a->left,b->right);
			}
		 if(a->right!=NULL)
			{
				b->left=copy(a->right,b->left);
			}
		}
	}
	return b;
}
void bst::copywrap(const bst t1)
{
	root=NULL;
	root=copy(t1.root,root);
}
void bst::small()
{
	bstnode *ptr=root;
	while(ptr->left!=NULL)
		{
		ptr=ptr->left;
		}
	cout<<endl<<"Minimum data value found is"<<ptr->data;
}
void bst::delete_tree(bstnode *root)
{
	if(root!=NULL)
		{
			delete_tree(root->left);
			delete_tree(root->right);
			delete root;
		}
}

void bst::deletew()
{
	if(root!=NULL)
	{
		delete_tree(root);
	root=NULL;
	cout<<endl<<"BST has been deleted";
	}
	else
		cout<<endl<<"BST has been empty";
}
int main()
{
	int ans,value,data;
		bst T1,T2;
		struct bstnode *loc,*par;

		do
		{
			cout<<endl<<"Menu"
					"\n1.insert node in binary search tree"
					"\n2.traverse tree"
					"\n3.search a number"
					"\n4.copy swapped tree"
					"\n5.Find number of nodes in longest path"
					"\n6.Minimum data value found in the tree"
					"\n7.exit"
					"\nEnter your choice";
			cin>>ans;
			switch(ans)
			{
			case 1:
				T1.insert();
				break;
			case 2:
				T1.display();
				break;
			case 3:
				cout<<endl<<"Enter value to search";
				cin>>value;
				T1.search(value,&loc,&par);
				if(loc!=NULL)
				{
					cout<<endl<<"Number found as"<<loc->data;
					loc=NULL;
				}
				else
					cout<<endl<<"Number not found in BST";
				break;
			case 4:
				T2.copywrap(T1);
				cout<<endl<<"Left and right nodes of BST has been swapped as =>";
				T2.display();
				break;
			case 5:
				T1.MAXwrap();
				break;
			case 6:
				T1.small();
				break;
			case 7:
				T1.deletew();
				T2.deletew();
				break;
			default:
				cout<<"please enter correct choice \n";
				break;
			}
		}while(ans!=7);
		return 0;
}
