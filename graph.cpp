#include<iostream>
#include<cstring>
#define max 5
using namespace std;
typedef struct node
{
	int key;
	string city;
	struct node *left;
};
class adjlist
{
	struct node *head;
	struct node *list_add[max];
	int city_count;
public:
	adjlist()
{
		int i;
		head=NULL;
		for(i=0;i<max;i++)
		{
			list_add[i]=NULL;
			city_count=0;
		}
}
	void create_g(int);
	void display();
};
class adjmat
{
int mat[max][max];
string city[max];
int city_count;
public:
adjmat()
{
	int i,j;
	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
		{
			mat[i][j]=0;
		}
	}

	city_count=0;
}
   void create_g(int cities);
   void display();
};
void adjmat::create_g(int c)
{
	int i,j,ans,time;
	city_count=c;
	cout<<endl<<"Enter list of cities";
	for(int i=0;i<c;i++)
	{
		cout<<endl<<"Enter city"<<i+1;
		cin>>city[i];
	}
	for(i=0;i<c;i++)
	{
		for(j=0;j<c;j++)
		{
			if(mat[i][j]==0&&i!=j)
			{
			cout<<endl<<"Is there any flight between "
					<<city[i]<<" & "<<city[j]
					<<"?Enter 1 if yes otherwise 0";
			cin>>ans;
			if(ans==1)
			{
				cout<<endl<<"Enter time of flight in hour";
				cin>>time;
				mat[i][j]=time;
				mat[j][i]=time;
			}
			}
		}
	}
}
void adjmat::display()
{
	int i,j,c;
	c=city_count;
	cout<<endl<<"Graph as follows"<<endl;
	for(i=0;i<c;i++)
		{
			for(j=0;j<c;j++)
			{
				cout<<mat[i][j]<<"\t";
			}
			cout<<endl;
		}
	cout<<endl<<"Source    Destination   Time";
	for(i=0;i<c;i++)
			{
				for(j=i;j<c;j++)
				{
					if(mat[i][j]!=0&&i!=j)
					cout<<endl<<city[i]<<"   to   "<<city[j]<<"   "<<mat[i][j]<<"Hr";
				}
			}
}
void adjlist::create_g(int c)
{
	int i,j,ans,time;
	string city;
	struct node *nnode,*lnode,*lnode2;
	city_count=c;
		cout<<endl<<"Enter list of cities";
		for(int i=0;i<c;i++)
		{
			cout<<endl<<"Enter city"<<i+1;
			cin>>city;
			if(i==0)
			{
				head=new node;
				head->city=city;
				head->key=0;
				head->left=NULL;
				list_add[i]=head;
			}
			else
			{
				nnode=new node;
				nnode->city=city;
				nnode->key=0;
				nnode->left=NULL;
				list_add[i]=nnode;
			}
		}
		for(i=0;i<c;i++)
		{
			lnode=list_add[i];
			for(j=0;j<c;j++)
			{
				if(i!=j)
				{
				cout<<endl<<"Is there any flight between "
						<<list_add[i]->city
						<<" & "<<list_add[j]->city
						<<"?Enter 1 if yes otherwise 0";
				cin>>ans;
				if(ans==1)
				{
					cout<<endl<<"Enter time of flight in hour";
					cin>>time;
					nnode=new node;
					nnode->key=time;
					nnode->city=list_add[j]->city;
					nnode->left=NULL;

					lnode->left=nnode;
					lnode=nnode;
				}
				}
			}
		}
}
void adjlist::display()
{
	int i;
	struct node *lnode,*head;
	cout<<endl<<"Flights are as";
	for(i=0;i<city_count;i++)
	{
		head=list_add[i];
		lnode=head->left;
		while(lnode!=NULL)
		{
			cout<<endl<<head->city<<" TO "<<lnode->city<<"  "<<lnode->key<<" HR";
			lnode=lnode->left;
		}
	}
}
int main()
{
int cities,ch;
adjmat g1;
adjlist g2;
do{
	cout<<endl<<"MENU"
			"\n1.create graph by adjacency matrix"
			"\n2.create graph by adjacency list"
			"\n3.show all flights of adjacency matrix"
			"\n4.show all flights of adjacency list"
			"\n5.exit";
	cin>>ch;
	switch(ch)
	{
	case 1:
		cout<<endl<<"How many cities?";
		cin>>cities;
		g1.create_g(cities);
		break;
	case 2:
		cout<<endl<<"How many cities?";
				cin>>cities;
				g2.create_g(cities);
		break;
	case 3:
		g1.display();
		break;
	case 4:
		g2.display();
		break;
	case 5:
		break;
	default:
		cout<<endl<<"Enter valid option";
	}
}while(ch!=5);
}
