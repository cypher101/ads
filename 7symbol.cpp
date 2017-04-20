#include<iostream>
#include<string.h>
#define max 10
using namespace std;
typedef struct symbol
{
	string type;
	string name;
	string value;
};

class compiler
{
	symbol st[max];
	int total;
public:
	compiler()
{
		int i;
		for(i=0;i<max;i++)
		{
			st[i].name="NULL";
			st[i].type="NULL";
			st[i].value="NULL";
		}
		total=0;
}
	        int search(string);
			void modify();
			void insert();
			void deleteVar();
};

void compiler::insert()
{
int i,j,n,len,h;
string name;
string type;
string val;
int ascii;
cout<<endl<<"How many variables?:";
cin>>n;

for(i=0;i<n;i++)
{
cout<<endl<<"Enter identifier name:";
cin>>name;
cout<<endl<<"Enter type:";
cin>>type;
cout<<endl<<"Enter value:";
cin>>val;
len=name.length();
ascii=0;
for(j=0;j<len;j++)
{
	ascii=ascii+name[j];
}

h=ascii%max;
if(st[h].name=="NULL")
{
st[h].name=name;
st[h].type=type;
st[h].value=val;
}
else
{
	j=(h+1)%max;
	while(j!=h)
	{
		if(st[j].name=="NULL")
		{
		st[j].name=name;
		st[j].type=type;
		st[j].value=val;
		break;
		}
		j=(j+1)%max;
	}
	if(j==h)
	{
		cout<<endl<<"Sorry!,Symbol table is full";
	}
}
}
}

int compiler::search(string id_name)
{
	int i,j,n,len,h;
	int ascii;
	string name;
	name=id_name;
	len=name.length();
	ascii=0;
	for(j=0;j<len;j++)
	{
		ascii=ascii+name[j];
	}

	h=ascii%max;
	if(st[h].name==name)
	{
		cout<<endl<<"Identifier found as=>"
				"\nTYPE   NAME   VALUE";
	cout<<endl<<st[h].type<<"  "<<st[h].name<<"  "<<st[h].value;
	return h;
	}
	else
	{
		j=(h+1)%max;
		while(j!=h)
		{
			if(st[j].name==name)
			{
				cout<<endl<<"Identifier found as=>"
							"\nTYPE   NAME   VALUE";
				cout<<endl<<st[j].type<<"  "<<st[j].name<<"  "<<st[j].value;
			break;
			}
			j=(j+1)%max;
		}
		if(j==h)
		{
			cout<<endl<<"Sorry!,Required identifier is not defined in symbol table";
			return -1;
		}
		else
			return j;
	}
}

void compiler::modify()
{
	int pos,i,j,ascii,h,len;
	string name;
	string type;
	string val;

	cout<<endl<<"Enter identifier name to modify:";
	cin>>name;
	pos=search(name);
	if(pos!=-1)
	{
	    st[pos].name="NULL";
		st[pos].type="NULL";
		st[pos].value="NULL";

	cout<<endl<<"Enter new identifier name:";
	cin>>name;
	cout<<endl<<"Enter type:";
	cin>>type;
	cout<<endl<<"Enter value:";
	cin>>val;

	len=name.length();
	ascii=0;
	for(j=0;j<len;j++)
	{
		ascii=ascii+name[j];
	}

	h=ascii%max;
	if(st[h].name=="NULL")
	{
	st[h].name=name;
	st[h].type=type;
	st[h].value=val;
	}
	else
	{
		j=(h+1)%max;
		while(j!=h)
		{
			if(st[j].name=="NULL")
			{
			st[j].name=name;
			st[j].type=type;
			st[j].value=val;
			break;
			}
			j=(j+1)%max;
		}
		if(j==h)
		{
			cout<<endl<<"Sorry!,Symbol table is full";
		}
	}
	}
}

void compiler::deleteVar()
{
	int pos;
	string name;
	cout<<endl<<"Enter identifier name to delete";
		cin>>name;
		pos=search(name);
		if(pos!=-1)
		{
		    st[pos].name="NULL";
			st[pos].type="NULL";
			st[pos].value="NULL";
	cout<<endl<<"Identifier '"<<name<<" has been deleted.";
		}
}
int main()
{
	int i,ch;
	string name;
	compiler obj;
	do{
		cout<<endl<<"MENU"
				"\n1. Insert a new name and its attributes"
				"\n2.Search and retrieve for an identifier"
				"\n3.Modify the attributes of identifier"
				"\n4.Delete a name and its attributes"
				"\n5.Exit"
				"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1:
			obj.insert();
			break;
		case 2:
			cout<<endl<<"Enter identifier name to search:";
			cin>>name;
			i=obj.search(name);
			break;
		case 3:
			obj.modify();
			break;
		case 4:
			obj.deleteVar();
			break;
		}
	}while(ch!=5);
}
