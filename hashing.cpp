#include<iostream>
#include<cstring>
#define max 10
using namespace std;
typedef struct hash_table
{
	string name;
	long int num;
	int chain;
};
class hashf
{
   hash_table h[max];
   int c;
public:
	hashf()
{
		int i;
		for(i=0;i<max;i++)
		{
			h[i].num=0;
			h[i].chain=-1;
		}
		c=0;
}
	void storeNo();
	void searchNo();
	int findEmpty(int);
};
void hashf::storeNo()
{
	int i,count,hf,nf;
	string cname;
	long int no;
	cout<<endl<<"How many clients to add in the telephone book";
	cin>>count;
	c=count;
	 for(i=0;i<c;i++)
	 {
		 cout<<endl<<"Enter the name of "<<i+1<<"th client";
		 cin>>cname;
		 cout<<endl<<"Enter the number of "<<i+1<<"th client";
		 cin>>no;
		 hf=no%c;
		 if(h[hf].num==0)
		 {
			 h[hf].num=no;
			    h[hf].name=cname;
		 }
		 else
		 {
			 nf=hf;
			 if(h[nf].chain!=-1)
			 {
			 while(h[nf].chain!=-1)
				 {
				 nf=h[nf].chain;
				 }
			 hf=nf;
			 }
			 nf=findEmpty(nf);
			if(nf!=99)
			 {
			 h[nf].num=no;
	         h[nf].name=cname;
	         h[hf].chain=nf;
			 }
		 }

	 }
}
int hashf::findEmpty(int hf)
{
	int nf;
	nf=hf+1;
				 do
				 {
					 if(h[hf].chain==-1)
					 {
					 if(h[nf].num==0)
					 {
						   return nf;
						    break;
					 }
					 else
					 {
						 nf=(nf+1)%c;
						 if(nf==hf)
						 {
							 cout<<endl<<"Sorry hash table is full!!!";
							 return 99;
							 break;
						 }
					 }
					 }
				 }while(1);
}
void hashf::searchNo()
{
     int hf,f=-1,phf;
     long int no;
		 cout<<endl<<"Enter the number of client";
					 cin>>no;
					 hf=no%c;
					 phf=hf;
					 do{
					 if(h[hf].num==no)
			{
						 cout<<endl<<"NAME :: "<<h[hf].name<<endl<<"NUMBER ::"<<h[hf].num;
						 f=0;
			}
					 else if(h[hf].chain!=-1)
					 {
						 hf=h[hf].chain;
					 }
					 }while(f!=0 && hf!=phf);
					 if(f==-1 || hf==phf)
					 {
						 cout<<endl<<"Sorry,Entered number is not available!!!";
					 }
}
int main()
{
	int ch;
     hashf o;
	do{
		cout<<endl<<"MENU"
				"\n1.create phone contacts"
				"\n2.search a telephone number"
				"\n3.exit";
		cin>>ch;
		switch(ch)
		{
		case 1:
			o.storeNo();
			break;
		case 2:
			o.searchNo();
			break;
		case 3:
			break;
		default:
			cout<<endl<<"Please enter a valid choice";
		}
	}while(ch!=3);
	return 0;
}
