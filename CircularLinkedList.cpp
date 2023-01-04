#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	
}*first = NULL;

void traverse(node*);

void create(int a[], int n)
{
	node *last, *temp;
	first  = new node;
	first->data = a[0];
	first->next = first;
	last  =  first;
	for(int i =1; i<n; i++)
	{
		temp = new node;
		temp->data = a[i];
		temp->next = first;
		last->next = temp;
		last = temp; 
	}
}

void display(node* p)
{
	do
	{
		cout<<p->data<<"->";
		p = p->next;
	}while(p != first);
}

int count(node* p)
{
	int count = 0;
	do
	{
		count++;
		p = p->next;
	}
	while(p!=first);
	return count;
}

int sum(node* p)
{
	int sum = 0;
	do
	{
		sum += p->data;
		p = p->next;
	}
	while(p!=first);
	return sum;
}

void insert(node* p, int pos, int data)
{
	if(pos<0 || pos>count(p)){return;}
	node* ToInsert = new node;
	ToInsert->data = data;
	
	if(pos == 0)
	{
		if(first == NULL)
		{
			ToInsert->next = ToInsert;
			first = ToInsert;
		}
		
		else
		{
			while(p->next != first)
			{
				p=p->next;
			}
			p->next = ToInsert;	
			ToInsert->next = first;
			first = ToInsert;
		}	
	}
	
	else
	{
		for(int i = 0; i<pos-1;i++)
		{
			p=p->next;
		}
	
		ToInsert->next = p->next;
		p->next = ToInsert;
	}
}

int Delete(node* p, int pos)
{
	node* q = p;
	int x = -1;

	if(pos<1 || pos>count(p))
	{
		cout<<"Error out of BOUNDS"<<endl;
		return x;}
	
	if(pos == 1)
	{
		q = p;
		while(q->next != first)
		{
			q = q->next;
		}
		q->next = p->next;
		x = p->data;
		first = first->next;
		delete p;
		return x;
	}
	
	else
	{
		q = p;
		for(int i = 0; i< pos-1; i++)
		{
			q=p;
			p = p->next;
		}
		
		q->next = p->next;
		x = p->data;
		delete p;
		return x;
	}
}
void traverse(node* p)
{	do{p = p->next;}
	while(p != first);
}

int main()
{
	int a[5]= {10,20,30,40,50};
	create(a,5);
	display(first);
	cout<<endl<<"After Insert"<<endl;
	insert(first, 0, 8);
	display(first);
	cout<<"\nTotal Elements in Circular linked list are: "<<count(first)<<endl;
	cout<<"Sum of Elements in Circular linked list are "<<sum(first)<<endl;
	Delete(first, 6);
	display(first);
}
