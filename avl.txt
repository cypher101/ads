#include<iostream>
using namespace std;
# define max 20
struct avlnode
{
char key,mean;
struct avlnode *left;
struct avlnode *right;
int ht;
};

class dict
{
struct avlnode *root;
public :
    dict()
    {
    root=NULL;
    }
    void insert(char k,char m);
    avlnode* createnode(char k,char m);
    avlnode* insertnode(avlnode *pnode,char k,char m);
    void indisplay(avlnode *node);   
    void display();
    int getht(avlnode *n);
    int getbal(avlnode *node);
    avlnode * rrotate(avlnode *y);
    avlnode * lrotate(avlnode *x);
};
int getmax(int h1,int h2)
{
if(h1>h2)
   return h1;
return h2;
}


    avlnode * dict::rrotate(avlnode *y)
    {
    cout<<endl<<"rotating right - "<< y->key;
    avlnode *x=y->left;
    avlnode *t=x->right;
    x->right= y;
    y->left=t;
    y->ht=getmax(getht(y->left),getht(y->right))+1;
    x->ht=getmax(getht(x->left),getht(x->right))+1;
    return x;
    }
    avlnode * dict::lrotate(avlnode *x)
    {
    cout<<endl<<"rotating left - "<< x->key;

    avlnode *y=x->right;
    avlnode *t=y->left;
    x->right= t;
    y->left=x;
    y->ht=getmax(getht(y->left),getht(y->right))+1;
    x->ht=getmax(getht(x->left),getht(x->right))+1;
    return y;
    }


int dict::getht(avlnode *n)
{
if(n==NULL)
    return 0;
else
    return(n->ht);
}
void dict::display()
{
indisplay(root);
}
void dict::insert(char k,char m)
{
root= insertnode(root,k,m);
}
void dict::indisplay(avlnode *node)
{
if(node!=NULL)
  {
  indisplay(node->left);
  cout<<" "<<node->key<<" "<<node->mean;
  indisplay(node->right);
  }
}

int dict::getbal(avlnode *node)
{
if(node==NULL)
  return 0;
return (getht(node->left)-getht(node->right));
}
avlnode* dict::insertnode(avlnode *pnode,char k,char m)
{

if(pnode==NULL)
    return(createnode(k,m));
if(k<pnode->key)
{
 
   pnode->left=insertnode(pnode->left,k,m);

}
else if(k>pnode->key)
{
   pnode->right=insertnode(pnode->right,k,m);

}
else
 return(pnode);

pnode->ht=1+(getmax(getht(pnode->left),getht(pnode->right)));
cout<<endl<<"height - "<<pnode->ht;

int bal = getbal(pnode);
cout<<endl<<"node bal - "<<bal;

cout<<" current key is "<<k;

if(bal > 1 && k < pnode->left->key)
  return(rrotate(pnode));
if(bal < -1 && k > pnode->right->key)
  return(lrotate(pnode));
if(bal > 1 && k > pnode->left->key)
{
pnode->left = lrotate(pnode->left);
return(rrotate(pnode));
}
if(bal < -1 && k < pnode->right->key)
{
pnode->right = rrotate(pnode->right);
  return(lrotate(pnode));
}

return(pnode);

}

avlnode* dict::createnode(char k,char m)
{
avlnode* navlnode = new avlnode;
navlnode->key=k;
navlnode->mean=m;
navlnode->ht=1;
navlnode->left=NULL;
navlnode->right=NULL;
return(navlnode);
}

int main()
{
int ch,cont;
char k,m;
int n;
dict d1;
do
{
cout<<endl<<"Menu";
cout<<endl<<"1.Insert node";
cout<<endl<<"2.Inorder Display  tree";
cout<<endl<<"Enter Choice";
cin>>ch;
switch(ch)
{
case 1:
    do{
    cout<<endl<<"enter key and meaning(single char)";
    cin>>k>>m;
    d1.insert(k,m);
    }while(k!='z');
    break;
case 2:
    d1.display();   
    break;
}
cout<<endl<<"do u want to continue?(1 for continue)";
cin>>cont;
}while(cont==1);
return 0;
}
