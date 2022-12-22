#include<iostream>

using namespace std;																			//LIFO

struct node
{
	int data;
	node* next;
}*top = NULL;

void push(int x)
{
	node* temp = new node;
	if(temp == NULL)
	{
		cout<<"Stack is full";																//OverFlow Memory is full
	}
    	temp->data = x;
    	temp->next = top;
    	top  = temp;
}

int pop()
{
	int x;
	node *temp;
	if(top == NULL)
	{
		cout<<"Stack Underflow"<<endl;
		return -1;
	}
	
	else
	{
		temp = top;
		x = top->data;
		top = top->next;
		delete temp;
		return x;
	}
}

void display(node* p)
{
	while( p!= NULL)
	{
		cout<<p->data<<"->";
		p = p->next;
	}
}

int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	pop();
	display(top);
}
