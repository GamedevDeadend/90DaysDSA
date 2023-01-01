#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
}*first  = nullptr, *second = nullptr;

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
void create2(int b[], int size)
{
    node* temp,* last;
    second = new node;           //Creating first node
    second->data = b[0];         //Set array element as data
    second->next = nullptr;      //Setting pointer to NULL
    last = second;               //Setting first as last
                  
    for(int i=1; i<size; i++)
    {
        temp  = new node;       //Creating temporary Node
        temp->data = b[i];      //Set array element as data for new node
        temp->next = nullptr;   //Set next pointer as null
        last->next = temp;      //Linking last pointer with temp
        last = temp;            // making temp pointer as last
    }

}

node* merge(node* p, node* q)
{
    node* last = nullptr;           //last pointer will change links while traversing through p & q based on conditions.Merged pointer will act as beginning pointer for last pointer
    if(p->data < q->data)
    {
        last = p;
        p = p->next;
        last->next = nullptr;
    }                               //Setting last Pointer for first time. 
    else
    {
        last = q;
        q = q->next;
        last->next = nullptr;
    }

    node* merged = last;			// merged is acting as first pointer for new merged list
    while (p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            p = p->next;
            last = last->next;
            last->next = nullptr;
        }                           
        else
        {
            last->next = q;
            q = q->next;
            last = last->next;
            last->next = nullptr;
        }
    }

    last->next = (p)?p:q; // Condition For situation when p and q don't have equal no. of elements
    return merged;
}


void display(node* p)
{
    while(p)
    {
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<endl;
}

int main() 
{
 int a[5] = {15,25,35,45,55};
 int b[5] = {10,26,30,40,50};
create(a,5);
create2(b,5);
node* merged = merge(first,second);
display(merged);
}
