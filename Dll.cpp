#include<iostream>
using namespace std;

struct node
{
	node* prev;
	int data;
	node* next;
} *first = NULL;

void create( int a[], int size)
{
	node *last = NULL;
	node *temp = NULL;
	
	first  = new node;
	first->data = a[0];
	first->next,first->prev = NULL;
	last = first;
	for(int i  = 1; i<size; i++)
	{
		temp  = new node;
		temp->prev = last;
		temp->data = a[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

int count(node *p)
{
	int count = 0;
	while(p != NULL)
	{
		count++;
		p = p->next;
	}
	
	return count;
}

void insert(node* p, int a, int pos)
{
	node* temp = new node;
	temp->data = a;
	if(pos<0||pos>count(p)){return;}
	
	if(pos == 0)
	{
		temp->prev = NULL;
		temp->next = first;
		first->prev = temp;
		first = temp;
	}
	
	else
	{
		for(int i = 0; i<pos-1; i++)
		{
			p = p->next;
		}
		
		if(p->next != NULL)
		{
			(p->next)->prev = temp;
			temp->next = p->next;
			p->next = temp;
			temp->prev = p;
		}
		
		else
		{
			p->next = temp;
			temp->prev = p;
		}
	}
}

int Delete(node* p, int index)
{
	int x;
	if(index<0||index>count(p)){return -1;}
	if(index == 1)
	{
		x = p->data;
		first = first->next;
		first->prev = NULL;
		delete p;
		return x;
	}
	
	else
	{
		for(int i = 0; i<index-1; i++)
		{
			p = p->next;
		}
		
		p->prev->next = p->next;
		if(p->next != NULL)
		{
			p->next->prev = p->prev;
		}
		 
		x = p->data;
		delete p;
		
	}
}

void reverse(node*p)
{
	while(p->next != NULL)
	{
		p = p->next;
	}
	
	while(p != NULL)
	{
		cout<<p->data<<"<=>";
		p = p->prev;
	}
}

void display(node *p)
{
	while(p != NULL)
	{
		cout<<p->data<<"<=>";
		p = p->next;
	}
	cout<<endl;
}


int main()
{
	int a[5] = {10,20,30,40,50};
	create(a,5);
	display(first);
	cout<<"No of Elements: "<<count(first)<<endl;
	insert(first, 100, 5);
	display(first);
	reverse(first);
}
