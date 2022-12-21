#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
}*first = nullptr,*Second = nullptr,*Merged = nullptr;

void create(int a[], int size)
{
    node* temp,* last;
    first = new node;           //Creating first node
    first->data = a[0];         //Set array element as data
    first->next = nullptr;      //Setting pointer to NULL
    last = first;               //Setting first as last
                  
    for(int i=1; i<size; i++)
    {
        temp  = new node;       //Creating temporary Node
        temp->data = a[i];      //Set array element as data for new node
        temp->next = nullptr;   //Set next pointer as null
        last->next = temp;      //Linking last pointer with temp
        last = temp;            // making temp pointer as last
    }

}

int count(node* p); // function Prototype

void display(node* p)
{
    while(p)
    {
        cout<<p->data<<"->";
        p = p->next;
    }

    cout<<endl;
}

void Insert(node* p, int element, int pos)
{
    node* temp = new node;
    temp->data = element;
    if(pos < 0 || pos > count(p))                                      // Total pos  = no. of elements + 1 In this case total elemnts  = 5; pos total 6 = {0 to 5};
        return;

    if(pos == 0)
    {
        temp->next = first;                                                // Insert At beginning code
        first = temp;
    }

    else
    {
        for(int i  = 0 ; i < pos - 1 ; i++)
            p = p->next;
            
        temp->next = p->next;
        p->next = temp;
    }
}

int count(node* p)
{
    int count{0};

    while (p != NULL)
    {
        p = p->next;    // traverse to the next pointer
        count++;
    }
    return count;
}

int delete1( node* p,int index)
{
	node* q; int x=-1;
	if(index <0 || index>count(p)-1)
	        return -1;
	if(index==0)
	{
	x=p->data;
	first = first->next;
	delete p;
	return x;
    }
    else
    {
    	for(int i=0;i<index-1;i++)
    	{
    		q=p;
    		p=p->next;
		}
		q->next=p->next;
		x=p->data;
		delete p;
		return x;
	}
}

void Creverse(node*p)
{
	cout<<"REVERSE"<<endl;
	node* q = NULL;                     //Taking q as previous pointer for first(current)
	while(p)
	{
        // cout<<"Hello";
        node* temp = p->next;           // Temp Will take p->next reference work as next pointer
		p->next = q;                    // q = prev
		q = p;                          // p = curr
        p = temp;                       // temp = next
	}
    first = q;
}

node *CreverseRecurrsion(node* p)
{   
    if(p->next == nullptr)
    {
        return p;
    }

    node *reversedHead = CreverseRecurrsion(p->next);                   // Reversing A Linked List using recurison
    node* temp;
    temp = p->next;
    temp->next = p;
    p->next = nullptr;
    return reversedHead;
}

string IsSorted(node* p)                //Is Sorted Code
{
    int x  = -67735;
    while(p)
    {
        if( p->data < x)
        {
            return "true";
        }
        x = p->data;
        p = p->next;
    }
    return "false";
}

void Merge(node *p , node *q)
{
    node* temp;
   if(p->data < q->data)
   {
    Merged = temp = p;
    p = p->next;
    temp->next = NULL;
   }

   else
   {
    Merged = temp = q;
    q = q ->next;
    temp->next = NULL;
   }

   while (p&&q)
   {
    if(p->data < q->data)
    {
        temp->next = p;
        temp = p;
        p = p->next;
        temp->next = NULL;
    }

    else
    {
      temp ->next = q;
      temp = q;
      q = q ->next;
      temp ->next = NULL;
    }
   }

   if(p)
   {
    temp->next = p;
   }
   else
   {
    temp->next = q;
   }
   
}

int main()
{
    int a[5] = {1,2,3,4,5};
    create(a,5);
    display(first);
    Creverse(first);
    display(first);
    Insert(first, 75 ,5);
    cout<<endl;
    display(first);
    delete1(first, 4);
    display(first);
    // IsSorted(first);
    cout<<IsSorted(first)<<endl;
    first = CreverseRecurrsion(first);
    display(first);

}