#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class prims
{
	int n;
	int adjmat[10][10];
	int table[10][4];
	string city[10];
public:
	prims()
	{
		for(int i=0;i<10;i++)
		{	for(int j=0;j<10;j++)
			{
			adjmat[i][j]=0;
			}
		for(int k=0;k<4;k++)
					{
					table[i][k]=100;
					table[i][3]=0;
					table[i][0]=i+1;
					}

		}
	}
	int sum()
	{
        int sum=0;
       
        for(int i=1;i<n;i++)
            {
            sum=sum+table[i][1];
                }
                return sum;
                
    }
	void getdata()
	{
		int i,j,ans;
		cout<<"\nENTER TOTAL NO OF CITIES";
		cin>>n;
		for(i=0;i<n;i++)
		{
			cout<<"\nENTER NAME OF CITY "<<i+1<<" ";
			cin>>city[i];
		}
		 for( i=0;i<n;i++)
	  {
		     for( j=0;j<n;j++)
		 {
		       if(i<j&&adjmat[i][j]==0)
		        {
		          cout<<"\n\nIS THERE A CONNECTION BETWEEN CITY "<<city[i]<<" & CITY "<<city[j]<<" (1/0) ";
		          cin>>ans;
		          	 if(ans)
		          	  {
		       	  cout<<"\nENTER COST  ";
		       	  cin>>adjmat[i][j];
		       	  adjmat[j][i]=adjmat[i][j];
		          	  }
		         }
		  }
	  }

	}
void disp_adj()
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<n;j++)
		{
			cout<<"\t"<<adjmat[i][j];
		}
	}

}
void disp_table()
{
     		cout<<"\n\n";
            cout<<"\tnode \t"<<"cost\t"<<"predec \t"<<"status \t";
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<4;j++)
		{
			cout<<"\t"<<table[i][j];
		}
	}

}
int stat_check()
{
    int flag=1;
for( int i=0;i<n;i++)
{
     if(table[i][3]==1)
     {
             flag=0;                
      }
      else
      {
          return 1;
      }
     
}
return flag; 
}
void compute()
{
int j=0,md;
while(stat_check())
{
 for(int i=0;i<n;i++)
 {
         if(table[i][1]>adjmat[j][i] && table[i][3]==0  && adjmat[j][i]!=0)
         {
          table[i][1]=adjmat[j][i];
          table[i][2]=j;
         }
 }
j=min();
table[j][3]=1;
disp_table();
cout<<"\n min ="<<j;
}
md=sum();
cout<<"\nMINIMUM DISTANCE "<<md;

}

int min()
{
    int i,min=1000,index;
    for(i=0;i<n;i++)
    {
     if(table[i][1]<min  && table[i][3]==0)
     {
      min=table[i][1];
      index=i;
      }
    }
    return index;
}
};
int main()
{
	prims p;
	int ch;
do{
	cout<<"\nMENU"
        <<"\n1.ENTER GRAPH INFO "
        <<"\n2.DISPLAY ADJANCENCY MATRIX"
        <<"\n3.COMPUTE SHORTEST DISTANCE"
        <<"\n4.EXIT";
 cin>>ch;
 switch(ch)
 {
 case 1:
      	p.getdata();
      	break;
case 2:             
       p.disp_adj(); 
       break;
case 3:  
      p.compute();  
       break;
case 4:
     break;
default:
        cout<<"\nPLEASE ENTER A VALID CHOICE";
                   
 }
 }while(ch!=4);



	return 0;
}
