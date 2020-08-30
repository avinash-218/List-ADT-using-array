#include<iostream>
using namespace std;
//class declaration
class List_ADT		//List_ADT class
{
	private:
			int *arr;	//array elements
			int size;	//size
			int cap;		//capacity
	public:
			List_ADT();		//default constructor
			List_ADT(int*,int,int);	//parameterised constructor
			List_ADT(const List_ADT&);	//copy constructor
			~List_ADT();	//destructor

			int isFull();	//to check if the list is full
			int isEmpty();	//to check if the list is empty
			void insertAtFirst(int);	//to insert an element at first
			void insertAtLast(int);	//to insert an element at last
			void insertByPos(int,int);	//insert an element in the given position by doing necessary shifting
			void displayList();	//to display elements of list
			void deleteAtFirst();	//to delete element at first
			void deleteAtLast();	//to delete element at last
			void deleteByPos(int);	//to delete the element at the given position
			void makeListEmpty();	//to empty the list
};

//implementation
List_ADT::List_ADT()	//default constructor
{
	//arr = Null;
	size=0;
	cap=10;		//default capacity is 10
	arr=new int[cap];
	for(int i=0;i<cap;i++)	//initially setting all elements to -1
		arr[i]=-1;
}

List_ADT::List_ADT(int *a,int s,int c)
{
	size=s;
	cap=c;
	arr=new int[cap];
	for(int i=0;i<size;i++)	//copying given element
		arr[i]=a[i];
	for(int i=size;i<cap;i++)	//setting other elements to -1
		arr[i]=-1;
}

List_ADT::List_ADT(const List_ADT &cpy)	//copy constructor
{
	size=cpy.size;
	cap=cpy.cap;
	arr=new int[cap];
	for(int i=0;i<size;i++)		//copying given elements
		arr[i]=cpy.arr[i];
	for(int i=size;i<cap;i++)	//setting other elements to -1
		arr[i]=-1;
}

List_ADT::~List_ADT()	//destructor
{
	size=0;
	cap=0;
	delete []arr;
	arr=NULL;
}

int List_ADT::isFull()	//to check if the list is full
{
	return cap==size;
}

int List_ADT::isEmpty()	//to check if the lsit is empty
{
	return size==0;
}

void List_ADT::insertAtLast(int ele)	//to insert an element to the last of the list
{
	if(!isFull())	//if the list is not full
	{
		arr[size++]=ele;
		cout<<"element inserted at last\n";	//success
	}
	else
		cout<<"element can't be inserted\n";	//list is full
}

void List_ADT::insertAtFirst(int ele)	//to insert an element to the first of the list
{
	if(!isFull())	//if list is not full
	{
		for(int i=cap;i>0;i--)
			arr[i]=arr[i-1];
			size++;
		arr[0]=ele;
		cout<<"element inserted at first\n";	//success
	}
	else
		cout<<"element can't be inserted\n";	//list if full
}

void List_ADT::insertByPos(int pos,int ele)	//to insert an element in the given position (by necessary shifting)
{
	//pos belongs to [1,cap]
	if (!isFull() && pos>0 && pos<=size+1)	//if the list is not full
	{
		if(pos==1)	//to insert at first
			insertAtFirst(ele);
		else if(pos==size+1)	//to insert at last
			insertAtLast(ele);
		else 	//to insert in-between
		{
			int flag=size;
			while(flag>pos-1)
			{
				arr[flag]=arr[flag-1];
				flag--;
			}
			arr[pos-1]=ele;
			size++;
			cout<<"element is inserted at the position\n";	//success
		}
	}
	else
		cout<<"element can't be inserted\n";	//list is full or invalid position
}

void List_ADT::displayList()	//to display elements of list
{
	if(isEmpty())	//if list is empty
		cout<<"List is Empty!\n";
	else
	{
		cout<<"Elements in the list:\n";
		for(int i=0;i<size;i++)
			cout<<arr[i]<<"\t";
	}
	cout<<"\n";
}

void List_ADT::deleteAtFirst()
{
	if(!isEmpty())	//if list is empty
	{
		for(int i=0;i<size-1;i++)
			arr[i]=arr[i+1];
		arr[--size]=-1;
		cout<<"element at first is deleted\n";	//success
	}
	else
		cout<<"element can't be deleted\n";	//list is empty
}

void List_ADT::deleteAtLast()
{
	if(!isEmpty())	//if list is empty
	{
		arr[size--]=-1;
		cout<<"element at last is deleted\n";	//success
	}
	else
		cout<<"element can't be deleted\n";	//list is empty
}

void List_ADT::deleteByPos(int pos)
{
	if(!isEmpty() && pos>0 && pos<=size)	//if list is not empty
	{
		if(pos==1)
			deleteAtFirst();
		else if (pos==size-1)
			deleteAtLast();
		else
		{
			for(int i=pos-1;i<size-1;i++)
				arr[i]=arr[i+1];
			arr[size-1]=-1;
		}
		cout<<"element is deleted at the position\n";	//success
	}
	else
		cout<<"element can't be deleted\n";	//list is empty or invalid position
}

void List_ADT::makeListEmpty()	//to empty the list
{
	while(arr[0]!=-1)
		deleteAtFirst();
	cout<<"List has no elements\n";
}

//application

int main()
{
	List_ADT list;
	int ch=0;
	while(ch!=-1)
	{
		cout<<"\nChoose an option\n";
		cout<<"1-to check if list is full\n";
		cout<<"2-to check if list is empty\n";
		cout<<"3-to insert element at first\n";
		cout<<"4-to insert element at last\n";
		cout<<"5-to insert element at a position\n";
		cout<<"6-to delete element at first\n";
		cout<<"7-to delete element at last\n";
		cout<<"8-to delete element at a position\n";
		cout<<"9-to display the list\n";
		cout<<"10-to delete all elements of the list\n";
		cout<<"-1 - to exit\n\n";
		cin>>ch;
		cout<<"\n";
		if(ch==1)
		{
			if(list.isFull())
				cout<<"list is full\n";
			else
				cout<<"list is not full\n";
		}
		else if (ch==2)
		{
			if(list.isEmpty())
				cout<<"list is empty\n";
			else
				cout<<"list is not empty\n";
		}
		else if(ch==3)
		{
			int ele;
			cout<<"enter the element\n";
			cin>>ele;
			list.insertAtFirst(ele);
		}
		else if(ch==4)
		{
			int ele;
			cout<<"enter the element\n";
			cin>>ele;
			list.insertAtLast(ele);
		}
		else if(ch==5)
		{
			int ele,pos;
			cout<<"enter the element\n";
			cin>>ele;
			cout<<"enter the position\n";
			cin>>pos;
			list.insertByPos(pos,ele);
		}
		else if(ch==6)
			list.deleteAtFirst();
		else if(ch==7)
			list.deleteAtLast();
		else if(ch==8)
		{
			int pos;
			cout<<"enter the position\n";
			cin>>pos;
			list.deleteByPos(pos);
		}
		else if(ch==9)
			list.displayList();
		else if(ch==10)
		{
			list.makeListEmpty();
		}
	}
}