#include<iostream>
#define max 50
using namespace std;
class Heap
{
	int marks[max];
	int count;
public:
	Heap()
{
		int i;
		for(i=0;i<max;i++)
		{
			marks[i]=0;
		}

		count=0;
}
	void getmarks();
	void swap(int &,int &);
	void maxHeap();
	void minHeap();
};

void Heap::maxHeap()
{
	int i,j;
	int heap[count];

	for(i=0;i<count;i++)
	{
		heap[i]=marks[i];
	}
	for(i=1;i<count;i++)
	{
	    if(heap[i]>heap[(i-1)/2])
	    	swap(heap[i],heap[(i-1)/2]);

	    for(j=((i-1)/2);j>0;j--)
	    		{
	    	    if(heap[j]>heap[(j-1)/2])
	    	    {
	    	    	swap(heap[j],heap[(j-1)/2]);
	        	}
	    		}
	}

	cout<<endl<<"Marks in heap tree are =>"<<endl;
	for(i=0;i<count;i++)
		{
			cout<<heap[i]<<" ";
		}
	cout<<endl<<"Maximum marks in heap tree are =>"<<heap[0];
}

void Heap::minHeap()
{
	int i,j;
	int heap[count];

	for(i=0;i<count;i++)
	{
		heap[i]=marks[i];
	}
	for(i=1;i<count;i++)
	{
		         if(heap[i]<heap[(i-1)/2])
			    	{
			    	swap(heap[i],heap[(i-1)/2]);
			    	}
		for(j=((i-1)/2);j>0;j--)
		{
	    if(heap[j]<heap[(j-1)/2])
	    {
	    	swap(heap[j],heap[(j-1)/2]);
    	}
		}
	}

	cout<<endl<<"Marks in ascending oredr are =>"<<endl;
	for(i=0;i<count;i++)
		{
			cout<<heap[i]<<" ";
		}
	cout<<endl<<"Minimum marks obtained on subject is =>"<<heap[0];
}

void Heap::swap(int &x,int &y)
{
	// function definition to swap the values.
	   int temp;
	   temp = x; /* save the value at address x */
	   x = y;    /* put y into x */
	   y = temp; /* put x into y */

}

void Heap::getmarks()
{
	int t,i,m;
	cout<<endl<<"Enter total numbers of students";
	cin>>t;
	count=t;
	cout<<endl<<"Please enter students marks";
	for(i=0;i<t;i++)
	{
		cin>>marks[i];
	}
}





int main()
{
	int ch;
	Heap h;
	do{
	cout<<endl<<"Menu"
			"\n1.Enter marks of subject"
			"\n2.Get maximum marks obtained"
			"\n3.Get minimum marks obtained"
			"\n4.exit"
			"\nEnter your choice";
	cin>>ch;
	switch(ch)
	{
	case 1:
	    h.getmarks();
	    break;
	case 2:
		h.maxHeap();
		break;
	case 3:
		h.minHeap();
		break;
	case 4:
		break;
	default :
		cout<<endl<<"Please enter a valid option";
	}
	}while(ch!=4);
}
