#include<conio.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class ArrayADT
{
	private:
	int capacity;
	int lastindex;
	int *ptr;
	public:
		ArrayADT()
		{
			capacity=-0;
			lastindex=-1;
			ptr=NULL;
		}
			void createitem(int cap);
			int getitem(int index);
			void setitem(int index,int value);
			void edititem(int index,int value);
			int countitem();
			void removeitem(int index);
			int searchitem(int index);
			void sortitem();
			friend ostream& operator<<(ostream&,ArrayADT);
			~ArrayADT()
			{
				delete[]ptr;
		    }
		    ArrayADT(ArrayADT &list)
		    {
		    	capacity = list.capacity;
		    	lastindex = list.lastindex;
		    	ptr = new int(capacity);
		    	for(int i=0;i<=list.lastindex;i++)
		    	ptr[i] = list.ptr[i];
			}
		    
		
};


void ArrayADT:: createitem(int cap)
{
	this->capacity=cap;
	lastindex=-1;
	ptr = new int(capacity);
}
int ArrayADT:: getitem(int index)
{
	if(lastindex == -1)
	{
		cout<<"\nlist is empty";
		return(-1);
	}
	if(lastindex<index||index<0)
	{
		cout<<"\n invalid index";
		return(-1);
	}
	else
	return(ptr[index]);
}

void ArrayADT:: setitem(int value,int index )
{
	int i;
	if(lastindex == capacity-1)
	{
	  cout<<"\noverflow";	
	}
	else if(index<0||index>lastindex+1)
	{
		cout<<"\n invaild index";
	}
	else if(index <= lastindex)
	{
		lastindex++;
		i = lastindex+1;
		while(i!=index)
		{
			ptr[i]=ptr[i-1];
			i--;
		}
		ptr[index] = value;
	}
    else if(index == lastindex+1)
	{
		lastindex++;
		ptr[index]=value;
	}
		
 }
	void ArrayADT:: edititem(int index,int newvalue)
	{
		if(index<0||index>lastindex)
		{
			cout<<"\n invalid inde";
		}
		else
		ptr[index]=newvalue;		
   	}
	int ArrayADT:: countitem()
	{
		return(lastindex+1);
	}
	void ArrayADT:: removeitem(int index)
	{
		if(index<0||index>lastindex)
		{
			cout<<"\n invalid index";
		}
		else if(index < lastindex);
		{
			int i;
			i = index;
			while(i != lastindex)
			{
				ptr[i] = ptr[i+1];
				i++;
			}
			lastindex--;
		}
	      if(index == lastindex)
		{
			lastindex--;
		}
	}
	int ArrayADT::searchitem(int value)
	{
		int i;
		if(lastindex==-1)
		{
			cout<<"\n list is empty";
			return(-1);
		}
		for(i=0;i<=lastindex;i++)
		{
			if(ptr[i]==value)
			return(i);
			
		}
		return(-1);
	}
	void ArrayADT:: sortitem()
	{
		int r,i,t;
		for(r=1;r<countitem();r++)
		{
			for(i=0;i<countitem()-r;i++)
			{
				if(ptr[i] > ptr[i+1])
			    {
				   t = ptr[i];
				   ptr[i] = ptr[i+1];
				   ptr[i+1] = t;
		       	}
			}
		}
	}
	ostream& operator<<(ostream &dout,ArrayADT l)
	{
		int n = l.lastindex+1;
		if(l.lastindex == -1)
		{
			cout<<"\n list is empty";
		}
		for(int i=0;i<n;i++)
		{
			cout<<" "<<l.getitem(i);
			return(dout);
		}
	}
	main()
	{
		ArrayADT l1;
		l1.createitem(6);
		l1.setitem(0,37);
		l1.setitem(1,89);
		cout<<l1;
	}
	

